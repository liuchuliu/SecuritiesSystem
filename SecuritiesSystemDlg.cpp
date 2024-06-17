
// SecuritiesSystemDlg.cpp: 实现文件
//

#include "pch.h"
#include "framework.h"
#include "SecuritiesSystem.h"
#include "SecuritiesSystemDlg.h"
#include "afxdialogex.h"
#include "LoginDlg.h"
#include "AmendDlg.h"
#include "MarketDlg.h"
#include "AnalyzeDlg.h"
#include "FilterDlg.h"
#include "RiskAssessDlg.h"
#include "TradingSimDlg.h"
#include "HisDlg.h"
#include "ZhuceDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// 用于应用程序“关于”菜单项的 CAboutDlg 对话框

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

// 实现
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSecuritiesSystemDlg 对话框



CSecuritiesSystemDlg::CSecuritiesSystemDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SECURITIESSYSTEM_DIALOG, pParent)
	, m_find(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSecuritiesSystemDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_BUTTON1, m_login);
	DDX_Control(pDX, IDC_LIST1, m_list);
	DDX_Text(pDX, IDC_EDIT1, m_find);
	DDX_Control(pDX, IDC_BUTTON9, m_picture);
}

BEGIN_MESSAGE_MAP(CSecuritiesSystemDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON10, &CSecuritiesSystemDlg::OnBnClickedButton10)
	ON_BN_CLICKED(IDC_BUTTON2, &CSecuritiesSystemDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON1, &CSecuritiesSystemDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON11, &CSecuritiesSystemDlg::OnBnClickedButton11)
	ON_BN_CLICKED(IDC_BUTTON8, &CSecuritiesSystemDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON4, &CSecuritiesSystemDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON3, &CSecuritiesSystemDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON5, &CSecuritiesSystemDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON9, &CSecuritiesSystemDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON15, &CSecuritiesSystemDlg::OnBnClickedButton15)
	ON_BN_CLICKED(IDC_BUTTON6, &CSecuritiesSystemDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON16, &CSecuritiesSystemDlg::OnBnClickedButton16)
END_MESSAGE_MAP()


// CSecuritiesSystemDlg 消息处理程序

