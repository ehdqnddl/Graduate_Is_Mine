// board.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "board.h"
#include "afxdialogex.h"


// board 대화 상자입니다.

IMPLEMENT_DYNAMIC(board, CDialogEx)

board::board(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG6, pParent)
{

}

board::~board()
{
}

void board::DoDataExchange(CDataExchange* pDX)
{
	
	DDX_Control(pDX, IDC_EXPLORER1, jinwon);
	CComVariant var(_T("file:///C:/Users/Seo/Desktop/test/test/board/main.htm"));
	jinwon.Navigate2(&var, NULL, NULL, NULL, NULL);

	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(board, CDialogEx)
END_MESSAGE_MAP()


// board 메시지 처리기입니다.
