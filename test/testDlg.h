
// testDlg.h : ��� ����
//

#pragma once
#include "CWebBrowser2.h"


// CtestDlg ��ȭ ����
class CtestDlg : public CDialogEx
{
// �����Դϴ�.
public:
	CtestDlg(CWnd* pParent = NULL);	// ǥ�� �������Դϴ�.
	
// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TEST_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV �����Դϴ�.


// �����Դϴ�.
protected:
	HICON m_hIcon;

	// ������ �޽��� �� �Լ�
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
