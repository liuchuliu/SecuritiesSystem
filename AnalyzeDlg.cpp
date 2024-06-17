// AnalyzeDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "AnalyzeDlg.h"
#include "SecuritiesSystem.h"


// AnalyzeDlg 对话框

IMPLEMENT_DYNAMIC(AnalyzeDlg, CDialogEx)

AnalyzeDlg::AnalyzeDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_AnalyzeDlg, pParent)
{

}

AnalyzeDlg::~AnalyzeDlg()
{
}

void AnalyzeDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, a_list);
}

void AnalyzeDlg::UpdateList()
{
	Datainterface.Analyze();
	//mar_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Datainterface.stocks.size(); i++)
	{
		a_list.InsertItem(i, Datainterface.stocks[i].symbol.c_str());
		a_list.SetItemText(i, 1, Datainterface.stocks[i].name.c_str());
		str.Format(TEXT("%2f"), Datainterface.stocks[i].price);
		a_list.SetItemText(i, 2, str);
		str.Format(TEXT("%2f"), Datainterface.stocks[i].changePercentage);
		a_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), Datainterface.stocks[i].volume);
		a_list.SetItemText(i, 4, str);

	}
}


BEGIN_MESSAGE_MAP(AnalyzeDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &AnalyzeDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &AnalyzeDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// AnalyzeDlg 消息处理程序


BOOL AnalyzeDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = a_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//高亮
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线 
	a_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	a_list.InsertColumn(0, TEXT("证券代码"), 0, 110);
	a_list.InsertColumn(1, TEXT("证券名称"), 0, 110);
	a_list.InsertColumn(2, TEXT("当前价格($)"), 0, 110);
	a_list.InsertColumn(3, TEXT("跌涨幅(%)"), 0, 110);
	a_list.InsertColumn(4, TEXT("成交量(万股)"), 0, 110);

	UpdateList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}


void AnalyzeDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	int index = a_list.GetSelectionMark();
	if (index > -1)
	{
		UINT i;
		string str;
		i = MessageBox(_T("确定查看此股票的分析吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
		if (i == IDYES)
		{
			str = Datainterface.SelectStock(index);
			MessageBox(str.c_str(), TEXT("提示"));
		}
		else
		{
			return;
		}
	}
	else
	{
		MessageBox(TEXT("请先选择欲分析的股票"), TEXT("提示"));
	}
}


void AnalyzeDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);//返回
}
