
// MultiThread3Dlg.h: 头文件
//

#pragma once
struct threadInfo
{
	UINT nMilliSecond;
	CProgressCtrl* pctrlProgress;
};
UINT ThreadFunc(LPVOID lpParam);

// CMultiThread3Dlg 对话框
class CMultiThread3Dlg : public CDialogEx
{

protected:
	HANDLE hThread;
	DWORD ThreadID;

// 构造
public:
	CMultiThread3Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTITHREAD3_DIALOG };
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
	afx_msg void OnEnChangeMillisecond();
	CProgressCtrl m_ctrlProgress;
	afx_msg void OnBnClickedStart();
	int m_nMilliSecond;
};
