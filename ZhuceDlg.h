#pragma once
#include "afxdialogex.h"
#include "Cuser.h"

// ZhuceDlg 对话框

class ZhuceDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ZhuceDlg)

public:
	ZhuceDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~ZhuceDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ZhuceDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CString z_username;
	CString z_password;
	CString sure_password;
	CString z_email;
	afx_msg void OnBnClickedOk();
};
