// upl_dlg.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "test.h"
#include "upl_dlg.h"
#include "afxdialogex.h"
#include "Main_page.h"

// upl_dlg ��ȭ �����Դϴ�.

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


// upl_dlg �޽��� ó�����Դϴ�.


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
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
