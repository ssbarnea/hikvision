
#include "StdAfx.h"
#include "CConvertAVI.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CConvertAVI::CConvertAVI()
{
	m_pOutAVI    = NULL;
	m_pIndexes   = NULL;
	m_dwMaxFrames = 0;
	ZeroMemory(&m_strAVIPara, sizeof(AVI_CONVERT_PARA));
}

CConvertAVI::~CConvertAVI()
{
}

BOOL CConvertAVI::InitResource(AVI_CONVERT_PARA* pParam, CString strAVIPath)
{
	m_dwCurFrameNum	    = 0;
	m_dwFirstFrameOffset = 0;
	m_bWriteHdr			= TRUE;

	CopyMemory(&m_strAVIPara, pParam, sizeof(AVI_CONVERT_PARA));
	
	m_dwMaxFrames = MAX_FILE_LEN/m_strAVIPara.dwTotalFrames;

#ifdef WRITE_INDEX
	m_pIndexes = new AVIINDEXENTRY[m_dwMaxFrames];
	if(NULL == m_pIndexes)
	{
		return FALSE;
	}
	ZeroMemory(m_pIndexes,  m_dwMaxFrames * sizeof(AVIINDEXENTRY));
	m_nMoviOffset = 0;
#endif 

	m_pOutAVI = riffCreate( LPCTSTR(strAVIPath) );
	if ( m_pOutAVI == NULL )
	{
		ReleaseResource();
		return FALSE;
	}

	return TRUE;
}

void CConvertAVI::ReleaseResource()
{
	if(m_pOutAVI != NULL)
	{
		TRACE("Close wriff files.\n");
		CloseWriffFiles();
		m_pOutAVI = NULL;
	}

#ifdef WRITE_INDEX
	if(m_pIndexes != NULL)
	{
		TRACE("Delete m_pIndexes.\n");
		delete [] m_pIndexes;
		m_pIndexes = NULL;
	}
#endif

	ZeroMemory(&m_strAVIPara, sizeof(AVI_CONVERT_PARA));
}

BOOL CConvertAVI::IsWriteAVIHdr()
{
	return m_bWriteHdr;
}

BOOL CConvertAVI::WriteHeaders()
{
	MainAVIHeader		 mainAviHeader;
	AVIStreamHeader		 aviStreamHeader;
	BITMAPINFOHEADER	 bitmapHeader;
	DWORD fcc;
	riffAddList( m_pOutAVI, "RIFF", "AVI " );
	//
	// Write hdr1 list
	//
	riffAddList( m_pOutAVI, "LIST", "hdrl" );
	mainAviHeader.dwMicroSecPerFrame		= 1000000 / (m_strAVIPara.dwFPS);
	mainAviHeader.dwMaxBytesPerSec			= m_strAVIPara.dwFrameSize + PADDING_GRANULARITY;	// Spare
	mainAviHeader.dwPaddingGranularity		= 0;
	mainAviHeader.dwFlags					= AVIF_HASINDEX;
	mainAviHeader.dwTotalFrames				= m_strAVIPara.dwTotalFrames;
	mainAviHeader.dwInitialFrames			= 0;
	mainAviHeader.dwStreams					= 1;
	mainAviHeader.dwSuggestedBufferSize		= m_strAVIPara.dwFrameSize + PADDING_GRANULARITY;	// Spare
	mainAviHeader.dwWidth					= m_strAVIPara.dwFrameWidth;
	mainAviHeader.dwHeight					= m_strAVIPara.dwFrameHeight;
	mainAviHeader.dwReserved[0]				= 0;
	mainAviHeader.dwReserved[1]				= 0;
	mainAviHeader.dwReserved[2]				= 0;
	mainAviHeader.dwReserved[3]				= 0; 

	riffAddChunk  ( m_pOutAVI, "avih" );
	riffWriteData ( m_pOutAVI, &mainAviHeader, sizeof( mainAviHeader ) );
	riffCloseChunk( m_pOutAVI );
	//
	// Write the "strl" video list
	//
	riffAddList( m_pOutAVI, "LIST", "strl" );
	//
	// Write the "strh" chunk	
	//
	fcc = mmioFOURCC( 'Y', 'V', '1', '2' );
	aviStreamHeader.fccType					= mmioFOURCC( 'v', 'i', 'd', 's' );
	aviStreamHeader.fccHandler				= 0;
	aviStreamHeader.dwFlags					= fcc;
	aviStreamHeader.wPriority				= 0;
	aviStreamHeader.wLanguage				= 0;
	aviStreamHeader.dwInitialFrames			= 0;
	aviStreamHeader.dwScale					= 1;
	aviStreamHeader.dwRate					= m_strAVIPara.dwFPS;
	aviStreamHeader.dwStart					= 0;
	aviStreamHeader.dwLength				= m_strAVIPara.dwTotalFrames;
	aviStreamHeader.dwSuggestedBufferSize	= m_strAVIPara.dwFrameSize + PADDING_GRANULARITY;
	aviStreamHeader.dwQuality				= 0xFFFFFFFF;				// -1
	aviStreamHeader.dwSampleSize			= 0;
	aviStreamHeader.dwTop					= 0;
	aviStreamHeader.dwLeft					= 0;
	aviStreamHeader.dwRight					= 0;
	aviStreamHeader.dwBottom				= 0;


	riffAddChunk  ( m_pOutAVI, "strh" );
	riffWriteData ( m_pOutAVI, &aviStreamHeader, sizeof( aviStreamHeader ) );
	riffCloseChunk( m_pOutAVI );
	//
	//
	// Write the "strf" chunk
	//
	bitmapHeader.biSize				= sizeof( bitmapHeader );
	bitmapHeader.biWidth			= m_strAVIPara.dwFrameWidth;
	bitmapHeader.biHeight			= m_strAVIPara.dwFrameHeight;
	bitmapHeader.biPlanes			= 1;
	bitmapHeader.biBitCount			= 12;
	bitmapHeader.biCompression		= fcc;
	bitmapHeader.biSizeImage		= m_strAVIPara.dwFrameSize;
    bitmapHeader.biXPelsPerMeter	= 0;
    bitmapHeader.biYPelsPerMeter	= 0;
	bitmapHeader.biClrUsed			= 0;
	bitmapHeader.biClrImportant		= 0;
    
	riffAddChunk  ( m_pOutAVI, "strf" );
	riffWriteData ( m_pOutAVI, &bitmapHeader, sizeof( bitmapHeader ) );
	riffCloseChunk( m_pOutAVI );      

	//
	// Close the strl list
	//
	riffCloseList( m_pOutAVI );

	//
	// Close the hdrl list
	//
	riffCloseList( m_pOutAVI );
	//
	// Write JUNK chunk
	//
	riffPadJunk( m_pOutAVI, PADDING_GRANULARITY, 0 );
	//
	// Write the "movi" list
	//
	riffAddList( m_pOutAVI, "LIST", "movi" );
	m_dwFirstFrameOffset = riffSize( m_pOutAVI );

#ifdef WRITE_INDEX
	m_nMoviOffset = m_dwFirstFrameOffset - 4;
#endif

	//
	// Return
	//

	m_bWriteHdr = FALSE;
	return TRUE;
}


