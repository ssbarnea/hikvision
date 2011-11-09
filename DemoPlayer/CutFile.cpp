// CutFile.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "CutFile.h"
#include <Shlwapi.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#pragma comment(lib, "Shlwapi.lib")

extern LONG m_lPort;
/////////////////////////////////////////////////////////////////////////////
// CCutFile dialog


CCutFile::CCutFile(CWnd* pParent /*=NULL*/)
	: CDialog(CCutFile::IDD, pParent)
{
	//{{AFX_DATA_INIT(CCutFile)
	m_nBegin		 = 0;
	m_nType			 = 0;
	m_nEnd			 = 0;
	m_strSaveFileName = _T("D:\\Clip.mp4");
	//}}AFX_DATA_INIT
}


void CCutFile::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CCutFile)
	DDX_Text(pDX, IDC_BEGIN, m_nBegin);
	DDX_Radio(pDX, IDC_BYFRAME, m_nType);
	DDX_Text(pDX, IDC_END, m_nEnd);
	DDX_Text(pDX, IDC_FILENAME, m_strSaveFileName);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CCutFile, CDialog)
	//{{AFX_MSG_MAP(CCutFile)
	ON_BN_CLICKED(IDC_VIEW, OnViewNotification)
	ON_BN_CLICKED(IDC_SAVE, OnSave)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CCutFile message handlers

void CCutFile::OnViewNotification() 
{
	OnView();
}

BOOL CCutFile::OnView() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	if(!CheckValue())
	{
		MessageBox("Input value over");
		return FALSE;
	}
	
	DWORD dwType;
	ZeroMemory(&m_stRealBegin, sizeof(FRAME_POS));
	ZeroMemory(&m_stRealEnd, sizeof(FRAME_POS));
	if(m_nType == 0)
	{
		dwType = BY_FRAMENUM;
	}
	else
	{
		dwType = BY_FRAMETIME;
		//conver to ms
		m_nBegin *= 1000;
		m_nEnd   *= 1000;
	}
	
	//locate the I-Frame .
	NAME(PlayM4_GetKeyFramePos)(m_lPort, m_nBegin, dwType, &m_stRealBegin);
	
	if(!NAME(PlayM4_GetNextKeyFramePos)(m_lPort, m_nEnd, dwType, &m_stRealEnd))
	{
		m_stRealEnd.nFilePos   = SetFilePointer(m_hPlayFile, 0, 0, FILE_END);
		m_stRealEnd.nFrameNum  = m_nEnd;
		m_stRealEnd.nFrameTime = m_dwMaxTime*1000;
	}
	DWORD dwBegin = 0;
	DWORD dwEnd = 0;
	if(dwType == BY_FRAMENUM)
	{
		dwBegin = m_stRealBegin.nFrameNum;
		dwEnd   = m_stRealEnd.nFrameNum;
	}
	else if(dwType == BY_FRAMETIME)
	{
		dwBegin = m_stRealBegin.nFrameTime / 1000;
		dwEnd   = m_stRealEnd.nFrameTime / 1000;
	}
	else
	{
		MessageBox("Type is unknown");
		return FALSE;
	}

	CString strReal;
	strReal.Format("%d", dwBegin);
	GetDlgItem(IDC_REAL_BEGIN)->SetWindowText(strReal);
	strReal.Format("%d", dwEnd);
	GetDlgItem(IDC_REAL_END)->SetWindowText(strReal);
	return TRUE;
}

