#pragma once
#include "afxwin.h"


// Myinfo ��ȭ �����Դϴ�.

class Myinfo : public CDialogEx
{
	DECLARE_DYNAMIC(Myinfo)

public:
	Myinfo(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~Myinfo();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	CString sub_num;
	CListBox mlist;
	CString msub;
	CEdit medit;
	afx_msg void OnBnClickedCancel();
	afx_msg void OnBnClickedButton3();
};
