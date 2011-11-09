# Microsoft Developer Studio Project File - Name="Player" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=Player - Win32 PlayM4 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Player.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Player.mak" CFG="Player - Win32 PlayM4 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Player - Win32 HikPlayM4 Release" (based on "Win32 (x86) Application")
!MESSAGE "Player - Win32 HikPlayM4 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Player - Win32 PlayM4 Release" (based on "Win32 (x86) Application")
!MESSAGE "Player - Win32 PlayM4 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""$/Hikplayer", XDAAAAAA"
# PROP Scc_LocalPath "."
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Player - Win32 HikPlayM4 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Player___Win32_HikPlayM4_Release"
# PROP BASE Intermediate_Dir "Player___Win32_HikPlayM4_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\bin" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\bin\H264Play" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_FOR_HIKPLAYM4_DLL_" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_FOR_HIKPLAYM4_DLL_"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release\hikplayer.exe"
# SUBTRACT BASE LINK32 /nodefaultlib
# ADD LINK32 HikPlayM4.lib /nologo /subsystem:windows /machine:I386 /out:"Release\hikplayer.exe"
# SUBTRACT LINK32 /nodefaultlib
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Desc=copy to
PostBuild_Cmds=copy          .\release\hikplayer.exe           ..\bin\HikPlayM4
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Player - Win32 HikPlayM4 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Player___Win32_HikPlayM4_Debug"
# PROP BASE Intermediate_Dir "Player___Win32_HikPlayM4_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 5
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\bin" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\bin\H264Play" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_FOR_HIKPLAYM4_DLL_" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_FOR_HIKPLAYM4_DLL_"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"Debug\hikplayer.exe" /pdbtype:sept
# ADD LINK32 HikPlayM4.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"Debug\hikplayer.exe" /pdbtype:sept /libpath:"..\bin\HikPlayM4"
# Begin Special Build Tool
SOURCE="$(InputPath)"
PostBuild_Desc=copy to
PostBuild_Cmds=copy          .\debug\hikplayer.exe           ..\bin\HikPlayM4
# End Special Build Tool

!ELSEIF  "$(CFG)" == "Player - Win32 PlayM4 Release"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Player___Win32_PlayM4_Release"
# PROP BASE Intermediate_Dir "Player___Win32_PlayM4_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\bin" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "MIX_INPUT" /D "_AFXDLL" /FR /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386 /out:"Release\hikplayer.exe"
# SUBTRACT BASE LINK32 /nodefaultlib
# ADD LINK32 PlayCtrl.lib /nologo /subsystem:windows /machine:I386
# SUBTRACT LINK32 /nodefaultlib

!ELSEIF  "$(CFG)" == "Player - Win32 PlayM4 Debug"

# PROP BASE Use_MFC 5
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Player___Win32_PlayM4_Debug"
# PROP BASE Intermediate_Dir "Player___Win32_PlayM4_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /I "..\bin" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W4 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FAcs /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /incremental:no /debug /machine:I386 /out:"Debug\hikplayer.exe" /pdbtype:sept
# ADD LINK32 PlayCtrl.lib /nologo /subsystem:windows /map /debug /machine:I386 /pdbtype:sept /libpath:"..\bin\PlayM4"
# SUBTRACT LINK32 /incremental:no

!ENDIF 

# Begin Target

# Name "Player - Win32 HikPlayM4 Release"
# Name "Player - Win32 HikPlayM4 Debug"
# Name "Player - Win32 PlayM4 Release"
# Name "Player - Win32 PlayM4 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Group "Control - Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BCMenu.cpp
# End Source File
# Begin Source File

SOURCE=.\BtnST.cpp
# End Source File
# Begin Source File

SOURCE=.\Color.cpp
# End Source File
# Begin Source File

SOURCE=.\FontSize.cpp
# End Source File
# Begin Source File

SOURCE=.\VolumeCtrl.cpp
# End Source File
# Begin Source File

SOURCE=.\XColorStatic.cpp
# End Source File
# Begin Source File

SOURCE=.\XScrollBar.cpp
# End Source File
# End Group
# Begin Group "AVI - Src"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\CConvertAVI.cpp
# End Source File
# Begin Source File

SOURCE=.\WRIFF.CPP
# End Source File
# End Group
# Begin Source File

SOURCE=.\CutFile.cpp
# End Source File
# Begin Source File

SOURCE=.\DisplayRect.cpp
# End Source File
# Begin Source File

SOURCE=.\HelpDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Info.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.cpp
# End Source File
# Begin Source File

SOURCE=.\Player.rc
# End Source File
# Begin Source File

SOURCE=.\PlayerDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Seek.cpp
# End Source File
# Begin Source File

SOURCE=.\SetKeyDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\VideoCtrlDlg.cpp
# End Source File
# Begin Source File

