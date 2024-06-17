// HisDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "HisDlg.h"
#include "SecuritiesSystem.h"

// HisDlg 对话框

IMPLEMENT_DYNAMIC(HisDlg, CDialogEx)

HisDlg::HisDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_HisDlg, pParent)
{

}

HisDlg::~HisDlg()
{
}

void HisDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_pic);
}


BEGIN_MESSAGE_MAP(HisDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &HisDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// HisDlg 消息处理程序


void HisDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CImage cim;
	cim.Load(_T(".\\1.png"));
	HBITMAP hbmp = cim.Detach();
	m_pic.SetBitmap(hbmp);
	m_pic.SetWindowPos(NULL, 0, 0, 800, 400, SWP_NOZORDER);
}
