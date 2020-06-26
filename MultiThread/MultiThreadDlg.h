
// MultiThreadDlg.h: 头文件
//

#pragma once


// CMultiThreadDlg 对话框
class CMultiThreadDlg : public CDialogEx
{
// 构造
public:
	CMultiThreadDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTITHREAD_DIALOG };
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
	afx_msg void OnBnClickedCancel();
	afx_msg void OnEnChangeEdit1();
 
//多线程处理
protected:
	HANDLE hThread;
	DWORD ThreadID;
public:
	afx_msg void OnBnClickedStart();
	afx_msg void OnBnClickedStop();
};

//线程函数声明
void ThreadFunc();