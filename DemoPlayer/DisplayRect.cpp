// DisplayRect.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "PlayerDlg.h"
#include "DisplayRect.h"
#include <stdio.h>

void RunInfo111(char *szFormat, ...)
{	
	char szInfo[512];
	va_list	ArgumentList;
	
	va_start(ArgumentList, szFormat); 
	vsprintf(szInfo, szFormat, ArgumentList);
	va_end(ArgumentList);
	OutputDebugString(szInfo);
}

extern LONG m_lPort;

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDisplayRect dialog


CDisplayRect::CDisplayRect(CWnd* pParent /*=NULL*/)
	: CDialog(CDisplayRect::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDisplayRect)
	m_nZoom = 100;
	//}}AFX_DATA_INIT
	m_pParent = pParent;
    m_FocusRect.iZoom = 100;
	m_FocusRect.iClientHeight = 288;
	m_FocusRect.iClientWidth = 352;
	m_FocusRect.stCenterPoint.x = 288/2;
	m_FocusRect.stCenterPoint.y = 352/2;
	m_rcRect.left   = 0;
	m_rcRect.bottom = 288;
	m_rcRect.right  = 352;
	m_rcRect.top	= 0;
	m_bValid = FALSE;
	m_state = State_Set;
}


void CDisplayRect::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDisplayRect)
	DDX_Control(pDX, IDC_SLIDER1, m_CtrlZoom);
	DDX_Text(pDX, IDC_EDIT_SIZE, m_nZoom);
	DDV_MinMaxUInt(pDX, m_nZoom, 100, 1100);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDisplayRect, CDialog)
	//{{AFX_MSG_MAP(CDisplayRect)
	ON_BN_CLICKED(IDC_DISPLAY, OnDisplay)
	ON_WM_MOVE()
	ON_WM_PAINT()
	ON_WM_SIZE()
	ON_WM_GETMINMAXINFO()
	ON_WM_HSCROLL()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONDOWN()
	ON_WM_DESTROY()
	//}}AFX_MSG_MAP
	
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDisplayRect message handlers

void CDisplayRect::OnOK() 
{
	// TODO: Add extra validation here
	if(m_pParent)
	{
		if (m_state == State_Set) 
		{    
			Enable(FALSE);
			m_pParent->PostMessage(WM_DISPLAY_OK, 0, 0);
		}
        else 
		{
			Enable(TRUE);
			m_pParent->PostMessage(WM_DISPLAY_OK, 1, 0);
        }
	}
	else
	{
		CDialog::OnOK();
	}
	
}


void CDisplayRect::Enable(BOOL bEnable)
{
    if (bEnable) 
	{
		GetDlgItem(IDC_SLIDER1)->EnableWindow(TRUE);
		GetDlgItem(IDOK)->SetWindowText("Play");
		GetDlgItem(IDC_DISPLAY)->EnableWindow(TRUE);
		m_state = State_Set;
    }
	else
	{
		GetDlgItem(IDC_SLIDER1)->EnableWindow(FALSE);
		GetDlgItem(IDOK)->SetWindowText("Set");
		GetDlgItem(IDC_DISPLAY)->EnableWindow(FALSE);
		m_state = State_Play;
	}

}

void CDisplayRect::OnDisplay() 
{
	// TODO: Add your control notification handler code here
    m_FocusRect.iZoom = 100;
	m_nZoom = m_FocusRect.iZoom;
	
	UpdateData(FALSE);	
	SetDisplayRegion();
	m_CtrlZoom.SetPos(0);
}

