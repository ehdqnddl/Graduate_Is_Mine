#pragma once


// ADD_Stu ��ȭ �����Դϴ�.

class ADD_Stu : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_Stu)

public:
	ADD_Stu(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~ADD_Stu();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString Stu_Ma;
	CString Stu_Name;
	CString Stu_pass;
	afx_msg void OnBnClickedOk();
	CString Stu_id;
};
