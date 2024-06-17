// LLogin.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "LLogin.h"


// LLogin 对话框

IMPLEMENT_DYNAMIC(LLogin, CDialogEx)

LLogin::LLogin(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoginDlg, pParent)
{

}

LLogin::~LLogin()
{
}

void LLogin::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(LLogin, CDialogEx)
	ON_BN_CLICKED(IDOK2, &LLogin::OnBnClickedOk2)
END_MESSAGE_MAP()


// LLogin 消息处理程序


void LLogin::OnBnClickedOk2()
{
	// TODO: 在此添加控件通知处理程序代码,注册
}
