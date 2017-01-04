#pragma once
#include "afxwin.h"


// Myinfo 대화 상자입니다.

class Myinfo : public CDialogEx
{
	DECLARE_DYNAMIC(Myinfo)

public:
	Myinfo(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~Myinfo();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
