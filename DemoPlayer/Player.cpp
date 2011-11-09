// Player.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "Player.h"
#include "PlayerDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CPlayerApp

BEGIN_MESSAGE_MAP(CPlayerApp, CWinApp)
	//{{AFX_MSG_MAP(CPlayerApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPlayerApp construction

CPlayerApp::CPlayerApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CPlayerApp object

CPlayerApp theApp;

/////////////////////////////////////////////////////////////////////////////
// CPlayerApp initialization

BOOL CPlayerApp::InitInstance()
{
	AfxEnableControlContainer();

	// Standard initialization
	// If you are not using these features and wish to reduce the size
	//  of your final executable, you should remove from the following
	//  the specific initialization routines you do not need.

	CCommandLineInfo cmdInfo;
	ParseCommandLine(cmdInfo);
	CPlayerDlg dlg;
	dlg.m_strPlayFileName=cmdInfo.m_strFileName;
	TRACE("%s",cmdInfo.m_strFileName);
	cmdInfo.m_nShellCommand = CCommandLineInfo::FileDDE ;
//	if (!ProcessShellCommand(cmdInfo))
 //     return FALSE;

	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();
	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}

	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}

int CPlayerApp::ExitInstance() 
{
	// TODO: Add your specialized code here and/or call the base class
	
	return CWinApp::ExitInstance();
}
