#pragma once
#include "afxwin.h"


// Main_page ��ȭ �����Դϴ�.

class Main_page : public CDialogEx
{
	DECLARE_DYNAMIC(Main_page)

public:
	Main_page(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Main_page();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString Stuid;
	CString StuMa;
	CString StuMil;
	CString StuNa;
	CString StuPass;
	afx_msg void OnBnClickedButton1();
	CStatic te_na;
	CStatic te_num;
	CStatic te_ma;
	CStatic te_mil;
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnPaint();
};
