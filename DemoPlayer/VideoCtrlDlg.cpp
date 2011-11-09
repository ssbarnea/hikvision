// VideoCtrlDlg.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "VideoCtrlDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern LONG m_lPort;

#define COLOR_DEFAULT		64				// brightness, contrast, saturation, hue default value(0~128);

/////////////////////////////////////////////////////////////////////////////
// CVideoCtrlDlg dialog


CVideoCtrlDlg::CVideoCtrlDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CVideoCtrlDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CVideoCtrlDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_hIcon	     =	AfxGetApp()->LoadIcon(IDI_VIDEOCTRL);
	m_pParent	 =  pParent;
}


void CVideoCtrlDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CVideoCtrlDlg)
	DDX_Control(pDX, IDC_VC_SATURATION, m_ctrlVCS);
	DDX_Control(pDX, IDC_VC_RESET, m_ctrlVCReset);
	DDX_Control(pDX, IDC_VC_HUE, m_ctrlVCH);
	DDX_Control(pDX, IDC_VC_CONTRAST, m_ctrlVCC);
	DDX_Control(pDX, IDC_VC_BRIGHTNESS, m_ctrlVCB);
	DDX_Control(pDX, IDC_SLIDER_HUE, m_SliderH);
	DDX_Control(pDX, IDC_SLIDER_SATURATION, m_SliderS);
	DDX_Control(pDX, IDC_SLIDER_CONTRAST, m_SliderC);
	DDX_Control(pDX, IDC_SLIDER_BRIGHTNESS, m_SliderB);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CVideoCtrlDlg, CDialog)
	//{{AFX_MSG_MAP(CVideoCtrlDlg)
	ON_BN_CLICKED(IDC_VC_RESET, OnVcReset)
	ON_WM_CLOSE()
	ON_WM_VSCROLL()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CVideoCtrlDlg message handlers

BOOL CVideoCtrlDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	// Init color slider
	m_SliderB.SetRange(0, 128);
	m_SliderC.SetRange(0, 128);
	m_SliderS.SetRange(0, 128);
	m_SliderH.SetRange(0, 128);

	m_SliderB.SetPos(COLOR_DEFAULT);
	m_SliderC.SetPos(COLOR_DEFAULT);
	m_SliderS.SetPos(COLOR_DEFAULT);
	m_SliderH.SetPos(COLOR_DEFAULT);

	// Init button
	m_ctrlVCB.SetIcon(IDI_BRIGHTNESS);
	m_ctrlVCC.SetIcon(IDI_CONTRAST);
	m_ctrlVCH.SetIcon(IDI_HUE);
	m_ctrlVCS.SetIcon(IDI_SATURATION);

	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


void CVideoCtrlDlg::OnVcReset() 
{
	// TODO: Add your control notification handler code here
	m_SliderB.SetPos(COLOR_DEFAULT);
	m_SliderC.SetPos(COLOR_DEFAULT);
	m_SliderS.SetPos(COLOR_DEFAULT);
	m_SliderH.SetPos(COLOR_DEFAULT);
	
	NAME(PlayM4_SetColor)(m_lPort, 0, COLOR_DEFAULT, COLOR_DEFAULT, COLOR_DEFAULT, COLOR_DEFAULT);
}


void CVideoCtrlDlg::OnClose() 
{
	// TODO: Add your message handler code here and/or call default
	if(m_pParent)
	{
		m_pParent->PostMessage(WM_VIDEOCTRL_OK, 0, 0);
	}
	else
	{
		CDialog::OnClose();
	}
}


void CVideoCtrlDlg::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
	// TODO: Add your message handler code here and/or call default
	int   nBrightness, nContrast, nSaturation, nHue;
	switch(GetWindowLong(pScrollBar->m_hWnd, GWL_ID))
	{	
	case IDC_SLIDER_BRIGHTNESS:
	case IDC_SLIDER_CONTRAST:
	case IDC_SLIDER_SATURATION:
	case IDC_SLIDER_HUE:
		nBrightness = m_SliderB.GetPos();
		nContrast   = m_SliderC.GetPos();
		nSaturation = m_SliderS.GetPos();
		nHue		= m_SliderH.GetPos();
		
		NAME(PlayM4_SetColor)(m_lPort, 0, nBrightness, nContrast, nSaturation, nHue);
		// NAME(PlayM4_GetColor)(m_lPort, 0, &nBrightness, &nContrast, &nSaturation, &nHue);
		// TRACE("Get color(B,C,S,V):%d, %d, %d, %d\n", nBrightness, nContrast, nSaturation, nHue);
		break;
		
	default:
		break;
	}
	CDialog::OnVScroll(nSBCode, nPos, pScrollBar);
}
