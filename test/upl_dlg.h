#pragma once


// upl_dlg ��ȭ �����Դϴ�.

class upl_dlg : public CDialogEx
{
	DECLARE_DYNAMIC(upl_dlg)

public:
	upl_dlg(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~upl_dlg();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton5();
};
