#pragma once
#include "afxdialogex.h"
#include "Cinterface.h"

// MarketDlg 对话框

class MarketDlg : public CDialogEx
{
	DECLARE_DYNAMIC(MarketDlg)

public:
	MarketDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~MarketDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MarketDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl mar_list;
	afx_msg void OnBnClickedButton13();
	afx_msg void OnBnClickedButton6();
	virtual BOOL OnInitDialog();
	Cinterface Datainterface;
	void UpdateList();
	afx_msg void OnBnClickedButton14();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton12();
};
