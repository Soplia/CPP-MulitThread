#include "stdafx.h"
#include "CUIThread.h"
#include "resource.h"


IMPLEMENT_DYNCREATE(CUIThread, CWinThread)
BEGIN_MESSAGE_MAP(CUIThread, CWinThread)
	//{{AFX_MSG_MAP(CUIThread)
	// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

BOOL CUIThread::InitInstance()
{
	m_dlg.Create(IDD_UITHREADDLG);
	m_dlg.ShowWindow(SW_SHOW);
	m_pMainWnd = &m_dlg;
	return TRUE;
}

int CUIThread::ExitInstance()
{
	m_dlg.DestroyWindow();
	return CWinThread::ExitInstance();
}

CUIThread::CUIThread()
{
}


CUIThread::~CUIThread()
{
}