DWORD CConvertAVI::GetCurFrameNum()
{
	return m_dwCurFrameNum;
}


BOOL CConvertAVI::AddFileToAVI(char* pBuf, DWORD /*nSize*/)
{

#ifdef WRITE_REC_LIST
	//
	// Write "rec " list
	//
	#ifdef WRITE_INDEX

	riffPadWord( m_pOutAVI );

	#endif // WRITE_INDEX

	riffAddList( m_pOutAVI, "LIST", "rec" );

#endif // WRITE_REC_LIST

	//
	// Write the "00dc" chunk
	//
#ifdef WRITE_INDEX

	riffPadWord( m_pOutAVI );

	m_pIndexes[m_dwCurFrameNum].ckid				= mmioFOURCC( '0', '0', 'd', 'c' );
	m_pIndexes[m_dwCurFrameNum].dwFlags			= AVIIF_KEYFRAME;
	m_pIndexes[m_dwCurFrameNum].dwChunkOffset	= riffSize( m_pOutAVI ) - m_nMoviOffset;
	m_pIndexes[m_dwCurFrameNum].dwChunkLength	= m_strAVIPara.dwFrameSize;
 
#endif // WRITE_INDEX

	//
	// Write the chunk
	//
	riffAddChunk  ( m_pOutAVI, "00dc" );
    riffWriteData ( m_pOutAVI, pBuf, m_strAVIPara.dwFrameSize );	
	riffCloseChunk( m_pOutAVI );

#ifdef WRITE_REC_LIST

	//
	// Close the "rec " list
	//
	riffCloseList( m_pOutAVI );

#endif // WRITE_REC_LIST

	//
	// Write JUNK chunk to align video frames
	//
#ifdef ALIGN_VIDEO_FRAMES

	riffPadJunk( m_pOutAVI, PADDING_GRANULARITY, m_dwFirstFrameOffset );

#endif // ALIGN_VIDEO_FRAMES

	m_dwCurFrameNum ++;
	
	return TRUE;
}


BOOL CConvertAVI::CloseWriffFiles()
{
	//
	// Close the "movi" list
	//
	riffCloseList( m_pOutAVI );
    
	//
	// Write the "idx1" chunk
	//
#ifdef WRITE_INDEX

	riffPadWord   ( m_pOutAVI );
	riffAddChunk  ( m_pOutAVI, "idx1" );
	riffWriteData ( m_pOutAVI, m_pIndexes, m_dwCurFrameNum*sizeof( AVIINDEXENTRY) );
	riffCloseChunk( m_pOutAVI );

#endif // WRITE_INDEX

	//
	// Close the "RIFF" LIST
	//
	riffCloseList( m_pOutAVI );
    
	//
	// Close the riff file
	//
	riffClose( m_pOutAVI );


	return TRUE;
}

void CConvertAVI::SetFPS(DWORD nFps)
{
	m_strAVIPara.dwFPS = nFps;
}

BOOL CConvertAVI::IsExceedMaxFileLen()
{
	return ( (m_dwCurFrameNum >= m_dwMaxFrames) ? TRUE : FALSE);
}