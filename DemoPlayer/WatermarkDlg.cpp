// WaterMarkDlg.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "PlayerDlg.h"
#include "watermarkinfo.h"
#include "WatermarkDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

#define WATERMARK_TIMER 10
HBRUSH hBrush = CreateSolidBrush(COLORREF(0x000000));

extern WATERMARK_VER1_INFO m_strWaterMark;
/////////////////////////////////////////////////////////////////////////////
// CWatermarkDlg dialog

CWatermarkDlg::CWatermarkDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CWatermarkDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CWatermarkDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dwTimer = 0;
	m_pParent = pParent;
}


void CWatermarkDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CWatermarkDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CWatermarkDlg, CDialog)
	//{{AFX_MSG_MAP(CWatermarkDlg)
	ON_WM_CTLCOLOR()
	ON_WM_DESTROY()
	ON_WM_TIMER()
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// WatermarkDlg message handlers

HBRUSH CWatermarkDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT /*nCtlColor*/) 
{
	UNREFERENCED_PARAMETER(pWnd);
//	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	
	// TODO: Change any attributes of the DC here
	pDC->SetTextColor(RGB(255, 255, 255));
	pDC->SetBkColor(RGB(0, 0, 0));

	// TODO: Return a different brush if the default is not desired
	return hBrush;
//	return hbr;
}

void CWatermarkDlg::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	if(m_dwTimer != 0)
	{
		KillTimer(WATERMARK_TIMER);
		m_dwTimer = 0;
	}
}

BOOL CWatermarkDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here

	if(m_dwTimer == 0)
	{
		m_dwTimer = SetTimer(WATERMARK_TIMER, 100, NULL);
	}

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CWatermarkDlg::OnTimer(UINT nIDEvent) 
{
	// TODO: Add your message handler code here and/or call default
	if(nIDEvent == WATERMARK_TIMER)
	{
		char cstr[256];
		int nOsdYear, nOsdMonth, nOsdDay, nOsdHour, nOsdMin, nOsdSec;		
	
		if(m_strWaterMark.global_time > 0)
		{
			nOsdYear	= GET_FILE_YEAR(m_strWaterMark.global_time);
			nOsdMonth	= GET_FILE_MONTH(m_strWaterMark.global_time);
			nOsdDay		= GET_FILE_DAY(m_strWaterMark.global_time);
			nOsdHour	= GET_FILE_HOUR(m_strWaterMark.global_time);
			nOsdMin		= GET_FILE_MINUTE(m_strWaterMark.global_time);
			nOsdSec		= GET_FILE_SECOND(m_strWaterMark.global_time);
			sprintf(cstr, "%04d-%02d-%-02d %02d:%02d:%02d", nOsdYear, nOsdMonth, nOsdDay, nOsdHour, nOsdMin, nOsdSec);
			GetDlgItem(IDC_GLOBALTIME)->SetWindowText(cstr);
			sprintf(cstr,"%02x:%02x:%02x:%02x:%02x:%02x", 
					m_strWaterMark.mac_addr[0], m_strWaterMark.mac_addr[1], 
					m_strWaterMark.mac_addr[2], m_strWaterMark.mac_addr[3],
					m_strWaterMark.mac_addr[4], m_strWaterMark.mac_addr[5]);
			GetDlgItem(IDC_MAC)->SetWindowText(cstr);
			sprintf(cstr,"%d", m_strWaterMark.device_sn);
			GetDlgItem(IDC_DEVICESN)->SetWindowText(cstr);
			sprintf(cstr,"%d", m_strWaterMark.device_info);
			GetDlgItem(IDC_DEVICEINFO)->SetWindowText(cstr);
			sprintf(cstr,"%d", m_strWaterMark.channel_num);
			GetDlgItem(IDC_CHAN)->SetWindowText(cstr);
			sprintf(cstr,"%d", m_strWaterMark.device_type);
			GetDlgItem(IDC_DEVICETYPE)->SetWindowText(cstr);
		}
	}

	CDialog::OnTimer(nIDEvent);
}

void CWatermarkDlg::Clear()
{
	GetDlgItem(IDC_GLOBALTIME)->SetWindowText(" ");
	GetDlgItem(IDC_MAC)->SetWindowText(" ");
	GetDlgItem(IDC_DEVICESN)->SetWindowText(" ");
	GetDlgItem(IDC_DEVICEINFO)->SetWindowText(" ");
	GetDlgItem(IDC_CHAN)->SetWindowText(" ");
	GetDlgItem(IDC_DEVICETYPE)->SetWindowText(" ");
}

void CWatermarkDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pParent)
	{
		m_pParent->PostMessage(WM_WATERMARK_OK, 0, 0);
	}

	CDialog::OnClose();
}

