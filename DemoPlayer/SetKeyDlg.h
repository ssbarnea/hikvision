/////////////////////////////////////////////////////////////////////////////////////
// CSetKeyDlg.h : header file
/////////////////////////////////////////////////////////////////////////////////////


#if !defined(AFX_PLAYERDLG_H__BC7E7078_7E67_40B3_85A4_591E51BB1ABB__INCLUDED_)
#define AFX_PLAYERDLG_H__BC7E7078_7E67_40B3_85A4_591E51BB1ABB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CSetKeyDlg : public CDialog
{
// Construction
public:
	CSetKeyDlg(LONG lPort, CWnd* pParent = NULL);
	CSetKeyDlg(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CSetKeyDlg)
	enum { IDD = IDD_SET_KEY };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSetKeyDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CSetKeyDlg)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	int CheckKey(PSTR szKey);
	void HexToASCII(PSTR szKey);

private:
	LONG m_lPort;
};

#endif //#if !defined(AFX_PLAYERDLG_H__BC7E7078_7E67_40B3_85A4_591E51BB1ABB__INCLUDED_)
