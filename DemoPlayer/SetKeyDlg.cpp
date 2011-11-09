/////////////////////////////////////////////////////////////////////////////
// SetKeyDlg.cpp

#include "stdafx.h"
#include "player.h"
#include "SetKeyDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

CSetKeyDlg::CSetKeyDlg(LONG lPort, CWnd* pParent /* = NULL */)
	: CDialog(CSetKeyDlg::IDD, pParent)
	, m_lPort(lPort)
{

}

CSetKeyDlg::CSetKeyDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CSetKeyDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CSetKeyDlg)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

void CSetKeyDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CSetKeyDlg)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CSetKeyDlg, CDialog)
	//{{AFX_MSG_MAP(CSetKeyDlg)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CSetKeyDlg message handlers

BOOL CSetKeyDlg::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	CComboBox *pCombo = (CComboBox*)GetDlgItem(IDC_CB_FORMAT);
	pCombo->AddString(_T("AES"));
	pCombo->SetCurSel(0);

	pCombo = (CComboBox*)GetDlgItem(IDC_CB_LENGTH);
	pCombo->AddString(_T("128"));
	pCombo->SetCurSel(0);

	CButton *pRad = (CButton*)GetDlgItem(IDC_RAD_ASCII);
	pRad->SetCheck(BST_CHECKED);
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CSetKeyDlg::OnOK() 
{
	// TODO: Add extra validation here
	char cKey[256] = {0};
	GetDlgItem(IDC_EDT_KEY)->GetWindowText(cKey, 256);

	int iRet = CheckKey(cKey);
	if (0 == iRet)
	{
		MessageBox("The length of key is not correct!", "Error", MB_ICONWARNING);
		return;
	}
	else if (-1 == iRet)
	{
		MessageBox("The word input is in wrong format!", "Error", MB_ICONWARNING);
		return;
	}

	if (NAME(PlayM4_SetSecretKey(m_lPort, 1, cKey, 128)))
	{
		MessageBox("Secret key set succeed!", "Success", MB_ICONINFORMATION);
	}
	else
	{
		MessageBox("Secret key set failed!", "Failed", MB_ICONINFORMATION);
		return;
	}
	
	CDialog::OnOK();
}

int CSetKeyDlg::CheckKey(PSTR szKey)
{
	int iLength = strlen(szKey);
	BOOL bASCII = TRUE;

	CButton *pRad = (CButton*)GetDlgItem(IDC_RAD_ASCII);
	if (BST_CHECKED != pRad->GetCheck())	//16进制模式
	{
		bASCII = FALSE;
	}

	CComboBox* pCombo = (CComboBox*)GetDlgItem(IDC_CB_LENGTH); 
	int iCurSel = pCombo->GetCurSel();
	if (0 == iCurSel)	//检查密钥长度，目前只支持128位模式
	{
		if (bASCII && iLength != 16 || !bASCII && iLength != 32)
		{
			return 0;
		}
	}
	else
	{
		return 0;
	}

	//如果由16进制输入则需要判断输入是否合法
	if (!bASCII)
	{
		CopyMemory(szKey, _strupr(szKey), iLength);
		int i = 0;

		for (i = 0; i < iLength; i++)
		{
			if (szKey[i] >= 'A' && szKey[i] <= 'F' || szKey[i] >= '0' && szKey[i] <= '9')
			{
				continue;
			}
			
			break;
		}

		if (i != iLength)	//输入非法
		{
			return -1;
		}

		HexToASCII(szKey);
	}

	return 1;
}

void CSetKeyDlg::HexToASCII(PSTR szKey)
{
	for (int i = 0; i < 32; i += 2)
	{
		if (szKey[i] >= 65)		//将字母转化为对应的16进制数值
		{
			szKey[i] -= 55;
		}
		else					//将数字转化为对应的16进制数值
		{
			szKey[i] -= 48;
		}

		if (szKey[i + 1] >= 65)
		{
			szKey[i + 1] -= 55;
		}
		else
		{
			szKey[i + 1] -= 48;
		}

		szKey[i / 2] = szKey[i] << 4 | szKey[i + 1]; //Hex下两个字符表示ASCII下一个字符
	}
}