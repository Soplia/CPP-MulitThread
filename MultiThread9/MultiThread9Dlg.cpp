﻿
// MultiThread9Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MultiThread9.h"
#include "MultiThread9Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CEvent eventWriteD;
wchar_t g_Array[10];
UINT WriteW(LPVOID pParam)
{
	CEdit *pEdit = (CEdit*)pParam;
	pEdit->SetWindowText(L"");
	for (int i = 0; i < 10; i++)
	{
		g_Array[i] = 'W';
		if (i == 10 - 1) { g_Array[10 - 1] = '\0'; }
		pEdit->SetWindowText(g_Array);
		Sleep(1000);
	}
	eventWriteD.SetEvent();
	return 0;

}
UINT WriteD(LPVOID pParam)
{
	CEdit *pEdit = (CEdit*)pParam;
	pEdit->SetWindowText(L"");
	WaitForSingleObject(eventWriteD.m_hObject, INFINITE);
	for (int i = 0; i < 10; i++)
	{
		g_Array[i] = 'D';
		if (i == 10 - 1) { g_Array[10 - 1] = '\0'; }
		pEdit->SetWindowText(g_Array);
		Sleep(1000);
	}
	return 0;

}
// CMultiThread9Dlg 对话框



CMultiThread9Dlg::CMultiThread9Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MULTITHREAD9_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThread9Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_W, m_ctrlW);
	DDX_Control(pDX, IDC_D, m_ctrlD);
}

BEGIN_MESSAGE_MAP(CMultiThread9Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_WRITEW, &CMultiThread9Dlg::OnBnClickedWritew)
END_MESSAGE_MAP()


// CMultiThread9Dlg 消息处理程序

BOOL CMultiThread9Dlg::OnInitDialog()
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

void CMultiThread9Dlg::OnPaint()
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
HCURSOR CMultiThread9Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMultiThread9Dlg::OnBnClickedWritew()
{
	// TODO: 在此添加控件通知处理程序代码
	CWinThread *pWriteW = AfxBeginThread(WriteW,

		&m_ctrlW,

		THREAD_PRIORITY_NORMAL,

		0,

		CREATE_SUSPENDED);

	pWriteW->ResumeThread();



	CWinThread *pWriteD = AfxBeginThread(WriteD,

		&m_ctrlD,

		THREAD_PRIORITY_NORMAL,

		0,

		CREATE_SUSPENDED);

	pWriteD->ResumeThread();
}