BOOL CSecuritiesSystemDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	DWORD dwStyle = m_list.GetExtendedStyle();
	dwStyle |= LVS_EX_FULLROWSELECT;	//选中某行使整行高亮（只适用与report风格的ListCtrl） 
	dwStyle |= LVS_EX_GRIDLINES;	   //网格线（只适用与report风格的ListCtrl） 
	m_list.SetExtendedStyle(dwStyle); //设置扩展风格 

	m_list.InsertColumn(0, TEXT("证券代码"), 0, 110);
	m_list.InsertColumn(1, TEXT("证券名称"), 0, 110);
	m_list.InsertColumn(2, TEXT("当前价格($)"), 0, 110);
	m_list.InsertColumn(3, TEXT("跌涨幅(%)"), 0, 110);
	m_list.InsertColumn(4, TEXT("成交量(万股)"), 0, 110);


	//设置 Static Text 静态文本字体放大
	cfont.CreatePointFont(150, _T("黑体"), NULL);
	GetDlgItem(IDC_STATIC1)->SetFont(&cfont);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CSecuritiesSystemDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CSecuritiesSystemDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CSecuritiesSystemDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSecuritiesSystemDlg::OnBnClickedButton10()
{
	// TODO: 在此添加控件通知处理程序代码
	UINT i;
	i = MessageBox(_T("确定要退出吗？"), _T("提示"), MB_YESNO | MB_ICONQUESTION);
	if (i == IDYES)
	{
		exit(0);
	}
	else
	{
		return;
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton2()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLoggedIn)
	{
		UpdateData(TRUE);//更新用户输入
		CSecurity FindSt = datainterface.Find(m_find);
		if (FindSt.price == -1)
		{
			MessageBox(TEXT("查无此股票"), TEXT("提示"));
		}
		else
		{
			CString st;
			st.Format(TEXT("查找成功\n\n证券代码：%s\n证券名称：%s\n当前价格：%2f\n涨跌幅：%2f\n成交量：%d"),
				FindSt.symbol.c_str(), FindSt.name.c_str(), FindSt.price, FindSt.changePercentage, FindSt.volume);
			MessageBox(TEXT(st), TEXT("提示"));
		}
	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码,登录
	
	if (!isLoggedIn)
	{
		LoginDlg dlgg;
		if (IDOK == dlgg.DoModal())
		{
			Cuser uuser(dlgg.username.GetBuffer(), dlgg.password.GetBuffer(), dlgg.email.GetBuffer());
			isLoggedIn = datainterface.Login(uuser);
			if (isLoggedIn)
			{
				MessageBox(TEXT("登录成功"), TEXT("提示"));
				UpdateList();
			}
			else
			{
				MessageBox(TEXT("信息错误，请重新登录"), TEXT("提示"));
			}

		}
	}
	else
	{
		MessageBox(TEXT("已经登录！"), TEXT("提示"));
	}

}

void CSecuritiesSystemDlg::UpdateList()
{
	m_list.DeleteAllItems();
	CString str1,str2,str3;
	for (int i = 0; i < datainterface.stocks.size(); i++)
	{
		m_list.InsertItem(i, datainterface.stocks[i].symbol.c_str());
		m_list.SetItemText(i, 1, datainterface.stocks[i].name.c_str());
		str1.Format(TEXT("%2f"), datainterface.stocks[i].price);
		m_list.SetItemText(i, 2, str1);
		str2.Format(TEXT("%2f"), datainterface.stocks[i].changePercentage);
		m_list.SetItemText(i, 3, str2);
		str3.Format(TEXT("%d"), datainterface.stocks[i].volume);
		m_list.SetItemText(i, 4, str3);
	}
}





void CSecuritiesSystemDlg::OnBnClickedButton11()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLoggedIn)
	{
		for (int i = 0; i < datainterface.users.size(); i++)
		{
			if (datainterface.CurUser == datainterface.users[i].m_username)
			{
				int index = i;
				CString st;
				AmendDlg dlg;
				st.Format(TEXT("%s"), datainterface.users[i].m_username.c_str());
				dlg.ch_username = st;
				st.Format(TEXT("%s"), datainterface.users[i].m_password.c_str());
				dlg.ch_password = st;
				st.Format(TEXT("%s"), datainterface.users[i].m_email.c_str());
				dlg.ch_email = st;
				if (IDOK == dlg.DoModal())
				{
					Cuser uuser(dlg.ch_username.GetBuffer(), dlg.ch_password.GetBuffer(), dlg.ch_email.GetBuffer());
					datainterface.amend(index, uuser);
				}

			}
		}
	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton8()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLoggedIn)
	{
		MarketDlg ddlg;
		CString str;
		if (IDOK == ddlg.DoModal())
		{
			//ddlg.mar_list.DeleteAllItems();
		}
	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton4()
{
	// TODO: 在此添加控件通知处理程序代码，股票分析
	if (isLoggedIn)
	{
		AnalyzeDlg ddlg;
		CString str;
		if (IDOK == ddlg.DoModal())
		{
			//ddlg.mar_list.DeleteAllItems();
		}
	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton3()
{
	// TODO: 在此添加控件通知处理程序代码
	if (isLoggedIn)
	{
		FilterDlg dlg;
		if (IDOK == dlg.DoModal())
		{
			vector<CSecurity> old_stocks = datainterface.stocks;
			datainterface.stocks = datainterface.Filter(dlg.min_price, dlg.max_price, dlg.min_change, dlg.max_change, dlg.min_v, dlg.max_v);
			UpdateList();
			datainterface.stocks = old_stocks;
		}
	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}


void CSecuritiesSystemDlg::OnBnClickedButton5()
{
	// TODO: 在此添加控件通知处理程序代码，风险评估
	if (isLoggedIn)
	{
		RiskAssessDlg dlg;
		CString str;
		if (IDOK == dlg.DoModal())
		{
			//ddlg.mar_list.DeleteAllItems();
		}

	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
	}
}



void CSecuritiesSystemDlg::OnBnClickedButton9()
{
	// TODO: 在此添加控件通知处理程序代码，图表展示
	if (isLoggedIn)
	{
		HisDlg dl;
		CString str;
		if (IDOK == dl.DoModal())
		{
			//h
		}

	}
}


void CSecuritiesSystemDlg::OnBnClickedButton15()
{
	// TODO: 在此添加控件通知处理程序代码，交易模拟
	if (isLoggedIn)
	{
		TradingSimDlg dl;
		CString str;
		if (IDOK == dl.DoModal())
		{
			
		}

	}
	else
	{
		MessageBox(TEXT("请登录！"), TEXT("提示"));
		}
}


void CSecuritiesSystemDlg::OnBnClickedButton6()
{
	// TODO: 在此添加控件通知处理程序代码
	m_list.DeleteAllItems();
	datainterface.stocks.clear();
	datainterface.Analyze();
	UpdateList();

}


void CSecuritiesSystemDlg::OnBnClickedButton16()
{
	// TODO: 在此添加控件通知处理程序代码
	ZhuceDlg zdlg;
	if (IDOK == zdlg.DoModal())
	{
		Cuser zuser(zdlg.z_username.GetBuffer(), zdlg.z_password.GetBuffer(), zdlg.z_email.GetBuffer());
		if (datainterface.Zhuce(zuser))
		{
			MessageBox(TEXT("注册成功"), TEXT("提示"));
			isLoggedIn = false;
		}
		else
		{
			MessageBox(TEXT("用户已存在或邮箱已占用"), TEXT("提示"));
		}
	}
}
