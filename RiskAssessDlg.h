#pragma once
#include "afxdialogex.h"
#include "Cinterface.h"

// RiskAssessDlg 对话框

class RiskAssessDlg : public CDialogEx
{
	DECLARE_DYNAMIC(RiskAssessDlg)

public:
	RiskAssessDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~RiskAssessDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_RiskAssessDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	CListCtrl r_list;
	Cinterface Datainterface;
	void UpdateList();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
