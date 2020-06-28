#include "stdafx.h"
#include "CUIThreadDlg.h"

CUIThreadDlg::CUIThreadDlg()
{
}

CUIThreadDlg::~CUIThreadDlg()
{
}

BEGIN_MESSAGE_MAP(CUIThreadDlg, CDialog)
	ON_WM_LBUTTONDOWN()
END_MESSAGE_MAP()


void CUIThreadDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	CString msg = CString("我终于调通了!");
	AfxMessageBox(msg);
	CDialog::OnLButtonDown(nFlags, point);
}
