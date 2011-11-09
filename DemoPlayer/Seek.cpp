// Seek.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "Seek.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern LONG m_lPort;
/////////////////////////////////////////////////////////////////////////////
// CSeek dialog


CSeek::CSeek(CWnd* pParent /*=NULL*/)
	: CDialog(CSeek::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSeek)
	m_nSeekType = 0;
	m_nValue	= 0;
	//}}AFX_DATA_INIT
	m_pParent	= pParent;
}


void CSeek::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSeek)
	DDX_Radio(pDX, IDC_BYFRAME, m_nSeekType);
	DDX_Text(pDX, IDC_VALUE, m_nValue);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSeek, CDialog)
	//{{AFX_MSG_MAP(CSeek)
	ON_BN_CLICKED(IDC_SEEK, OnSeek)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSeek message handlers

void CSeek::OnSeek() 
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	
	if(m_nSeekType == 0)
	{
		if(m_nValue >= m_dwMaxFrameNum)
		{
			MessageBox("Input frame number is over!");
			return;
		}
		NAME2(PlayM4_SetCurrentFrameNum)(m_lPort, m_nValue);
		
		// ssbarnea: add for debugging purpose
		DWORD got = NAME2(PlayM4_GetCurrentFrameNum)(m_lPort);
		if (m_nValue != got) {
			TRACE("Error setting frame, expected %d but got %d", m_nValue, got);
		}

	}
	else if(m_nSeekType == 1)
	{
		if(m_nValue > m_dwMaxTime)
		{
			MessageBox("Input time is over!");
			return;
		}
		NAME(PlayM4_SetPlayedTimeEx)(m_lPort, m_nValue*1000);
	}
		
}

BOOL CSeek::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dwMaxTime     = NAME(PlayM4_GetFileTime)(m_lPort);
	m_dwMaxFrameNum = NAME(PlayM4_GetFileTotalFrames)(m_lPort);
	CString csRange;
	csRange.Format("Frame number range:%d~%d\r\nTime range(Seconds)£º%d~%d\r\n", 0, m_dwMaxFrameNum, 0, m_dwMaxTime);
	GetDlgItem(IDC_RANGE)->SetWindowText(csRange);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSeek::OnOK() 
{
	// TODO: Add extra validation here
	if(m_pParent)
	{
		m_pParent->PostMessage(WM_SEEKOK, 0, 0);
	}
	else
	{
		CDialog::OnOK();
	}
}
