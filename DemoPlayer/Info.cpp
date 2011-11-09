// Info.cpp : implementation file
//

#include "stdafx.h"
#include "player.h"
#include "Info.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

extern  LONG m_lPort;
/////////////////////////////////////////////////////////////////////////////
// CInfo dialog


CInfo::CInfo(CWnd* pParent /*=NULL*/)
	: CDialog(CInfo::IDD, pParent)
{
	//{{AFX_DATA_INIT(CInfo)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
	m_dwRows = 0;
	m_bInit = FALSE;
	m_strTemp  = _T(""); 
}


void CInfo::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CInfo)
	DDX_Control(pDX, IDC_LIST_INFO, m_ctrlListInfo);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CInfo, CDialog)
	//{{AFX_MSG_MAP(CInfo)
	ON_BN_CLICKED(IDC_REFRESH, OnRefresh)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CInfo message handlers

void CInfo::OnRefresh() 
{
	// TODO: Add your control notification handler code here
	int nRows = m_dwRows;

		//invalid after play()
	BOOL bOverlay=NAME(PlayM4_GetOverlayMode)(m_lPort);
	if(!m_bInit)
	{
		m_strTemp.Format("Is OVERLAY Surface");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}

	if(bOverlay)
	{
		m_strTemp.Format("yes   The color key:0x%X",NAME(PlayM4_GetColorKey)(m_lPort));
	}
	else
	{
		m_strTemp.Format("No");
	}

	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Max display buffers(frame)");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}

	m_strTemp.Format("%d",NAME(PlayM4_GetDisplayBuf)(m_lPort));
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Volume");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	m_strTemp.Format("%x",NAME(PlayM4_GetVolume)(m_lPort));
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Image qulity");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}

	BOOL bHiQuality=FALSE;
	NAME(PlayM4_GetPictureQuality)(m_lPort,&bHiQuality);
	if(bHiQuality)
	{
		m_strTemp="High";
	}
	else
	{
		m_strTemp="Low";
	}
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("TIMER");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	DWORD nTimer;
	NAME(PlayM4_GetTimerType)(m_lPort,&nTimer,NULL);
	if(nTimer==TIMER_1)
	{
		m_strTemp="TIMER_1";
	}
	else
	{
		m_strTemp="TIMER_2";
	}
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	DWORD nVideoRender =NAME(PlayM4_GetBufferValue)(m_lPort,BUF_VIDEO_RENDER);
	DWORD nAudioRender =NAME(PlayM4_GetBufferValue)(m_lPort,BUF_AUDIO_RENDER);
	DWORD nVideoSource =NAME(PlayM4_GetBufferValue)(m_lPort,BUF_VIDEO_SRC);
	DWORD nAudioSource =NAME(PlayM4_GetBufferValue)(m_lPort,BUF_AUDIO_SRC);
	
	if(!m_bInit)
	{
		m_strTemp.Format("Video render frames");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	m_strTemp.Format("%d",nVideoRender);
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Audio render frames");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	m_strTemp.Format("%d",nAudioRender);
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Video Source size");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	m_strTemp.Format("%d",nVideoSource);
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;

	if(!m_bInit)
	{
		m_strTemp.Format("Audio Source size");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, nRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
	}
	m_strTemp.Format("%d",nAudioSource);
	m_ctrlListInfo.SetItemText(nRows,1,m_strTemp);
	nRows ++;
}

BOOL CInfo::OnInitDialog() 
{
	CDialog::OnInitDialog();
	
	// TODO: Add extra initialization here
	//m_ListCtrl
	m_ctrlListInfo.InsertColumn(0, "Description", LVCFMT_LEFT, 200);
	m_ctrlListInfo.InsertColumn(1, "value", LVCFMT_LEFT, 150);			
	m_ctrlListInfo.SetExtendedStyle(LVS_EX_FULLROWSELECT);


#if (WINVER > 0x0400)
	//If only one adapter ,the return value is 0;
	DWORD nVal=NAME(PlayM4_GetDDrawDeviceTotalNums)();
	if(nVal>=1)
	{
		m_strTemp.Format("Video adaper numbers");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, m_dwRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
		m_strTemp.Format("%d", nVal);
		m_ctrlListInfo.SetItemText(m_dwRows,1,m_strTemp);
		m_dwRows ++;

		for(DWORD nCount=1;nCount<=nVal;nCount++) 
		{
			DWORD nNameLen = 50;
			char pDriverDesp[50];
			char pDriverName[50];
			ZeroMemory(pDriverDesp, nNameLen);
			ZeroMemory(pDriverName, nNameLen);
			HMONITOR hMonitor;
			NAME(PlayM4_GetDDrawDeviceInfo)(nCount,pDriverDesp,nNameLen,pDriverName,nNameLen,&hMonitor);
			m_strTemp.Format("----Adatper<%d>", nCount-1);
			m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, m_dwRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
			m_ctrlListInfo.SetItemText(m_dwRows,1,pDriverDesp);
			m_dwRows ++;

			m_strTemp.Format("----Driver<%d>", nCount-1);
			m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, m_dwRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
			m_ctrlListInfo.SetItemText(m_dwRows,1,pDriverName);
			m_dwRows ++;
		}
	}
	else
	{
		m_strTemp.Format("Only one video adapter");
		m_ctrlListInfo.InsertItem(LVIF_TEXT|LVIF_STATE, m_dwRows, m_strTemp, LVIS_SELECTED|LVIS_FOCUSED, LVIS_SELECTED|LVIS_FOCUSED, 0, 0);
		m_ctrlListInfo.SetItemText(m_dwRows,1,"none");
		m_dwRows ++;
	}
#endif

	OnRefresh();

	m_bInit = TRUE;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}
