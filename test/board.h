#pragma once
#include "CWebBrowser2.h"


// board ��ȭ �����Դϴ�.

class board : public CDialogEx
{
	DECLARE_DYNAMIC(board)

public:
	board(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~board();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CWebBrowser2 jinwon;
};
