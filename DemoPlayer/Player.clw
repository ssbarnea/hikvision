; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CSetKeyDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "player.h"
LastPage=0

ClassCount=9
Class1=CPlayerApp
Class2=CAboutDlg
Class3=CPlayerDlg

ResourceCount=15
Resource1=IDR_MAINFRAME (English (U.S.))
Resource2=IDD_CUT
Resource3=IDD_APP_HELP (English (U.S.))
Class4=CInfo
Resource4=IDD_EXTRACT (English (U.S.))
Class5=CSeek
Resource5=IDD_VIDEOCTRL (English (U.S.))
Resource6=IDD_PLAYER_DIALOG (English (U.S.))
Class6=CCutFile
Resource7=IDD_ABOUTBOX (English (U.S.))
Class7=CDisplayRect
Resource8=IDD_SHARPEN_LEVEL (English (U.S.))
Resource9=IDD_INFO (English (U.S.))
Resource10=IDD_SET_KEY
Resource11=IDD_CUTFILE (English (U.S.))
Resource12=IDD_ABOUTBOX (English (U.S.) - _FOR_HIKPLAYM4_DLL_)
Resource13=IDD_WATERMARK
Class8=CWatermarkDlg
Resource14=IDD_RANGE (English (U.S.))
Class9=CSetKeyDlg
Resource15=IDD_SEEK (English (U.S.))

[CLS:CPlayerApp]
Type=0
BaseClass=CWinApp
HeaderFile=Player.h
ImplementationFile=Player.cpp
LastObject=CPlayerApp

[CLS:CAboutDlg]
Type=0
BaseClass=CDialog
HeaderFile=PlayerDlg.cpp
ImplementationFile=PlayerDlg.cpp
LastObject=CAboutDlg

[CLS:CPlayerDlg]
Type=0
BaseClass=CDialog
HeaderFile=PlayerDlg.h
ImplementationFile=PlayerDlg.cpp
Filter=D
VirtualFilter=dWC
LastObject=CPlayerDlg

[CLS:CInfo]
Type=0
HeaderFile=Info.h
ImplementationFile=Info.cpp
BaseClass=CDialog
Filter=D
LastObject=CInfo
VirtualFilter=dWC

[CLS:CSeek]
Type=0
HeaderFile=Seek.h
ImplementationFile=Seek.cpp
BaseClass=CDialog
Filter=D
LastObject=CSeek
VirtualFilter=dWC

[DLG:IDD_CUT]
Type=1
Class=?
ControlCount=1
Control1=IDOK,button,1342242817

[CLS:CCutFile]
Type=0
HeaderFile=CutFile.h
ImplementationFile=CutFile.cpp
BaseClass=CDialog
Filter=D
LastObject=CCutFile
VirtualFilter=dWC

[CLS:CDisplayRect]
Type=0
HeaderFile=DisplayRect.h
ImplementationFile=DisplayRect.cpp
BaseClass=CDialog
Filter=D
VirtualFilter=dWC
LastObject=CDisplayRect

[DLG:IDD_ABOUTBOX (English (U.S.))]
Type=1
Class=CAboutDlg
ControlCount=3
Control1=IDC_STATIC,static,1342177283
Control2=IDC_VER,static,1342308480
Control3=IDOK,button,1342373889

[DLG:IDD_INFO (English (U.S.))]
Type=1
Class=CInfo
ControlCount=3
Control1=IDOK,button,1342242816
Control2=IDC_REFRESH,button,1342242816
Control3=IDC_LIST_INFO,SysListView32,1350631937

[DLG:IDD_RANGE (English (U.S.))]
Type=1
Class=CDisplayRect
ControlCount=9
Control1=IDC_DISWND,static,1342308366
Control2=IDC_DISPLAY,button,1342275584
Control3=IDOK,button,1342275584
Control4=IDC_SLIDER1,msctls_trackbar32,1342242840
Control5=IDC_STATIC_SIZE,static,1342308352
Control6=IDC_EDIT_SIZE,edit,1342242960
Control7=IDC_STATIC_PST,static,1342308352
Control8=IDC_STATIC_PLUS,static,1342177294
Control9=IDC_STATIC_MINUS,static,1342177294