void CDisplayRect::SortCtrls()
{
	if( !(GetStyle() & WS_SIZEBOX) )
	{
		return;	
	}
	
	CRect rcClient;
	RECT rcControl;
	GetClientRect(&rcClient);

	int nTempWid = rcClient.Width() - 4;
	int nTempHei = rcClient.Height() - 85;

	if (nTempWid < 0 || nTempHei < 0) 
	{
		return;
	}
	if (nTempWid * m_nVideoHeight > nTempHei * m_nVideoWidth) 
	{
		m_FocusRect.stCenterPoint.x = m_StandardCenterPoint.x * nTempHei/m_nVideoHeight;
		m_FocusRect.stCenterPoint.y = m_StandardCenterPoint.y * nTempHei/m_nVideoHeight;
		TRACE("m_StandardPOint.y = %d", m_StandardCenterPoint.y);

		m_FocusRect.iClientWidth = m_nVideoWidth*nTempHei/m_nVideoHeight;	
		m_FocusRect.iClientHeight = nTempHei;
	}
	else
	{
		m_FocusRect.stCenterPoint.x = m_StandardCenterPoint.x * nTempWid/m_nVideoWidth;
		m_FocusRect.stCenterPoint.y = m_StandardCenterPoint.y * nTempWid/m_nVideoWidth;

		m_FocusRect.iClientHeight = m_nVideoHeight * nTempWid/m_nVideoWidth;	
		m_FocusRect.iClientWidth =  nTempWid;		
	}
	GetDlgItem(IDC_DISWND)->MoveWindow((rcClient.Width()-m_FocusRect.iClientWidth)/2, (rcClient.Height()-80-m_FocusRect.iClientHeight)/2, m_FocusRect.iClientWidth, m_FocusRect.iClientHeight, TRUE);

	DWORD x = (rcClient.Width()-m_FocusRect.iClientWidth)/2;
	DWORD y = rcClient.Height() - 70;
	GetDlgItem(IDC_STATIC_SIZE)->MoveWindow(x, y, 40, 20, TRUE);

	x += 40;
	GetDlgItem(IDC_EDIT_SIZE)->MoveWindow(x, y, 30, 15, TRUE);

	x += 30;
	GetDlgItem(IDC_STATIC_PST)->MoveWindow(x, y, 30, 20, TRUE);

	x += 50 + nTempWid/20;
	GetDlgItem(IDC_STATIC_MINUS)->MoveWindow(x, y, 16, 16, TRUE);

	x += 20;
	GetDlgItem(IDC_SLIDER1)->MoveWindow(x, y, 90, 20, TRUE );

	x += 90;
	GetDlgItem(IDC_STATIC_PLUS)->MoveWindow(x, y, 16, 16, TRUE);

	x = (rcClient.Width()-m_FocusRect.iClientWidth)/2+5;
	y += 30;
	GetDlgItem(IDOK)->MoveWindow(x, y, 70, 20, TRUE);

	x += 125+nTempWid/20;;
	GetDlgItem(IDC_DISPLAY)->MoveWindow(x, y, 70, 20, TRUE);

	rcControl.left = (rcClient.Width()-m_FocusRect.iClientWidth)/2;
	rcControl.right = x +200;
	rcControl.top = rcClient.Height() - 70;
	rcControl.bottom = y + 25;
 	InvalidateRect(&rcControl);
	
}


void CDisplayRect::DisplayRect(WPARAM /*wParam*/, LPARAM /*lParam*/)
{
//	CRect * rcRect = (CRect*)lParam;

	UpdateData(FALSE);
}

void CDisplayRect::InitShow()
{
	SortCtrls();

    NAME(PlayM4_SetDisplayRegion)(m_lPort, 1, &m_rcRect, GetDlgItem(IDC_DISWND)->m_hWnd, TRUE);
	NAME2(PlayM4_RefreshPlayEx)(m_lPort, 1);
}

BOOL CDisplayRect::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	m_dwScreenWidth  = GetSystemMetrics(SM_CXSCREEN);
	m_dwScreenHeight = GetSystemMetrics(SM_CYSCREEN);
	
	m_dwOldDeviceNum = 0;
	m_CtrlZoom.SetRange(0, 1000);
	m_CtrlZoom.SetPos(m_FocusRect.iZoom - 100);	
	m_bValid = TRUE;
	m_state = State_Set;
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}


BOOL CDisplayRect::SetDevice(UINT nSeq)
{
	BOOL bFunctionOK = FALSE;

#if (WINVER > 0x0400)
	DWORD nVal = NAME(PlayM4_GetDDrawDeviceTotalNums)();
	if(nVal >= 1)
	{
		if(NAME(PlayM4_SetDDrawDeviceEx)(m_lPort, 1, nSeq + 1))
		{
			bFunctionOK = TRUE;
		}
	}
#endif

	return bFunctionOK;
}

