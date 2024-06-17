// TradingSimDlg.cpp: 实现文件
//

#include "pch.h"
#include "afxdialogex.h"
#include "TradingSimDlg.h"
#include "SecuritiesSystem.h"

// TradingSimDlg 对话框

IMPLEMENT_DYNAMIC(TradingSimDlg, CDialogEx)

TradingSimDlg::TradingSimDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_TradingSimDlg, pParent)
	, in(_T(""))
	, out(_T(""))
{

}

TradingSimDlg::~TradingSimDlg()
{
}

void TradingSimDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, t_list);
	DDX_Text(pDX, IDC_EDIT1, in);
	DDX_Text(pDX, IDC_EDIT2, out);
}


BEGIN_MESSAGE_MAP(TradingSimDlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &TradingSimDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &TradingSimDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &TradingSimDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// TradingSimDlg 消息处理程序


BOOL TradingSimDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	DWORD dwStyle = t_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//高亮
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线 
	t_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	t_list.InsertColumn(0, TEXT("证券代码"), 0, 110);
	t_list.InsertColumn(1, TEXT("证券名称"), 0, 110);
	t_list.InsertColumn(2, TEXT("当前价格($)"), 0, 110);
	t_list.InsertColumn(3, TEXT("跌涨幅(%)"), 0, 110);
	t_list.InsertColumn(4, TEXT("成交量(万股)"), 0, 110);
	CString FilePath = _T(".\\Stocks.txt");
	ifstream in(FilePath, ios::in);
	if (in.is_open())
	{
		int sum;
		in >> sum;
		for (int j = 0; j < sum; j++)
		{
			CSecurity sttocks;
			sttocks.Load(in);
			Datainterface.stocks.push_back(sttocks);
		}
	}
	UpdateList();
	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

void TradingSimDlg::UpdateList()
{
	t_list.DeleteAllItems();
	CString str;
	for (int i = 0; i < Datainterface.stocks.size(); i++)
	{
		t_list.InsertItem(i, Datainterface.stocks[i].symbol.c_str());
		t_list.SetItemText(i, 1, Datainterface.stocks[i].name.c_str());
		str.Format(TEXT("%2f"), Datainterface.stocks[i].price);
		t_list.SetItemText(i, 2, str);
		str.Format(TEXT("%2f"), Datainterface.stocks[i].changePercentage);
		t_list.SetItemText(i, 3, str);
		str.Format(TEXT("%d"), Datainterface.stocks[i].volume);
		t_list.SetItemText(i, 4, str);

	}
}


void TradingSimDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int index = t_list.GetSelectionMark();
	if (index > -1)
	{
		if (in == TEXT(""))
		{
			MessageBox(TEXT("请填写买入股数"), TEXT("提示"));
		}
		else
		{
			UINT i;
			string str;

			i = MessageBox(_T("确定买入此股票吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				Datainterface.stocks[index].volume += atoi(in);
				CString FilePath = _T(".\\Stocks.txt");
				ofstream outt(FilePath, ios::out);
				if (outt.is_open())
				{
					outt << Datainterface.stocks.size() << endl;
					for (int i = 0; i < Datainterface.stocks.size(); i++)
					{
						outt << Datainterface.stocks[i].symbol << "\t" << Datainterface.stocks[i].name << "\t" << Datainterface.stocks[i].price << "\t" << Datainterface.stocks[i].changePercentage<< "\t" << Datainterface.stocks[i].volume  << "\n";
					}
					
					outt.close();
				}
				MessageBox(TEXT("买入成功"), TEXT("提示"));
			}
			else
			{
				return;
			}
			UpdateList();
		}
		
	}
	else
	{
		MessageBox(TEXT("请先选择欲买入的股票"), TEXT("提示"));
	}
	
}


void TradingSimDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	UpdateData(TRUE);
	int index = t_list.GetSelectionMark();
	if (index > -1)
	{
		if (out == TEXT(""))
		{
			MessageBox(TEXT("请填写卖出股数"), TEXT("提示"));
		}
		else
		{
			UINT i;
			string str;

			i = MessageBox(_T("确定卖出此股票吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
			if (i == IDYES)
			{
				Datainterface.stocks[index].volume += atoi(out);
				CString FilePath = _T(".\\Stocks.txt");
				ofstream outt(FilePath, ios::out);
				if (outt.is_open())
				{
					outt << Datainterface.stocks.size() << endl;
					for (int i = 0; i < Datainterface.stocks.size(); i++)
					{
						outt << Datainterface.stocks[i].symbol << "\t" << Datainterface.stocks[i].name << "\t" << Datainterface.stocks[i].price << "\t" << Datainterface.stocks[i].changePercentage << "\t" << Datainterface.stocks[i].volume << "\n";
					}

					outt.close();
				}
				MessageBox(TEXT("卖出成功"), TEXT("提示"));
			}
			else
			{
				return;
			}
			UpdateList();
		}

	}
	else
	{
		MessageBox(TEXT("请先选择欲卖出的股票"), TEXT("提示"));
	}
}


void TradingSimDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	EndDialog(0);
}