[DLG:IDD_CUTFILE (English (U.S.))]
Type=1
Class=CCutFile
ControlCount=16
Control1=IDOK,button,1342242816
Control2=IDC_SAVE,button,1342242816
Control3=IDC_VIEW,button,1342242816
Control4=IDC_STATIC,button,1342177287
Control5=IDC_BYFRAME,button,1342308361
Control6=IDC_BYTIME,button,1342177289
Control7=IDC_STATIC,button,1342177287
Control8=IDC_RANGE,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_BEGIN,edit,1350631552
Control11=IDC_REAL_BEGIN,edit,1350633600
Control12=IDC_STATIC,static,1342308352
Control13=IDC_END,edit,1350631552
Control14=IDC_REAL_END,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_FILENAME,edit,1350631552

[DLG:IDD_SEEK (English (U.S.))]
Type=1
Class=CSeek
ControlCount=9
Control1=IDOK,button,1342242816
Control2=IDC_SEEK,button,1342242816
Control3=IDC_STATIC,button,1342177287
Control4=IDC_BYFRAME,button,1342308361
Control5=IDC_BYTIME,button,1342177289
Control6=IDC_STATIC,button,1342177287
Control7=IDC_RANGE,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_VALUE,edit,1350631552

[MNU:IDR_MAINFRAME (English (U.S.))]
Type=1
Class=CPlayerDlg
Command1=IDM_FILE_OPEN
Command2=IDM_FILE_CLOSE
Command3=IDM_SET_KEY
Command4=IDM_APP_EXIT
Command5=IDM_VIEW_FULLSCREEN
Command6=IDM_VIEW_ZOOM_50
Command7=IDM_VIEW_ZOOM_100
Command8=IDM_VIEW_ZOOM_200
Command9=IDM_INFO
Command10=IDM_WATERMARK
Command11=IDM_SETDISPLAY
Command12=IDM_PLAY_PAUSE
Command13=IDM_STOP
Command14=IDM_STEPFORWARD
Command15=IDM_STEPBACKWARD
Command16=IDM_GOTOSTART
Command17=IDM_GOTOEND
Command18=IDM_SEEK
Command19=IDM_VIDEO_CONTROL
Command20=IDM_REPEAT
Command21=IDM_STREAM_TYPE
Command22=IDM_DEFLASH
Command23=IDM_QUALITY
Command24=IDM_PREVIEW50
Command25=IDM_SHARPEN_NONE
Command26=IDM_SHARPEN_LEVEL1
Command27=IDM_SHARPEN_LEVEL2
Command28=IDM_SHARPEN_LEVEL3
Command29=IDM_SHARPEN_LEVEL4
Command30=IDM_SHARPEN_LEVEL5
Command31=IDM_SHARPEN_LEVEL6
Command32=IDM_THROW0
Command33=IDM_THROW1
Command34=IDM_THROW2
Command35=IDM_DECODE_NORMAL
Command36=IDM_DECODE_I
Command37=IDM_DECODE_NONE
Command38=IDM_DISNORMAL
Command39=IDM_DISQUARTER
Command40=IDM_TIMER1
Command41=IDM_TIMER2
Command42=IDM_RESET_BUF
Command43=IDM_CAP_BMP
Command44=IDM_CAP_JPEG
Command45=IDM_CAPPIC_PATH
Command46=IDM_APP_HELP
Command47=IDM_APP_ABOUT
CommandCount=47

[DLG:IDD_PLAYER_DIALOG (English (U.S.))]
Type=1
Class=CPlayerDlg
ControlCount=18
Control1=IDC_SHOW,static,1342177294
Control2=IDC_PLAY,button,1342242819
Control3=IDC_PAUSE,button,1342242819
Control4=IDC_STOP,button,1342242819
Control5=IDC_INTER1,static,1342177297
Control6=IDC_GOTOSTART,button,1342181184
Control7=IDC_SLOW,button,1342181184
Control8=IDC_FAST,button,1342181184
Control9=IDC_GOTOEND,button,1342181184
Control10=IDC_INTER2,static,1342177297
Control11=IDC_STEPBACK,button,1342246720
Control12=IDC_STEP,button,1342246720
Control13=IDC_INTER3,static,1342177297
Control14=IDC_CAPPIC,button,1342246720
Control15=IDC_SOUND,button,1342246720
Control16=IDC_SOUND_SLIDER,msctls_trackbar32,1342177304
Control17=IDC_PLAYSTATETEXT,static,1342308866
Control18=IDC_PLAY_RECT_SLIDER,static,1350696960

