#if !defined(AFX_SEEK_H__82E4B390_2B41_43D7_9D19_5C4939F336BD__INCLUDED_)
#define AFX_SEEK_H__82E4B390_2B41_43D7_9D19_5C4939F336BD__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Seek.h : header file
//
#define WM_SEEKOK WM_USER+34
/////////////////////////////////////////////////////////////////////////////
// CSeek dialog

class CSeek : public CDialog
{
// Construction
public:
	CWnd* m_pParent;
	DWORD m_dwMaxFrameNum;
	DWORD m_dwMaxTime;
	CSeek(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSeek)
	enum { IDD = IDD_SEEK };
	int		m_nSeekType;
	UINT	m_nValue;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSeek)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSeek)
	afx_msg void OnSeek();
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SEEK_H__82E4B390_2B41_43D7_9D19_5C4939F336BD__INCLUDED_)
