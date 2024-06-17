// HistDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "HistDlg.h"


// HistDlg 对话框

IMPLEMENT_DYNAMIC(HistDlg, CDialogEx)

HistDlg::HistDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HistDlg, pParent)
{

}

HistDlg::~HistDlg()
{
}

void HistDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(HistDlg, CDialogEx)
END_MESSAGE_MAP()


// HistDlg 消息处理程序
