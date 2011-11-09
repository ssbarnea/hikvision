
#ifndef __CONVERT_TO_AVI__
#define __CONVERT_TO_AVI__

#include <mmsystem.h>
#include "AVIFMt.H"
#include "WRIFF.H"

#define WRITE_REC_LIST             // do write REC list?
#define WRITE_INDEX				   // do write index?
#define ALIGN_VIDEO_FRAMES	       // do align video frames?

#define MAX_FILE_LEN  2048000000   // the AVI file now can't exceed 2G

#define PADDING_GRANULARITY 2048   // padding size

typedef struct 
{
	DWORD				 dwFrameWidth;
	DWORD				 dwFrameHeight;
	DWORD				 dwFrameSize;
	DWORD				 dwFPS;
	DWORD				 dwTotalFrames; 
}AVI_CONVERT_PARA;


class CConvertAVI
{
public:
	CConvertAVI();
	virtual ~CConvertAVI();
	
public:
	
	DWORD                m_dwCurFrameNum;
	DWORD				 m_dwMaxFrames;
	BOOL				 m_bWriteHdr;
	riffFile			*m_pOutAVI;
	AVI_CONVERT_PARA     m_strAVIPara;
	
#ifdef WRITE_INDEX
	AVIINDEXENTRY*		 m_pIndexes;
	DWORD				 m_nMoviOffset;
#endif // WRITE_INDEX
	DWORD				 m_dwFirstFrameOffset;


public:
	BOOL WriteHeaders();
	BOOL AddFileToAVI(char* pBuf, DWORD nSize);
	BOOL CloseWriffFiles();

	BOOL InitResource(AVI_CONVERT_PARA* pParam, CString strAVIPath);
	void ReleaseResource();

	BOOL  IsWriteAVIHdr();
	BOOL  IsExceedMaxFileLen();
	DWORD GetCurFrameNum();
	void  SetFPS(DWORD nFps);
};

#endif