#pragma once
#include "afxdialogex.h"
#include "Cinterface.h"

// AnalyzeDlg 对话框

class AnalyzeDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AnalyzeDlg)

public:
	AnalyzeDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AnalyzeDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AnalyzeDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CListCtrl a_list;
	Cinterface Datainterface;
	void UpdateList();
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};
