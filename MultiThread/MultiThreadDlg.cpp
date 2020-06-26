// MultiThreadDlg.cpp: 实现文件
//
#include "stdafx.h"
#include "MultiThread.h"
#include "MultiThreadDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 声明全局变量
volatile BOOL m_bRun;
// 线程函数定义
void ThreadFunc()
{
	CTime time;
	CString strTime;
	m_bRun = TRUE;
	while (m_bRun)
	{
		time = CTime::GetCurrentTime();
		strTime = time.Format("%H:%M:%S");
		::SetDlgItemText(AfxGetApp()->m_pMainWnd->m_hWnd, IDC_TIME, strTime);
		Sleep(1000);
	}
}

// CMultiThreadDlg 对话框
CMultiThreadDlg::CMultiThreadDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MULTITHREAD_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThreadDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CMultiThreadDlg, CDialogEx)
	ON_WM_PAINT() 
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDCANCEL, &CMultiThreadDlg::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_START, &CMultiThreadDlg::OnBnClickedStart)
	ON_BN_CLICKED(IDC_STOP, &CMultiThreadDlg::OnBnClickedStop)
END_MESSAGE_MAP()


// CMultiThreadDlg 消息处理程序
BOOL CMultiThreadDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CMultiThreadDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMultiThreadDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CMultiThreadDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	CDialogEx::OnCancel();
}


void CMultiThreadDlg::OnEnChangeEdit1()
{
	// TODO:  如果该控件是 RICHEDIT 控件，它将不
	// 发送此通知，除非重写 CDialogEx::OnInitDialog()
	// 函数并调用 CRichEditCtrl().SetEventMask()，
	// 同时将 ENM_CHANGE 标志“或”运算到掩码中。

	// TODO:  在此添加控件通知处理程序代码
}


void CMultiThreadDlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	hThread = CreateThread(NULL, 0,
		(LPTHREAD_START_ROUTINE)ThreadFunc,
		NULL, 0, &ThreadID);
	GetDlgItem(IDC_START)->EnableWindow(FALSE);
	GetDlgItem(IDC_STOP)->EnableWindow(TRUE);
}


void CMultiThreadDlg::OnBnClickedStop()
{
	// TODO: 在此添加控件通知处理程序代码
	m_bRun = FALSE;
	GetDlgItem(IDC_START)->EnableWindow(TRUE);
	GetDlgItem(IDC_STOP)->EnableWindow(FALSE);
}
