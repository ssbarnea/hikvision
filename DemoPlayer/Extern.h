#ifndef __EXTERN_DEFINE__
#define __EXTERN_DEFINE__


/************************************************************************/				
UINT	WM_FILE_END			= WM_USER +33;	 // User message. Be posted when the file is end.
UINT	WM_ENC_CHANGE		= WM_USER +100;  // User message. Be posted when the image size is changed.
UINT	PLAY_TIMER			= 1;			 // TIMER ID;
UINT	PORT				= 0;			 // uesed port;can be from 0 to 15;
/************************************************************************/


/*************************************************************************/
/*  define  para begin
/*************************************************************************/
//#define _FILE_POS							// if defined we will use the file pos to decide the slider position
//#define _WAVE_ADJ							// if defined will addjust the wave value, else will set the voluem of the sound card; 
//#define _HIGH_FRUID						// if defined will set high fruid by default in menu, else not set by default

#define APP_VERSION			4.8				// player version


#define WIDTH				352				// Initialize width;
#define HEIGHT_PAL			288				// Initialize height;

#define MAX_DISPLAY_DEVICE  4				// max support display device

//Define the controls size and position
#define PLAY_SLIDER_UP		10
#define PLAY_SLIDER_HEIGHT	10
#define BUTTON_UP			4
#define BUTTON_SIZE			20
#define STATE_UP			10
#define STATE_HEIGHT		20
#define PANNEL_HEIGHT		(STATE_HEIGHT+STATE_UP+BUTTON_SIZE+BUTTON_UP+PLAY_SLIDER_HEIGHT+PLAY_SLIDER_UP)
#define INTERVAL_SIZE		2
#define INTERVAL			5
#define LEFT_EDGE			5

#define SOUND_SLIDER_HEIGHT	25
#define SOUND_SLIDER_WIDTH  80
#define PLAYER_SLIDER_MAX	200

#define MOD16(x) ((x+15)&0xfffffff0)		// aligned by 16 bytes
/*************************************************************************/
/*  define  para over
/*************************************************************************/



/*************************************************************************/
/*  callback function begin
/*************************************************************************/	
//File locate reference call back function;
void CALLBACK FileRefDone(DWORD nReserved,DWORD nUser);
//capture call back function;
void CALLBACK DisplayCBFun(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,long nReceaved);
//wave call back funtion
void CALLBACK WaveCBFun(long nPort, char * pAudioBuf, long nSize, long nStamp, long nType, long nUser);
//Decode call back funtion;
void CALLBACK DecCBFun(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, long nReserved1,long nReserved2);
void CALLBACK SourceBufFun(long nPort,DWORD nBufSize,DWORD dwUser,void*pContext);
// From v3.6 verify water mask;
//void CALLBACK VerifyFun(long nPort, FRAME_POS * pFilePos, DWORD bIsVideo, DWORD nUser);

/*************************************************************************/
/*  callback function begin
/*************************************************************************/

// input stream thread
DWORD WINAPI InputStreamThread( LPVOID lpParameter);


#endif