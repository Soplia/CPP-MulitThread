#include "stdafx.h"
#include "CCalculateThread.h"
#include "MultiThread7Dlg.h"

BOOL CCalculateThread::InitInstance()
{
	
	// TODO:  perform and per-thread initialization here   
	return TRUE;
}

int CCalculateThread::ExitInstance()
{
	// TODO:  perform any per-thread cleanup here   
	return CWinThread::ExitInstance();
}

BEGIN_MESSAGE_MAP(CCalculateThread, CWinThread)
	ON_THREAD_MESSAGE(WM_CALCULATE, OnCalculate)
END_MESSAGE_MAP()

void CCalculateThread::OnCalculate(UINT wParam, LONG lParam)
{
	int nTmpt = 0;
	for (int i = 0; i <= (int)wParam; i++)
	{
		nTmpt = nTmpt + i;
	}
	
	Sleep(500);
	::PostMessage((HWND)(GetMainWnd()->GetSafeHwnd()), WM_DISPLAY, nTmpt, NULL);
	//return 0;
}
CCalculateThread::CCalculateThread()
{
}


CCalculateThread::~CCalculateThread()
{
}
