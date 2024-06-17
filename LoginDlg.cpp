// LoginDlg.cpp: 实现文件
//

#include "pch.h"
#include "SecuritiesSystem.h"
#include "afxdialogex.h"
#include "LoginDlg.h"




// LoginDlg 对话框

IMPLEMENT_DYNAMIC(LoginDlg, CDialogEx)

LoginDlg::LoginDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_LoginDlg, pParent)
	, username(_T(""))
	, password(_T(""))
	, email(_T(""))
{

}

LoginDlg::~LoginDlg()
{
}

void LoginDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, username);
	DDX_Text(pDX, IDC_EDIT2, password);
	DDX_Text(pDX, IDC_EDIT3, email);
}


BEGIN_MESSAGE_MAP(LoginDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &LoginDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// LoginDlg 消息处理程序


void LoginDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (username == TEXT("") || password == TEXT("") || email == TEXT(""))
	{
		MessageBox(TEXT("存在输入空，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}
