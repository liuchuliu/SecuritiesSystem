// ZhuceDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "ZhuceDlg.h"
#include "resource.h"



// ZhuceDlg 对话框

IMPLEMENT_DYNAMIC(ZhuceDlg, CDialogEx)

ZhuceDlg::ZhuceDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ZhuceDlg, pParent)
	, z_username(_T(""))
	, z_password(_T(""))
	, sure_password(_T(""))
	, z_email(_T(""))
{

}

ZhuceDlg::~ZhuceDlg()
{
}

void ZhuceDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, z_username);
	DDX_Text(pDX, IDC_EDIT2, z_password);
	DDX_Text(pDX, IDC_EDIT3, sure_password);
	DDX_Text(pDX, IDC_EDIT4, z_email);
}


BEGIN_MESSAGE_MAP(ZhuceDlg, CDialogEx)
	ON_BN_CLICKED(IDOK, &ZhuceDlg::OnBnClickedOk)
END_MESSAGE_MAP()


// ZhuceDlg 消息处理程序


void ZhuceDlg::OnBnClickedOk()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (z_username == TEXT("") || z_password == TEXT("") || z_email == TEXT("") || sure_password == TEXT(""))
	{
		MessageBox(TEXT("存在输入空，请补充"), TEXT("提示"));
	}
	else if (z_password != sure_password)
	{
		MessageBox(TEXT("密码确认失败，请修改"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}
