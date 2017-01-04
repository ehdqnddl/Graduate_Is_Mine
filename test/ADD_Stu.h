#pragma once


// ADD_Stu 대화 상자입니다.

class ADD_Stu : public CDialogEx
{
	DECLARE_DYNAMIC(ADD_Stu)

public:
	ADD_Stu(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~ADD_Stu();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CString Stu_Ma;
	CString Stu_Name;
	CString Stu_pass;
	afx_msg void OnBnClickedOk();
	CString Stu_id;
};
