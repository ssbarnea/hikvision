#ifndef _AVIFMT_H_
#define _AVIFMT_H_

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

#ifndef DWORD
#define DWORD unsigned long
#endif

#ifndef WORD
#define WORD unsigned short
#endif

#ifndef FOURCC
#define FOURCC unsigned long
#endif

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

//
// Flags for "avih" chunk
//
#define AVIF_HASINDEX		0x00000010	// Index at end of file
#define AVIF_MUSTUSEINDEX	0x00000020
#define AVIF_ISINTERLEAVED	0x00000100
#define AVIF_TRUSTCKTYPE	0x00000800	// Use CKType to find key frames
#define AVIF_WASCAPTUREFILE	0x00010000
#define AVIF_COPYRIGHTED	0x00020000

//
// Flags for "strh" chunk
//
#define AVISF_DISABLED				0x00000001
#define AVISF_VIDEO_PALCHANGES		0x00010000

//
// Flags for "idx1" chunk
//
#define AVIIF_LIST          0x00000001L // chunk is a 'LIST'
#define AVIIF_KEYFRAME      0x00000010L // this frame is a key frame.
#define AVIIF_NOTIME	    0x00000100L // this frame doesn't take any time
#define AVIIF_COMPUSE       0x0FFF0000L // these bits are for compressor use

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////

typedef struct
{
    DWORD		dwMicroSecPerFrame;			// frame display rate (or 0L)
    DWORD		dwMaxBytesPerSec;			// max. transfer rate
    DWORD		dwPaddingGranularity;		// pad to multiples of this
                                            // size; normally 2K.
    DWORD		dwFlags;					// the ever-present flags
    DWORD		dwTotalFrames;				// # frames in file
    DWORD		dwInitialFrames;
    DWORD		dwStreams;
    DWORD		dwSuggestedBufferSize;

    DWORD		dwWidth;
    DWORD		dwHeight;

    DWORD		dwReserved[4];
} MainAVIHeader;

typedef struct {
    FOURCC		fccType;
    FOURCC		fccHandler;
    DWORD		dwFlags;					// Contains AVITF_* flags
    WORD		wPriority;
    WORD		wLanguage;
    DWORD		dwInitialFrames;
    DWORD		dwScale;	
    DWORD		dwRate;						// dwRate / dwScale == samples/second
    DWORD		dwStart;
    DWORD		dwLength;					// In units above...
    DWORD		dwSuggestedBufferSize;
    DWORD		dwQuality;
    DWORD		dwSampleSize;
	DWORD		dwTop;
	DWORD		dwLeft;
	DWORD		dwRight;
	DWORD		dwBottom;
} AVIStreamHeader;

typedef struct
{
    DWORD		ckid;
    DWORD		dwFlags;
    DWORD		dwChunkOffset;		// Position of chunk
    DWORD		dwChunkLength;		// Length of chunk
} AVIINDEXENTRY;

//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////


#endif _AVIFMT_H_