BOOL CDisplayRect::SetResolution(int nHei, int nWid)
{
	//设置图像客户区默认大小
	m_FocusRect.iClientWidth	= 352;
	m_FocusRect.iClientHeight	= nHei*352/nWid;
	m_nVideoWidth				= nWid;
	m_nVideoHeight				= nHei;
	m_rcRect.right				= nWid;
	m_rcRect.bottom				= nHei;
	
    m_FocusRect.stCenterPoint.x	= m_FocusRect.iClientWidth/2;
	m_FocusRect.stCenterPoint.y	= m_FocusRect.iClientHeight/2;
	m_StandardCenterPoint.x		= m_FocusRect.stCenterPoint.x;
	m_StandardCenterPoint.y		= m_FocusRect.stCenterPoint.y;
	m_FocusRect.iZoom			= 100;
	m_nZoom						= 100;
	return TRUE;
}

void CDisplayRect::OnMove(int x, int y) 
{
	CDialog::OnMove(x, y);
	
	// TODO: Add your message handler code here
	GetWindowRect(&m_rcWindow);
	DWORD dwNewDeviceNum;

	if(m_rcWindow.left < 0)
	{
		return;
	}
	
	if( (DWORD)m_rcWindow.right + (DWORD)m_rcWindow.left > 2 * m_dwScreenWidth )
	{
		if( (DWORD)m_rcWindow.top + (DWORD)m_rcWindow.bottom > 2 * m_dwScreenHeight)
		{
			dwNewDeviceNum = 3;
		}
		else 
		{
			dwNewDeviceNum = 1;
		}
	}
	else
	{
		if( (DWORD)m_rcWindow.top + (DWORD)m_rcWindow.bottom > 2 * m_dwScreenHeight)
		{
			dwNewDeviceNum = 2;
		}
		else 
		{
			dwNewDeviceNum = 0;
		}
	}
	
	if(dwNewDeviceNum != m_dwOldDeviceNum)
	{
		if(SetDevice(dwNewDeviceNum))
		{
			m_dwOldDeviceNum = dwNewDeviceNum;
		}
	}
}


void CDisplayRect::OnPaint() 
{
	CPaintDC dc(this); // device context for painting
	
	// TODO: Add your message handler code here
	UpdateWindow();
	NAME2(PlayM4_RefreshPlayEx)(m_lPort, 1);	

	DrawRectangle();
	// Do not call CDialog::OnPaint() for painting messages
}

void CDisplayRect::DrawRectangle()
{
	if (m_state == State_Play) 
	{
		return;
	}

	RECT DisRect;

    CBrush brush2(RGB(255,0,0)); 	
 	CDC* pDC = GetDlgItem(IDC_DISWND)->GetDC(); 
	
	GetFocusRectangle(DisRect);

	pDC->FrameRect(&DisRect, &brush2);
}

void CDisplayRect::GetFocusRectangle(RECT& DisRect)
{   
	int iWidth, iHeight;
	CRect VideoRect;

	GetDlgItem(IDC_DISWND)->GetClientRect(VideoRect);
	iWidth = m_FocusRect.iClientWidth*100/m_FocusRect.iZoom;
	iHeight = m_FocusRect.iClientHeight*100/m_FocusRect.iZoom;
	DisRect.left = m_FocusRect.stCenterPoint.x + VideoRect.left - iWidth/2;
	DisRect.right = DisRect.left + iWidth;
	DisRect.top = VideoRect.top + m_FocusRect.stCenterPoint.y - iHeight/2;
	DisRect.bottom = DisRect.top + iHeight;

	if (DisRect.bottom > VideoRect.bottom) 
	{
		DisRect.top -= (DisRect.bottom - VideoRect.bottom);	
		m_FocusRect.stCenterPoint.y -= (DisRect.bottom - VideoRect.bottom);
		DisRect.bottom = VideoRect.bottom; 

	}
	if (DisRect.right > VideoRect.right) 
	{
		DisRect.left -= (DisRect.right - VideoRect.right);
		m_FocusRect.stCenterPoint.x -= (DisRect.right - VideoRect.right);
		DisRect.right = VideoRect.right;
	}
	if (DisRect.top < VideoRect.top) 
	{
		DisRect.bottom = VideoRect.top + iHeight;
		DisRect.top = VideoRect.top;
		m_FocusRect.stCenterPoint.y = VideoRect.top + iHeight/2;
	}
	if (DisRect.left < VideoRect.left) 
	{
		DisRect.right = VideoRect.left + iWidth;
		DisRect.left = VideoRect.left;
		m_FocusRect.stCenterPoint.x = VideoRect.left + iWidth/2;
	}
//	m_StandardCenterPoint.x = m_FocusRect.CenterPoint.x * m_nVideoWidth/VideoRect.Width();
// 	m_StandardCenterPoint.y = m_FocusRect.CenterPoint.y * m_nVideoHeight/VideoRect.Height();
}

