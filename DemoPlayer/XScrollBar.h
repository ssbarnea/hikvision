// XScrollBar.h  Version 1.1
//
// Author:  Hans Dietrich
//          hdietrich@gmail.com
//
// License:
//     This software is released into the public domain.  You are free to use
//     it in any way you like, except that you may not sell this source code.
//
//     This software is provided "as is" with no expressed or implied warranty.
//     I accept no liability for any damage or loss of business that this
//     software may cause.
//
///////////////////////////////////////////////////////////////////////////////

#ifndef XSCROLLBAR_H
#define XSCROLLBAR_H

/////////////////////////////////////////////////////////////////////////////
// CXScrollBar

class CXScrollBar : public CStatic
{
// Construction
public:
	CXScrollBar();
	virtual ~CXScrollBar();
	BOOL CreateFromStatic(DWORD dwStyle,
						  CWnd* pParentWnd,
						  UINT nIdStatic,
						  UINT nId);

// Attributes
public:
	void	EnableChannelColor(BOOL bEnable) { m_bChannelColor = bEnable; }
	void	EnableThumbColor(BOOL bEnable) { m_bThumbColor = bEnable; }
	void	EnableThumbGripper(BOOL bGripper) { m_bThumbGripper = bGripper; }

	int		GetScrollPos() const { return m_nPos; }

	int		SetScrollPos(int nPos, BOOL bRedraw = TRUE);
	void	SetScrollRange(int nMinPos, int nMaxPos, BOOL bRedraw = TRUE);
	void	SetThumbColor(COLORREF rgb) { m_ThumbColor = rgb; m_bThumbColor = TRUE; }
	void	SetThumbHoverColor(COLORREF rgb) { m_ThumbHoverColor = rgb; }
	
	void MoveWindowEx(int x, int y, int nWidth, int nHeight, BOOL bRepaint = TRUE) 
					{ UNREFERENCED_PARAMETER(bRepaint); 
					  MoveWindow(x, y, nWidth, nHeight); 
					  GetClientRect(&m_rectClient); 
					}
	
// Operations
public:
	void	ScrollLeft();
	void	ScrollRight();
	void	ScrollUp();
	void	ScrollDown();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CXScrollBar)
	//}}AFX_VIRTUAL

// Implementation
protected:
	CWnd *		m_pParent;				// control parent 
	int			m_nThumbLeft;			// left margin of thumb
	int			m_nThumbTop;			// top margin of thumb
	int			m_nBitmapHeight;		// height of arrow and thumb bitmaps
	int			m_nBitmapWidth;			// width of arrow and thumb bitmaps
	int			m_nPos;					// current thumb position in scroll units
	int			m_nMinPos;				// minimum scrolling position
	int			m_nMaxPos;				// maximum scrolling position
	int			m_nRange;				// absolute value of max - min pos
	CRect		m_rectThumb;			// current rect for thumb
	CRect		m_rectClient;			// control client rect
    HCURSOR		m_hCursor;				// hand cursor
	COLORREF	m_ThumbColor;			// thumb color
	COLORREF	m_ThumbHoverColor;		// thumb color when mouse hovers
	BOOL		m_bThumbColor;			// TRUE = display thumb with color
	BOOL		m_bChannelColor;		// TRUE = display color in channel
	BOOL		m_bThumbGripper;		// TRUE = display thumb gripper
	BOOL		m_bThumbHover;			// TRUE = mouse is over thumb
	BOOL		m_bMouseDownArrowRight;	// TRUE = mouse over right arrow & left button down
	BOOL		m_bMouseDownArrowLeft;	// TRUE = mouse over left arrow & left button down
	BOOL		m_bMouseDownArrowUp;	// TRUE = mouse over left arrow & left button down
	BOOL		m_bMouseDownArrowDown;	// TRUE = mouse over right arrow & left button down
	BOOL		m_bMouseDown;			// TRUE = mouse over thumb & left button down
	BOOL		m_bDragging;			// TRUE = thumb is being dragged
	BOOL		m_bHorizontal;			// TRUE = horizontal scroll bar

	void		Draw();
	void		DrawHorizontal();
	void		DrawVertical();
	void		LimitThumbPosition();
	void		SetDefaultCursor();
	void		SetPositionFromThumb();
	void		UpdateThumbPosition();

	// Generated message map functions
protected:
	//{{AFX_MSG(CXScrollBar)
	afx_msg void OnPaint();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnTimer(UINT nIDEvent);
    afx_msg BOOL OnSetCursor(CWnd* pWnd, UINT nHitTest, UINT message);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif //XSCROLLBAR_H
