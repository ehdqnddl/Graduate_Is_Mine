#pragma once
#include "afxwin.h"


// mTree 대화 상자입니다.

class mTree : public CDialogEx
{
	DECLARE_DYNAMIC(mTree)

public:
	mTree(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~mTree();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	CButton but001;
	afx_msg void OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct);
	CStatic sub_tot;
	CStatic sub_ma;
	CStatic sub_cho;
	CStatic stu_bo;
	CStatic stu_to;
	CString stu_am;
	CString stuto;
	CString stbo;
	CStatic stu_amen;
};