void CDisplayRect::OnSize(UINT nType, int cx, int cy) 
{
	CDialog::OnSize(nType, cx, cy);
	
	// TODO: Add your message handler code here
	if (GetDlgItem(IDC_DISWND)->GetSafeHwnd()) 
	{
		SortCtrls();
	}
	
}

void CDisplayRect::OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI) 
{
	// TODO: Add your message handler code here and/or call default

	lpMMI->ptMinTrackSize.x = 280;
	lpMMI->ptMinTrackSize.y = 350;
//	CDialog::OnGetMinMaxInfo(lpMMI);
}

void CDisplayRect::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar) 
{
  // Get the current position of scroll box.
  int curpos = m_CtrlZoom.GetPos();

	m_FocusRect.iZoom = 100 + curpos;
	m_nZoom = m_FocusRect.iZoom;
	
	UpdateData(FALSE);
	SetDisplayRegion();
	
	CDialog::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CDisplayRect::OnMouseMove(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_state == State_Play) 
	{
		return;
	}

	POINT VideoPoint;
	POINT Point1, Point2;     
	CRect CRctFocus;
	CRect VideoRect;
	GetFocusRectangle(CRctFocus);
	VideoPoint.x = point.x;
	VideoPoint.y = point.y;
	ClientToScreen(&VideoPoint);

	if (MK_LBUTTON == nFlags) 
	{
		if (PtInFocusRect(VideoPoint)) 
		{
			VideoPoint.x -= m_FocusPoint.x;
			VideoPoint.y -= m_FocusPoint.y;

			m_FocusPoint = point;
			ClientToScreen(&m_FocusPoint);

			m_FocusRect.stCenterPoint.x += VideoPoint.x;
			m_FocusRect.stCenterPoint.y += VideoPoint.y;

			CRctFocus += VideoPoint;

			GetDlgItem(IDC_DISWND)->GetClientRect(VideoRect);


			Point1 = CRctFocus.TopLeft();
			Point2 = VideoRect.TopLeft();

			if (Point1.x - Point2.x < 0) 
			{
				m_FocusRect.stCenterPoint.x += Point2.x - Point1.x;
			}

			if (Point1.y - Point2.y < 0) 
			{
				m_FocusRect.stCenterPoint.y += Point2.y - Point1.y;
			}
			Point1 = CRctFocus.BottomRight();
			Point2 = VideoRect.BottomRight();

			if (Point1.x - Point2.x > 0) 
			{
				m_FocusRect.stCenterPoint.x -= (Point1.x - Point2.x);
			}
			if (Point1.y - Point2.y > 0) 
			{
				m_FocusRect.stCenterPoint.y -= (Point1.y - Point2.y);
			}

			m_StandardCenterPoint.x = m_FocusRect.stCenterPoint.x * m_nVideoWidth/m_FocusRect.iClientWidth;
            m_StandardCenterPoint.y = m_FocusRect.stCenterPoint.y * m_nVideoHeight/m_FocusRect.iClientHeight;
			SetDisplayRegion();
		}
	}
	
	CDialog::OnMouseMove(nFlags, point);
}

BOOL CDisplayRect::PtInFocusRect(POINT Point)
{
	RECT FocusRect;	
	GetFocusRectangle(FocusRect);
	GetDlgItem(IDC_DISWND)->ClientToScreen(&FocusRect);
	return PtInRect(&FocusRect, Point);
}

BOOL CDisplayRect::PtInVideoRect(POINT Point)
{
	RECT VideoRct;
	GetDlgItem(IDC_DISWND)->GetWindowRect(&VideoRct);
	return PtInRect(&VideoRct, Point);
}

