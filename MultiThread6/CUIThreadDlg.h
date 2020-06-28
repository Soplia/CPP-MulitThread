#pragma once
#include <afxwin.h>
class CUIThreadDlg :
	public CDialog
{
public:
	CUIThreadDlg();
	~CUIThreadDlg();
	DECLARE_MESSAGE_MAP()
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
};

