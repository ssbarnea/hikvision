#if !defined(AFX_VOLUMECTRL_H__AFBF9D0E_12E4_46EA_93E9_D983DC8C1DA9__INCLUDED_)
#define AFX_VOLUMECTRL_H__AFBF9D0E_12E4_46EA_93E9_D983DC8C1DA9__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VolumeCtrl.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CVolumeCtrl window

class CVolumeCtrl : public CSliderCtrl
{
// Construction
public:
	CVolumeCtrl();

// Attributes
public:
	CBrush	m_brush;
	CPen	m_LightPen;
	CPen	m_ShadowPen;
	POINT	m_MousePt;
// Operations
public:
	void DrawTriangle(CDC *pDC, CRect *prcDraw);
	BOOL PreTranslateMessage(MSG* pMsg);
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVolumeCtrl)
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CVolumeCtrl();

	// Generated message map functions
protected:
	//{{AFX_MSG(CVolumeCtrl)
	afx_msg void OnPaint();
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VOLUMECTRL_H__AFBF9D0E_12E4_46EA_93E9_D983DC8C1DA9__INCLUDED_)
