// AmendDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "SecuritiesSystem.h"
#include "AmendDlg.h"


// AmendDlg 对话框

IMPLEMENT_DYNAMIC(AmendDlg, CDialogEx)

AmendDlg::AmendDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AmendDlg, pParent)
	, ch_username(_T(""))
	, ch_password(_T(""))
	, ch_email(_T(""))
{

}

AmendDlg::~AmendDlg()
{
}

void AmendDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT3, ch_username);
	DDX_Text(pDX, IDC_EDIT2, ch_password);
	DDX_Text(pDX, IDC_EDIT4, ch_email);
}


BEGIN_MESSAGE_MAP(AmendDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &AmendDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &AmendDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// AmendDlg 消息处理程序


void AmendDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (ch_username == TEXT("") || ch_password == TEXT("") || ch_email == TEXT(""))
	{
		MessageBox(TEXT("存在输入空，请补充"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}


void AmendDlg::OnBnClickedCancel()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);//返回
}
