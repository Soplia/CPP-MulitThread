#pragma once
#include <afxwin.h>
#include "CUIThreadDlg.h"

class CUIThread :
	public CWinThread
{
	DECLARE_DYNCREATE(CUIThread)
public:
	CUIThread();
	virtual ~CUIThread();
	virtual BOOL InitInstance();
	virtual int ExitInstance();
	CUIThreadDlg m_dlg;
	DECLARE_MESSAGE_MAP()
};