[DLG:IDD_EXTRACT (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDOK,button,1342242816
Control2=IDC_SOURCEFILE,edit,1350631552
Control3=IDC_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_DESTFILE,edit,1350631552
Control6=IDC_SOURCEBRO,button,1342242816
Control7=IDC_DESTBRO,button,1342242816
Control8=IDC_EXTRACT,button,1342242816
Control9=IDC_EXTRACT_PROGRESS,msctls_progress32,1350565888

[DLG:IDD_SHARPEN_LEVEL (English (U.S.))]
Type=1
Class=?
ControlCount=4
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_STATIC,static,1342308352
Control4=IDC_EDIT_SHARPEN_LEVEL,edit,1350631553

[DLG:IDD_APP_HELP (English (U.S.))]
Type=1
Class=?
ControlCount=16
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,button,1342177287
Control3=IDC_STATIC,button,1342177287
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_STATIC,static,1342308352
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_STATIC,static,1342308352
Control13=IDC_STATIC,static,1342308352
Control14=IDC_STATIC,static,1342308352
Control15=IDC_STATIC,static,1342308352
Control16=IDC_STATIC,static,1342308352

[DLG:IDD_VIDEOCTRL (English (U.S.))]
Type=1
Class=?
ControlCount=9
Control1=IDC_VC_BRIGHTNESS,button,1342181184
Control2=IDC_VC_CONTRAST,button,1342181184
Control3=IDC_VC_SATURATION,button,1342181184
Control4=IDC_VC_HUE,button,1342181184
Control5=IDC_SLIDER_BRIGHTNESS,msctls_trackbar32,1342242855
Control6=IDC_SLIDER_CONTRAST,msctls_trackbar32,1342242855
Control7=IDC_SLIDER_SATURATION,msctls_trackbar32,1342242855
Control8=IDC_SLIDER_HUE,msctls_trackbar32,1342242855
Control9=IDC_VC_RESET,button,1342275584

[DLG:IDD_ABOUTBOX (English (U.S.) - _FOR_HIKPLAYM4_DLL_)]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_VER,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_WATERMARK]
Type=1
Class=CWatermarkDlg
ControlCount=12
Control1=IDC_STATIC,static,1342308352
Control2=IDC_STATIC,static,1342308352
Control3=ID_STATIC,static,1342308352
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_STATIC,static,1342308352
Control7=IDC_MAC,static,1342308352
Control8=IDC_DEVICESN,static,1342308352
Control9=IDC_CHAN,static,1342308352
Control10=IDC_GLOBALTIME,static,1342308352
Control11=IDC_DEVICEINFO,static,1342308352
Control12=IDC_DEVICETYPE,static,1342308352

[CLS:CWatermarkDlg]
Type=0
HeaderFile=WatermarkDlg.h
ImplementationFile=WatermarkDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CWatermarkDlg

[CLS:CSetKeyDlg]
Type=0
HeaderFile=SetKeyDlg.h
ImplementationFile=SetKeyDlg.cpp
BaseClass=CDialog
Filter=D
LastObject=CSetKeyDlg
VirtualFilter=dWC

[DLG:IDD_SET_KEY]
Type=1
Class=CSetKeyDlg
ControlCount=11
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_CB_FORMAT,combobox,1344340226
Control4=IDC_STATIC,static,1342308352
Control5=IDC_STATIC,static,1342308352
Control6=IDC_CB_LENGTH,combobox,1344340226
Control7=IDC_STATIC,static,1342308352
Control8=IDC_RAD_ASCII,button,1342177289
Control9=IDC_RAD_HEX,button,1342177289
Control10=IDC_STATIC,static,1342308352
Control11=IDC_EDT_KEY,edit,1350631584

