
// MultiThread7Dlg.h: 头文件
//

#pragma once

#include "CCalculateThread.h"

#define WM_DISPLAY WM_USER+2

// CMultiThread7Dlg 对话框
class CMultiThread7Dlg : public CDialogEx
{

protected:
	int nAddend;
	LRESULT OnDisplay(WPARAM wParam, LPARAM lParam);

// 构造
public:
	CCalculateThread* m_pCalculateThread;
	CMultiThread7Dlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTITHREAD7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedRadio3();
	afx_msg void OnBnClickedRadio1();
	afx_msg void OnBnClickedRadio2();
	afx_msg void OnBnClickedIgnore();
};
