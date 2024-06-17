#pragma once
#include "afxdialogex.h"


// FilterDlg 对话框

class FilterDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FilterDlg)

public:
	FilterDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~FilterDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FilterDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	double min_price;
	double max_price;
	double min_change;
	double max_change;
	int min_v;
	int max_v;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
};
