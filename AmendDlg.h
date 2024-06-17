#pragma once
#include "afxdialogex.h"


// AmendDlg 对话框

class AmendDlg : public CDialogEx
{
	DECLARE_DYNAMIC(AmendDlg)

public:
	AmendDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~AmendDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_AmendDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString ch_username;
	CString ch_password;
	CString ch_email;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
};
