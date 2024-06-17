
// SecuritiesSystemDlg.h: 头文件
//

#pragma once
#include "Cinterface.h"
#include "Cuser.h"

// CSecuritiesSystemDlg 对话框
class CSecuritiesSystemDlg : public CDialogEx
{
// 构造
public:
	CSecuritiesSystemDlg(CWnd* pParent = nullptr);	// 标准构造函数

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SECURITIESSYSTEM_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持


// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	Cinterface datainterface;
	bool isLoggedIn = false;
	CString UserFilePath;
	afx_msg void OnBnClickedButton10();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton1();
	CButton m_login;
	CListCtrl m_list;
	void UpdateList();
	CString m_find;
	CFont cfont;
	afx_msg void OnBnClickedButton11();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButton15();
	CButton m_picture;
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton16();
};
