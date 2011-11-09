// hikdump.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "hikdump.h"
#include "../SDK/PlayM4.h"
#include <cstdio>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CWinApp theApp;
bool isIndexed = false;

using namespace std;

void _stdcall pFileRefDone(DWORD nPort, DWORD nUser) {
	isIndexed = true;
	cout << "Callback called, file is indexed (" << nPort << "," << nUser<< ")" << endl;
}

int main(int argc, char* argv[], char* envp[])
{
	int nRetCode = 0;

	HMODULE hModule = ::GetModuleHandle(NULL);

	if (hModule == NULL)
	{
		printf("Fatal Error: GetModuleHandle failed\n");
		nRetCode = 1;
	}

	if (argc != 2) {
		cout << "Called with invalid number of parameters. You need to specify the video filename.";
		return -1;
	}

	HINSTANCE dll;
	dll = LoadLibrary("./PlayCtrl.dll"); // STEP-1
 
	if (dll == 0)
	{
		cout << "Unable to load HISDK player library!" << endl;
		return -1;
	}

	long port = 0;
	
	printf("%.8x <- PlayM4_GetPort()\n\r", PlayM4_GetSdkVersion());
	cout << PlayM4_GetPort(&port) << " <- PlayM4_GetPort() " << endl; // STEP-2

	cout << PlayM4_SetFileRefCallBack(port, pFileRefDone, 0) << " <- PlayM4_SetFileRefCallBack() " << endl; // STEP-3
	
	int ret = PlayM4_OpenFile(port, argv[1]);
	if (ret==0) { // STEP-4
		cout << "Unable to open video file " << argv[1];
		return -1;
	} else cout << ret << " <- PlayM4_OpenFile()" << endl;
	
	while(!isIndexed) { // STEP-5
		Sleep(500);
	}
	
	long width = 0, height = 0;
	PlayM4_GetPictureSize(port,&width,&height); 
	cout << width << "x" << height << " <- PlayM4_GetPictureSize()" << endl;
    
	int frames = PlayM4_GetFileTotalFrames(port); // STEP-6
    cout << frames << " <- PlayM4_GetFileTotalFrames()" << endl;
	
	cout << PlayM4_Play(port, 0) << " <- PlayM4_Play(port,0)" << endl; // STEP-7
    cout << PlayM4_Pause(port, 1) << " <- PlayM4_Pause(port,1)" << endl; // STEP-8
	//cout << PlayM4_OneByOne(port) << " <- PlayM4_OneByOne()" << endl;
	
	int range = min(100, frames);
	int failures = 0;
	int successes = 0;

	for(int i=0;i<range;i++) {
		// note, do not assume what was the previous frame, this should work for any frame in the video

		int ret = PlayM4_SetCurrentFrameNum(port, i); // STEP-9
		//Sleep(100);
		int got = PlayM4_GetCurrentFrameNum(port); // STEP-10
		if (!ret || i!=got) {
			cout << "Expect " << i << " but got " << got << "" << endl;
			failures++;
		}
		else successes++;
    
	}

	cout << "Test ended with " << failures << " failures and " << successes << " successes.";

	return nRetCode;
}
