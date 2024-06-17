#pragma once
#include "afxdialogex.h"


// HistDlg 对话框

class HistDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HistDlg)

public:
	HistDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HistDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HistDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
};
