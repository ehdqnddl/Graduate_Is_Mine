#pragma once
#include "CWebBrowser2.h"


// board 대화 상자입니다.

class board : public CDialogEx
{
	DECLARE_DYNAMIC(board)

public:
	board(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~board();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CWebBrowser2 jinwon;
};
