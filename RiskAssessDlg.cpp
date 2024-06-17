// RiskAssessDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "RiskAssessDlg.h"
#include "SecuritiesSystem.h"

// RiskAssessDlg 对话框

IMPLEMENT_DYNAMIC(RiskAssessDlg, CDialogEx)

RiskAssessDlg::RiskAssessDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_RiskAssessDlg, pParent)
{

}

RiskAssessDlg::~RiskAssessDlg()
{
}

void RiskAssessDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, r_list);
}


BEGIN_MESSAGE_MAP(RiskAssessDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &RiskAssessDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &RiskAssessDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// RiskAssessDlg 消息处理程序


BOOL RiskAssessDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = r_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//高亮
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线 
	r_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	r_list.InsertColumn(0, TEXT("证券代码"), 0, 110);
	r_list.InsertColumn(1, TEXT("证券名称"), 0, 110);
	r_list.InsertColumn(2, TEXT("当前价格($)"), 0, 110);
	r_list.InsertColumn(3, TEXT("跌涨幅(%)"), 0, 110);
	r_list.InsertColumn(4, TEXT("成交量(万股)"), 0, 110);
	UpdateList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void RiskAssessDlg::UpdateList()
{
	Datainterface.Analyze();
	CString str;
	for (int i = 0; i < Datainterface.stocks.size(); i++)
	{
		r_list.InsertItem(i, Datainterface.stocks[i].symbol.c_str());
		r_list.SetItemText(i, 1, Datainterface.stocks[i].name.c_str());
		str.Format(TEXT("%2f"), Datainterface.stocks[i].price);
		r_list.SetItemText(i, 2, str);
		str.Format(TEXT("%2f"), Datainterface.stocks[i].changePercentage);
		r_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), Datainterface.stocks[i].volume);
		r_list.SetItemText(i, 4, str);

	}
}


void RiskAssessDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int i = r_list.GetSelectionMark();
	vector<double> C = Datainterface.Volatility();
	vector<double> D = Datainterface.MaxDrawdown();
	if (i > -1)
	{
		UINT ii;
		CString str;
		string s1, s2;
		ii = MessageBox(_T("确定查看此股票的评估吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (ii == IDYES)
		{
			switch (int(C[i])/10)
			{
			case 0: s1 = "风险较低，收益相对稳定"; break;
			case 1: s1 = "风险适中，既有一定的收益潜力，又相对较为稳定"; break;
			default: s1 = "风险较高，价格波动较大，收益不稳定"; break;
			}
			switch (int(D[i]) / 10)
			{
			case 0: s2 = "市场下跌时回撤幅度较小，能够较好地保护投资者的本金"; break;
			case 1: s2 = "市场下跌时可能会有一定的回撤，但通常不会对投资者造成过大的损失"; break;
			default: s2 = "风险较高，价格波动较大，收益不稳定"; break;
			}
			str.Format(TEXT("波动率：%2f\n\t%s\n最大回撤：%2f\n\t%s"), C[i], s1.c_str(), D[i], s2.c_str());
			MessageBox(str, TEXT("股票风险评估"));
		}
		else
		{
			return;
		}
	}
	else
	{
		MessageBox(TEXT("请先选择欲评估的股票"), TEXT("提示"));
	}
}


void RiskAssessDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);//返回
}
