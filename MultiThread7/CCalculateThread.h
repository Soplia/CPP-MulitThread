#pragma once
#include <afxwin.h>

#define WM_CALCULATE WM_USER+1 

class CCalculateThread :
	public CWinThread
{
	//DECLARE_DYNCREATE(CCalculateThread)
public:
	CCalculateThread();
	~CCalculateThread();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	DECLARE_MESSAGE_MAP()
protected:
	afx_msg void OnCalculate(UINT wParam, LONG lParam);
};

