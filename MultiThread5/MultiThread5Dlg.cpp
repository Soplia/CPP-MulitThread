﻿
// MultiThread5Dlg.cpp: 实现文件
//

#include "stdafx.h"
#include "MultiThread5.h"
#include "MultiThread5Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

threadInfo Info;
UINT ThreadFunc(LPVOID lpParam)
{
	threadInfo* pInfo = (threadInfo*)lpParam;
	for (int i = 0; i < 100; i++)
	{
		int nTemp = pInfo->nMilliSecond;
		pInfo->pctrlProgress->SetPos(i);
		Sleep(nTemp);
	}
	return 0;
}
// CMultiThread5Dlg 对话框
CMultiThread5Dlg::CMultiThread5Dlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MULTITHREAD5_DIALOG, pParent)
	, m_nMilliSecond(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMultiThread5Dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PROGRESS1, m_ctrlProgress);
	DDX_Text(pDX, IDC_MILLISECOND, m_nMilliSecond);
}

BEGIN_MESSAGE_MAP(CMultiThread5Dlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_START, &CMultiThread5Dlg::OnBnClickedStart)
END_MESSAGE_MAP()


// CMultiThread5Dlg 消息处理程序

BOOL CMultiThread5Dlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	m_ctrlProgress.SetRange(0, 99);
	m_nMilliSecond = 20;
	UpdateData(FALSE);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMultiThread5Dlg::OnPaint()
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
HCURSOR CMultiThread5Dlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMultiThread5Dlg::OnBnClickedStart()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	Info.nMilliSecond = m_nMilliSecond;
	Info.pctrlProgress = &m_ctrlProgress;
	pThread = AfxBeginThread(ThreadFunc, &Info);
}
