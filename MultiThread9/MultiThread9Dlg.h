
// MultiThread9Dlg.h: 头文件
//

#pragma once

UINT WriteW(LPVOID pParam);
UINT WriteD(LPVOID pParam);
// CMultiThread9Dlg 对话框
class CMultiThread9Dlg : public CDialogEx
{
// 构造
public:
	CMultiThread9Dlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MULTITHREAD9_DIALOG };
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
	CEdit m_ctrlW;
	CEdit m_ctrlD;
	afx_msg void OnBnClickedWritew();
};
