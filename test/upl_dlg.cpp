// upl_dlg.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "upl_dlg.h"
#include "afxdialogex.h"
#include "Main_page.h"

// upl_dlg 대화 상자입니다.

IMPLEMENT_DYNAMIC(upl_dlg, CDialogEx)

upl_dlg::upl_dlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG4, pParent)
{

}

upl_dlg::~upl_dlg()
{
}

void upl_dlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(upl_dlg, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON5, &upl_dlg::OnBnClickedButton5)
END_MESSAGE_MAP()


// upl_dlg 메시지 처리기입니다.


void upl_dlg::OnBnClickedButton5()
{

	char command[18] = { 0 };
	CString Stu_id;
	Stu_id = ((Main_page*)GetParent())->Stuid;
	Stu_id = _T("upload.exe ") + Stu_id;
	for (int i = 0; i < 17; i++) {
		command[i] = Stu_id[i];
	}
	command[17] = '\0';
	system(command);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