void CCutFile::OnSave() 
{
	// TODO: Add your control notification handler code here
	if(!OnView())
	{
		return;
	}
	int iNewFileLen = int(m_stRealEnd.nFilePos - m_stRealBegin.nFilePos);
	if(iNewFileLen <= 0)
	{
		MessageBox("Stop position less than start position");
		return;
	}
	//UpdateData(TRUE);

	//Copy file
	HANDLE hNewFile = INVALID_HANDLE_VALUE;
	DWORD dwSize = 2048;		//Per 2k data;
	PBYTE pBuf  = NULL;
	DWORD dwFileHeadLen = NAME(PlayM4_GetFileHeadLength)();
	DWORD dwRet;
	DWORD dwBlock  = iNewFileLen / dwSize;
	DWORD dwRemain = iNewFileLen % dwSize;
	DWORD dwCount;

	try
	{
		if(PathFileExists(m_strSaveFileName))
		{
			int nVal = MessageBox("The file already exists, are u sure of covering it now?", "Warning", MB_YESNO | MB_ICONQUESTION);
			if(nVal == IDNO)
			{
				throw 0;
			}		
		}

		hNewFile = CreateFile(
							 m_strSaveFileName,
							 GENERIC_WRITE,
							 FILE_SHARE_READ | FILE_SHARE_WRITE,
							 NULL,
							 CREATE_ALWAYS,
							 FILE_ATTRIBUTE_NORMAL,
							 NULL );
		if(hNewFile == INVALID_HANDLE_VALUE)
		{
			MessageBox("Create saving file faild");
			throw 0;
		}
		

		pBuf = new BYTE [dwSize];
		if(NULL == pBuf)
		{
			MessageBox("Alloc memory failed!");
			throw 0;
		}

		//file header
		SetFilePointer(m_hPlayFile, 0, 0, FILE_BEGIN);
		if(!ReadFile(m_hPlayFile, pBuf, dwFileHeadLen, &dwRet, NULL))
		{
			MessageBox("Read file faild!");
			throw 0;
		}
		else
		{
			if(!WriteFile(hNewFile, pBuf, dwFileHeadLen, &dwRet, NULL))
			{
				MessageBox("Write file faild!");
				throw 0;
			}
		}
		SetFilePointer(m_hPlayFile, m_stRealBegin.nFilePos, 0, FILE_BEGIN);

		
		for(dwCount = 0; dwCount < dwBlock; dwCount ++)
		{
			if(!ReadFile(m_hPlayFile, pBuf, dwSize, &dwRet, NULL))
			{
				MessageBox("Read file faild");
				break;
			}
			if(!WriteFile(hNewFile, pBuf, dwSize, &dwRet, NULL))
			{
				MessageBox("Write file faild");
				break;
			}
		}

		if(!ReadFile(m_hPlayFile, pBuf, dwRemain, &dwRet, NULL))
		{
			MessageBox("Read file faild");
		}

		else
		{
			if(!WriteFile(hNewFile, pBuf, dwRemain, &dwRet, NULL))
					MessageBox("Write file faild");
		}

	}
	catch(...)
	{

	}

	if(pBuf != NULL)
	{
		delete []pBuf;
		pBuf = NULL;
	}

	if(hNewFile != INVALID_HANDLE_VALUE)
	{
		CloseHandle(hNewFile);
		hNewFile = INVALID_HANDLE_VALUE;
	}
}

void CCutFile::OnOK() 
{
	// TODO: Add extra validation here
	CloseHandle(m_hPlayFile);
	CDialog::OnOK();
}

BOOL CCutFile::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dwMaxTime     = NAME(PlayM4_GetFileTime)(m_lPort);
	m_dwMaxFrameNum = NAME(PlayM4_GetFileTotalFrames)(m_lPort);
	CString strRange;
	strRange.Format("Frame number range:%d~%d\r\nTime range(seconds):%d~%d\r\n", 0, m_dwMaxFrameNum, 0, m_dwMaxTime);
	GetDlgItem(IDC_RANGE)->SetWindowText(strRange);

	return TRUE;  // return TRUE unless you set the focus to a control
	// EXCEPTION: OCX Property Pages should return FALSE
}

BOOL CCutFile::CheckValue()
{
	DWORD dwMaxValue;
	if(m_nType == 0)
	{
		dwMaxValue = m_dwMaxFrameNum;
	}
	else
	{
		dwMaxValue = m_dwMaxTime;
	}

	if( (m_nBegin > dwMaxValue) || (m_nEnd > dwMaxValue) )
	{
		return FALSE;
	}

	return TRUE;

}

BOOL CCutFile::SetFileName(CString strName)
{
	m_strPlayFileName = strName;
	m_hPlayFile = CreateFile(
						     strName,
							 GENERIC_READ,
							 FILE_SHARE_READ|FILE_SHARE_WRITE,
							 NULL,
							 OPEN_EXISTING,
							 FILE_ATTRIBUTE_NORMAL,
							 NULL);
	if(m_hPlayFile == INVALID_HANDLE_VALUE)
	{
		MessageBox("Open file faild");
		return FALSE;
	}
	return TRUE;
}
