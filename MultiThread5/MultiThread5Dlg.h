
// MultiThread5Dlg.h: 头文件
//

#pragma once
struct threadInfo
{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;
};
UINT ThreadFunc(LPVOID lpParam);

// CMultiThread5Dlg 对话框
class CMultiThread5Dlg : public CDialogEx
{
protected:
	CWinThread* pThread;
// 构造
public:
	CMultiThread5Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTITHREAD5_DIALOG };
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
	CProgressCtrl m_ctrlProgress;
	int m_nMilliSecond;
	afx_msg void OnBnClickedStart();
};
