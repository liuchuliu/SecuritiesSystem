// MarketDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "MarketDlg.h"
#include "SecuritiesSystem.h"

// MarketDlg 对话框

IMPLEMENT_DYNAMIC(MarketDlg, CDialogEx)

MarketDlg::MarketDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MarketDlg, pParent)
{

}

MarketDlg::~MarketDlg()
{
}

void MarketDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST2, mar_list);
}


BEGIN_MESSAGE_MAP(MarketDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON13, &MarketDlg::OnBnClickedButton13)
	ON_BN_CLICKED(IDC_BUTTON6, &MarketDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON14, &MarketDlg::OnBnClickedButton14)
	ON_BN_CLICKED(IDC_BUTTON1, &MarketDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON12, &MarketDlg::OnBnClickedButton12)
END_MESSAGE_MAP()


// MarketDlg 消息处理程序



BOOL MarketDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = mar_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//高亮
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线 
	mar_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	mar_list.InsertColumn(0, TEXT("证券代码"), 0, 110);
	mar_list.InsertColumn(1, TEXT("证券名称"), 0, 110);
	mar_list.InsertColumn(2, TEXT("当前价格($)"), 0, 110);
	mar_list.InsertColumn(3, TEXT("跌涨幅(%)"), 0, 110);
	mar_list.InsertColumn(4, TEXT("成交量(万股)"), 0, 110);
	
	UpdateList();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void MarketDlg::UpdateList()
{
	//mar_list.DeleteAllItems();
	Datainterface.MarketTrend();
	CString str;
	for (int i = 0; i < Datainterface.stocks.size(); i++)
	{
		mar_list.InsertItem(i, Datainterface.stocks[i].symbol.c_str());
		mar_list.SetItemText(i, 1, Datainterface.stocks[i].name.c_str());
		str.Format(TEXT("%2f"), Datainterface.stocks[i].price);
		mar_list.SetItemText(i, 2, str);
		str.Format(TEXT("%2f"), Datainterface.stocks[i].changePercentage);
		mar_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), Datainterface.stocks[i].volume);
		mar_list.SetItemText(i, 4, str);

	}
}


void MarketDlg::OnBnClickedButton13()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	str.Format(TEXT("%s"), "今日市场总体呈现上涨趋势，其中科技板块表现尤为强劲。市场活跃度适中，投资者情绪偏向乐观。");
	MessageBox(str, TEXT("市场总体表现"));
}


void MarketDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);//返回
}


void MarketDlg::OnBnClickedButton14()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	str.Format(TEXT("%s"), "市场整体情绪偏向乐观，科技股的表现尤为突出。然而，投资者仍需注意市场的波动性和不确定性，合理配置资产以降低风险。");
	MessageBox(str, TEXT("市场整体情绪"));
}


void MarketDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	str.Format(TEXT("%s"), "从上述数据中可以看出，科技股整体表现良好，尤其是微软、阿里巴巴、京东和腾讯。这些公司的股价均有所上涨，显示出投资者对科技行业的青睐。");
	MessageBox(str, TEXT("市场趋势"));
}


void MarketDlg::OnBnClickedButton12()
{
	// TODO: 在此添加控件通知处理程序代码
	CString str;
	str.Format(TEXT("%s"), "微软和京东的交易量较大，显示出投资者对这些公司的兴趣较高。而谷歌的交易量较低，可能表明市场对其短期走势持观望态度。");
	MessageBox(str, TEXT("交易量变化"));
}
