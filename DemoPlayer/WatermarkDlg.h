#if !defined(AFX_WATERMARKDLG_H__64C35B92_753A_400B_BB6B_DAAD9E6E63D5__INCLUDED_)
#define AFX_WATERMARKDLG_H__64C35B92_753A_400B_BB6B_DAAD9E6E63D5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// WaterMarkDlg.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// WaterMarkDlg dialog
#define WM_WATERMARK_OK WM_USER + 37

class CWatermarkDlg : public CDialog
{
// Construction
public:
	CWnd* m_pParent;
	CWatermarkDlg(CWnd* pParent = NULL);   // standard constructor
	
	void Clear();
protected:
	DWORD m_dwTimer;
	
// Dialog Data
	//{{AFX_DATA(CWatermarkDlg)
	enum { IDD = IDD_WATERMARK };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CWatermarkDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CWatermarkDlg)
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnDestroy();
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT nIDEvent);
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_WATERMARKDLG_H__64C35B92_753A_400B_BB6B_DAAD9E6E63D5__INCLUDED_)
