#ifndef _WATERMARKINFO_H_ 
#define _WATERMARKINFO_H_

/*************************************************************************/
/*  define  para begin
/*************************************************************************/

#define APP_VERSION			4.8				// player version


#define WIDTH				352				// Initialize width;
#define HEIGHT_PAL			288				// Initialize height;

#define PLAY_LIST_WIDTH		200				// PlayList Width;
#define PLAY_LIST_TOP		20				// PlayList Top;

#define MAX_DVD_NUM			16

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

//File locate reference call back function;
void CALLBACK FileRefDone(DWORD nReserved,DWORD nUser);
//capture call back function;
void CALLBACK DisplayCBFun(long nPort,char * pBuf,long nSize,long nWidth,long nHeight,long nStamp,long nType,long nReceaved);
//wave call back funtion
void CALLBACK WaveCBFun(long nPort, char * pAudioBuf, long nSize, long nStamp, long nType, long nUser);
//Decode call back funtion;
//void CALLBACK DecCBFun(long nPort,char * pBuf,long nSize,FRAME_INFO * pFrameInfo, long nReserved1,long nReserved2);
void CALLBACK SourceBufFun(long nPort,DWORD nBufSize,DWORD dwUser,void*pContext);
// From v3.6 verify water mask;
//void CALLBACK VerifyFun(long nPort, FRAME_POS * pFilePos, DWORD bIsVideo, DWORD nUser);

/*************************************************************************/
/*  callback function begin
/*************************************************************************/

// input stream thread
DWORD WINAPI InputStreamThread( LPVOID lpParameter);

typedef struct
{
	unsigned int	global_time;	/*当前的全局时间(绝对时间)，需要和GROUP_HEADER中的时间相同*/
	unsigned int	device_sn;		/*设备的序列号(整数表示，非BCD码)*/
	unsigned char	mac_addr[6];	/*码流所属设备的MAC地址*/
	unsigned char	device_type;	/*设备的类型(型号)*/
	unsigned char	device_info;	/*设备的附加信息(区域、语言、版本等)*/
	unsigned char	channel_num;	/*码流所属的通道号*/
	unsigned char	reserved[47];	/*填补，保证按64对齐*/
}WATERMARK_VER1_INFO;

#define GET_FILE_YEAR(time)		((time>>26)+2000)
#define GET_FILE_MONTH(time)	((time>>22)&15)
#define GET_FILE_DAY(time)		((time>>17)&31)
#define GET_FILE_HOUR(time)		((time>>12)&31)
#define GET_FILE_MINUTE(time)	((time>>6)&63)
#define GET_FILE_SECOND(time)	((time>>0)&63)

// 水印回调
void CALLBACK funCheckWatermark(long nPort,WATERMARK_INFO *pFrameType,DWORD nUser);


#endif // _WATERMARKINFO_H_