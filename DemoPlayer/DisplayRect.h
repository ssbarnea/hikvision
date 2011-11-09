#if !defined(AFX_DISPLAYRECT_H__82EB3617_68F4_42E2_8E5D_5B7056C7C8A9__INCLUDED_)
#define AFX_DISPLAYRECT_H__82EB3617_68F4_42E2_8E5D_5B7056C7C8A9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DisplayRect.h : header file
//
class CPlayerDlg;
/////////////////////////////////////////////////////////////////////////////
// CDisplayRect dialog
#define WM_DISPLAY_OK WM_USER+35
#define WM_DISPLAY_RECT WM_USER+36
class CDisplayRect : public CDialog
{
// Construction
   friend class CPlayerDlg;
public:
	CWnd* m_pParent;
	CDisplayRect(CWnd* pParent = NULL);   // standard constructor
	RECT		m_rcRect;
	RECT		m_rcWindow;				  // window rect
	DWORD		m_dwOldDeviceNum;		  // old display device sequence
	DWORD		m_dwScreenHeight;         // screem height
	DWORD		m_dwScreenWidth;          // screen width	

public:
	BOOL  SetDevice(UINT nSeq);
	BOOL  SetResolution(int nHei, int nWid);
	void  InitShow();
	void  Enable(BOOL);
// Dialog Data
	//{{AFX_DATA(CDisplayRect)
	enum { IDD = IDD_RANGE };
	CSliderCtrl	m_CtrlZoom;
	UINT	m_nZoom;
	//}}AFX_DATA

	afx_msg void DisplayRect(WPARAM wParam, LPARAM lParam);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDisplayRect)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDisplayRect)
	virtual void OnOK();
	afx_msg void OnDisplay();
	virtual BOOL OnInitDialog();
	afx_msg void OnMove(int x, int y);
	afx_msg void OnPaint();
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnGetMinMaxInfo(MINMAXINFO FAR* lpMMI);
	afx_msg void OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnDestroy();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	void SortCtrls();
	void DrawRectangle();
	void GetFocusRectangle(RECT&);
	BOOL PtInFocusRect(POINT);
	BOOL PtInVideoRect(POINT);
	void SetDisplayRegion();

	struct myrect
	{
		POINT stCenterPoint;
		int iZoom;
		int iClientHeight;
		int iClientWidth;
	};

	myrect m_FocusRect;
	int m_nVideoHeight;
	int m_nVideoWidth;
	CPoint m_FocusPoint;
	BOOL m_bValid;
	POINT m_StandardCenterPoint;

	enum state 
	{ 
		State_Play,
		State_Set
	}m_state;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DISPLAYRECT_H__82EB3617_68F4_42E2_8E5D_5B7056C7C8A9__INCLUDED_)
