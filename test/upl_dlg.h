#pragma once


// upl_dlg 대화 상자입니다.

class upl_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(upl_dlg)

public:
	upl_dlg(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~upl_dlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
};
