#pragma once
#include "afxdialogex.h"
#include "Cinterface.h"

// TradingSimDlg 对话框

class TradingSimDlg : public CDialogEx
{
	DECLARE_DYNAMIC(TradingSimDlg)

public:
	TradingSimDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~TradingSimDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TradingSimDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl t_list;
	Cinterface Datainterface;
	void UpdateList();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	CString in;
	CString out;
};
