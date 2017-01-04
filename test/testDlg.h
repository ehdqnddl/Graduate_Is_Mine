
// testDlg.h : 헤더 파일
//

#pragma once
#include "CWebBrowser2.h"


// CtestDlg 대화 상자
class CtestDlg : public CDialogEx
{
// 생성입니다.
public:
	CtestDlg(CWnd* pParent = NULL);	// 표준 생성자입니다.
	
// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 지원입니다.


// 구현입니다.
protected:
	HICON m_hIcon;

	// 생성된 메시지 맵 함수
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CString Stu_Num;
	CString Stu_Pass;
	CString Stu_Name;
	CString Stu_Ma;
	CString Stu_Mil;
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedButton1();
	afx_msg void OnEnChangeEdit1();
	CWebBrowser2 inguk;
};
