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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
	CString msg = CString("�����ڵ�ͨ��!");
	AfxMessageBox(msg);
	CDialog::OnLButtonDown(nFlags, point);
}
