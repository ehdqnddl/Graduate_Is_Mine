#pragma once


// fix ��ȭ �����Դϴ�.

class fix : public CDialogEx
{
	DECLARE_DYNAMIC(fix)

public:
	fix(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~fix();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString my_pass;
	CString book;
	CString toeic;
	CString Amen;
	afx_msg void OnBnClickedOk();
};