SOURCE=.\WatermarkDlg.cpp
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=".\res\+.bmp"
# End Source File
# Begin Source File

SOURCE=".\res\-.bmp"
# End Source File
# Begin Source File

SOURCE=.\res\BLACK.bmp
# End Source File
# Begin Source File

SOURCE=.\res\brightness.ico
# End Source File
# Begin Source File

SOURCE=.\res\CAPPIC_AT.ico
# End Source File
# Begin Source File

SOURCE=.\res\CAPPIC_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\CAPPIC_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\contrast.ico
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\res\FASTBACKWARD_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\FASTBACKWARD_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\FASTFORWARD_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\FASTFORWARD_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\GOTOEND_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\GOTOEND_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\GOTOSTART_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\GOTOSTART_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\HIKVISION.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\HorizontalScrollBarChannel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\HorizontalScrollBarLeftArrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\HorizontalScrollBarRightArrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\HorizontalScrollBarThumb.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\HorizontalScrollBarThumbNoColor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\hue.ico
# End Source File
# Begin Source File

SOURCE=.\res\movies.ico
# End Source File
# Begin Source File

SOURCE=.\res\overlay.bmp
# End Source File
# Begin Source File

SOURCE=.\res\PAUSE_CHECK.ico
# End Source File
# Begin Source File

SOURCE=.\res\PAUSE_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\PAUSE_ENABLE.ICO
# End Source File
# Begin Source File

SOURCE=.\res\PLAY_CHECK.ICO
# End Source File
# Begin Source File

SOURCE=.\res\PLAY_DISABLE.ICO
# End Source File
# Begin Source File

SOURCE=.\res\PLAY_ENABLE.ICO
# End Source File
# Begin Source File

SOURCE=.\res\Player.rc2
# End Source File
# Begin Source File

SOURCE=.\res\saturation.ico
# End Source File
# Begin Source File

SOURCE=.\res\SOUND_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\SOUND_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\STEPBACKWARD_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\STEPBACKWARD_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\STEPFORWARD_DISABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\STEPFORWARD_ENABLE.ico
# End Source File
# Begin Source File

SOURCE=.\res\STOP_CHECK.ico
# End Source File
# Begin Source File

SOURCE=.\res\STOP_DISABLE.ICO
# End Source File
# Begin Source File

SOURCE=.\res\STOP_ENABLE.ICO
# End Source File
# Begin Source File

SOURCE=.\res\scroll\VerticalScrollBarChannel.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\VerticalScrollBarDownArrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\VerticalScrollBarThumb.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\VerticalScrollBarThumbNoColor.bmp
# End Source File
# Begin Source File

SOURCE=.\res\scroll\VerticalScrollBarUpArrow.bmp
# End Source File
# Begin Source File

SOURCE=.\res\VideoCtrl.ico
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Control - Hdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\BCMenu.h
# End Source File
# Begin Source File

SOURCE=.\BtnST.h
# End Source File
# Begin Source File

SOURCE=.\Color.h
# End Source File
# Begin Source File

SOURCE=.\FontSize.h
# End Source File
# Begin Source File

SOURCE=.\memdc.h
# End Source File
# Begin Source File

SOURCE=.\VolumeCtrl.h
# End Source File
# Begin Source File

SOURCE=.\XColorStatic.h
# End Source File
# Begin Source File

SOURCE=.\XScrollBar.h
# End Source File
# End Group
# Begin Group "AVI - Hdr"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\AVIFMT.H
# End Source File
# Begin Source File

SOURCE=.\CConvertAVI.h
# End Source File
# Begin Source File

SOURCE=.\WRIFF.H
# End Source File
# End Group
# Begin Source File

SOURCE=.\CutFile.h
# End Source File
# Begin Source File

SOURCE=.\DisplayRect.h
# End Source File
# Begin Source File

SOURCE=.\Extern.h
# End Source File
# Begin Source File

SOURCE=.\HelpDlg.h
# End Source File
# Begin Source File

SOURCE=.\Info.h
# End Source File
# Begin Source File

SOURCE=.\Player.h
# End Source File
# Begin Source File

SOURCE=.\PlayerDlg.h
# End Source File
# Begin Source File

SOURCE=.\plaympeg4.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\Seek.h
# End Source File
# Begin Source File

SOURCE=.\SetKeyDlg.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\VideoCtrlDlg.h
# End Source File
# Begin Source File

SOURCE=.\vkey.h
# End Source File
# Begin Source File

SOURCE=.\WatermarkDlg.h
# End Source File
# Begin Source File

SOURCE=.\watermarkinfo.h
# End Source File
# End Group
# Begin Group "doc"

# PROP Default_Filter ""
# Begin Source File

SOURCE=".\doc\player DEMOÐÞ¸Ä¼ÇÂ¼.doc"
# End Source File
# End Group
# Begin Source File

SOURCE=.\CWatermarkDlg.asp
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
