#if !defined(AFX_VIDEOCTRLDLG_H__C1F90363_064F_4E3C_84E7_545855BA4E4A__INCLUDED_)
#define AFX_VIDEOCTRLDLG_H__C1F90363_064F_4E3C_84E7_545855BA4E4A__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// VideoCtrlDlg.h : header file
//

#include "BtnST.h"

#define WM_VIDEOCTRL_OK WM_USER + 201

/////////////////////////////////////////////////////////////////////////////
// CVideoCtrlDlg dialog

class CVideoCtrlDlg : public CDialog
{
// Construction
public:
	CWnd* m_pParent;
	CVideoCtrlDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CVideoCtrlDlg)
	enum { IDD = IDD_VIDEOCTRL };
	CButtonST		m_ctrlVCS;
	CButtonST		m_ctrlVCH;
	CButtonST		m_ctrlVCC;
	CButtonST		m_ctrlVCB;
	CButton			m_ctrlVCReset;
	CSliderCtrl		m_SliderH;
	CSliderCtrl		m_SliderS;
	CSliderCtrl		m_SliderC;
	CSliderCtrl		m_SliderB;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CVideoCtrlDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CVideoCtrlDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnVcReset();
	afx_msg void OnClose();
	afx_msg void OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_VIDEOCTRLDLG_H__C1F90363_064F_4E3C_84E7_545855BA4E4A__INCLUDED_)
