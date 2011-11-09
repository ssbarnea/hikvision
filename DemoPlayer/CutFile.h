#if !defined(AFX_CUTFILE_H__B01A7B05_EE58_496E_BB87_98764D1661F3__INCLUDED_)
#define AFX_CUTFILE_H__B01A7B05_EE58_496E_BB87_98764D1661F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// CutFile.h : header file
//
#include "player.h"
/////////////////////////////////////////////////////////////////////////////
// CCutFile dialog

class CCutFile : public CDialog
{
// Construction
public:
	DWORD		m_dwMaxFrameNum;
	DWORD		m_dwMaxTime;
	HANDLE		m_hPlayFile;
	CString		m_strPlayFileName;
	FRAME_POS	m_stRealBegin;
	FRAME_POS	m_stRealEnd;

	BOOL SetFileName(CString csName);
	BOOL CheckValue();

	CCutFile(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CCutFile)
	enum { IDD = IDD_CUTFILE };
	UINT	m_nBegin;
	int		m_nType;
	UINT	m_nEnd;
	CString	m_strSaveFileName;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CCutFile)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CCutFile)
	afx_msg void OnViewNotification();
	afx_msg BOOL OnView();
	afx_msg void OnSave();
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CUTFILE_H__B01A7B05_EE58_496E_BB87_98764D1661F3__INCLUDED_)
