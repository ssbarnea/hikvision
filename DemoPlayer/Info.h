#if !defined(AFX_INFO_H__790410AB_7F0A_4383_9344_93A649AF432E__INCLUDED_)
#define AFX_INFO_H__790410AB_7F0A_4383_9344_93A649AF432E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Info.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CInfo dialog

class CInfo : public CDialog
{
// Construction
public:
	CString m_strInfo;
	CInfo(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CInfo)
	enum { IDD = IDD_INFO };
	CListCtrl	m_ctrlListInfo;
	//}}AFX_DATA

public:
	DWORD m_dwRows;
	BOOL  m_bInit;
	CString m_strTemp;
// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CInfo)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CInfo)
	afx_msg void OnRefresh();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_INFO_H__790410AB_7F0A_4383_9344_93A649AF432E__INCLUDED_)