void CDisplayRect::OnLButtonDown(UINT nFlags, CPoint point) 
{
	// TODO: Add your message handler code here and/or call default

	if (m_state == State_Play) 
	{
		return;
	}

	CRect FocusRect, VideoRect;
	POINT ClientPoint;
	ClientPoint.x = point.x;
	ClientPoint.y = point.y;
	ClientToScreen(&ClientPoint);

	if (PtInFocusRect(ClientPoint)) 
	{
		m_FocusPoint = ClientPoint;
	}
	else
	{
		if (PtInVideoRect(ClientPoint)) 
		{	
			GetDlgItem(IDC_DISWND)->ScreenToClient(&ClientPoint);
			m_FocusRect.stCenterPoint.x = ClientPoint.x;
			m_FocusRect.stCenterPoint.y = ClientPoint.y;

			GetFocusRectangle(FocusRect);
			GetDlgItem(IDC_DISWND)->GetClientRect(VideoRect);
			if (ClientPoint.x + (FocusRect.Width())/2 >= VideoRect.right) 
			{
				m_FocusRect.stCenterPoint.x = VideoRect.Width() - (FocusRect.Width())/2;
			}

			if (ClientPoint.y + (FocusRect.Height())/2 >= VideoRect.bottom) 
			{
				m_FocusRect.stCenterPoint.y = VideoRect.Height() - (FocusRect.Height())/2;
			}

			if (ClientPoint.x < (FocusRect.Width())/2) 
			{
				m_FocusRect.stCenterPoint.x = (FocusRect.Width())/2;
			}

			if (ClientPoint.y < (FocusRect.Height())/2) 
			{
				m_FocusRect.stCenterPoint.y = (FocusRect.Height())/2;
			}
			m_StandardCenterPoint.x = m_FocusRect.stCenterPoint.x * m_nVideoWidth/m_FocusRect.iClientWidth;
            m_StandardCenterPoint.y = m_FocusRect.stCenterPoint.y * m_nVideoHeight/m_FocusRect.iClientHeight;
			
		}		
		SetDisplayRegion();
	}
	CDialog::OnLButtonDown(nFlags, point);
}

void CDisplayRect::SetDisplayRegion()
{

	UpdateWindow();
	NAME2(PlayM4_RefreshPlayEx)(m_lPort, 1);	

	DrawRectangle();

	RECT RectFocus, RectDisplay;
	POINT stCenterPoint;
    GetFocusRectangle(RectFocus);
	stCenterPoint.x = m_FocusRect.stCenterPoint.x * m_nVideoWidth/m_FocusRect.iClientWidth;
	stCenterPoint.y = m_FocusRect.stCenterPoint.y * m_nVideoHeight/m_FocusRect.iClientHeight;
    RectDisplay.left = stCenterPoint.x -  (RectFocus.right - RectFocus.left)/2 * m_nVideoWidth/m_FocusRect.iClientWidth;
	RectDisplay.right = RectDisplay.left 
		              + (RectFocus.right - RectFocus.left) * m_nVideoWidth/m_FocusRect.iClientWidth;
	RectDisplay.top = stCenterPoint.y - (RectFocus.bottom - RectFocus.top)/2 * m_nVideoHeight/m_FocusRect.iClientHeight;
	RectDisplay.bottom = RectDisplay.top 
		               + (RectFocus.bottom - RectFocus.top) * m_nVideoHeight/m_FocusRect.iClientHeight;
	((CPlayerDlg*)m_pParent)->SetDisplayRegion(RectDisplay);

// 	if (m_nZoom == 100)
// 	{
// 		RectDisplay.left = 0;
// 		RectDisplay.right = m_nVideoWidth;
// 		RectDisplay.top = 0;
// 		RectDisplay.bottom = m_nVideoHeight;
// 		
// 		((CPlayerDlg*)m_pParent)->SetDisplayRegion(RectDisplay);
// 	}
// 	else
// 	{
// 		((CPlayerDlg*)m_pParent)->SetDisplayRegion(RectDisplay);
// 	}
// 	
}

void CDisplayRect::OnDestroy() 
{
	CDialog::OnDestroy();
	
	// TODO: Add your message handler code here
	NAME(PlayM4_SetDisplayRegion)(m_lPort, 1, &m_rcRect, NULL, FALSE);
	m_bValid = FALSE;	

}
