#pragma once


// fix 대화 상자입니다.

class fix : public CDialogEx
{
	DECLARE_DYNAMIC(fix)

public:
	fix(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~fix();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG7 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString my_pass;
	CString book;
	CString toeic;
	CString Amen;
	afx_msg void OnBnClickedOk();
};
