#pragma once
#include "afxdialogex.h"


// HisDlg 对话框

class HisDlg : public CDialogEx
{
	DECLARE_DYNAMIC(HisDlg)

public:
	HisDlg(CWnd* pParent = nullptr);   // 标准构造函数
	virtual ~HisDlg();

// 对话框数据
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_HisDlg };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	CButton m_pic;
	afx_msg void OnBnClickedButton1();
};
