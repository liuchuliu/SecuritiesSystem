// FilterDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "FilterDlg.h"
#include "SecuritiesSystem.h"


// FilterDlg 对话框

IMPLEMENT_DYNAMIC(FilterDlg, CDialogEx)

FilterDlg::FilterDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_FilterDlg, pParent)
	, min_price(0.00)
	, max_price(5000.00)
	, min_change(-100.00)
	, max_change(100.00)
	, min_v(0)
	, max_v(100000)
{

}

FilterDlg::~FilterDlg()
{
}

void FilterDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, min_price);
	DDX_Text(pDX, IDC_EDIT1, max_price);
	DDX_Text(pDX, IDC_EDIT4, min_change);
	DDX_Text(pDX, IDC_EDIT3, max_change);
	DDX_Text(pDX, IDC_EDIT5, min_v);
	DDX_Text(pDX, IDC_EDIT6, max_v);
}


BEGIN_MESSAGE_MAP(FilterDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON2, &FilterDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &FilterDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// FilterDlg 消息处理程序


void FilterDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);//返回
}


void FilterDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	if (min_price > max_price || min_change > max_change || min_v > max_v)
	{
		MessageBox(TEXT("存在逻辑错误，请修改"), TEXT("提示"));
	}
	else
	{
		OnOK();//退出本对话框
		return;
	}
}
