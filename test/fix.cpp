// fix.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "fix.h"
#include "afxdialogex.h"
#include "Main_page.h"
// fix 대화 상자입니다.

IMPLEMENT_DYNAMIC(fix, CDialogEx)

fix::fix(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG7, pParent)
	, my_pass(_T(""))
	, book(_T(""))
	, toeic(_T(""))
	, Amen(_T(""))
{

}

fix::~fix()
{
}

void fix::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, my_pass);
	DDX_Text(pDX, IDC_EDIT2, book);
	DDX_Text(pDX, IDC_EDIT3, toeic);
	DDX_Text(pDX, IDC_EDIT4, Amen);

}


BEGIN_MESSAGE_MAP(fix, CDialogEx)
	ON_BN_CLICKED(IDOK, &fix::OnBnClickedOk)
END_MESSAGE_MAP()


// fix 메시지 처리기입니다.


void fix::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (my_pass!=""&& book !="" && toeic !="" &&Amen != "")
	{
		CStdioFile file;
		CString Stu_id, Stu_Ma, Stu_Mil, m_Path, Stu_Name;
		CString sub_id, sub_name, sub_pr, sub_cre, sub_type;
		CFileException ex;
		Stu_id = ((Main_page*)GetParent())->Stuid;
		Stu_Ma = ((Main_page*)GetParent())->StuMa;
		Stu_Mil = ((Main_page*)GetParent())->StuMil;
		Stu_Name = ((Main_page*)GetParent())->StuNa;
		m_Path = Stu_id + _T(".txt");

		file.Open(m_Path, CFile::modeCreate | CFile::modeReadWrite, &ex);
		file.WriteString(my_pass + "\n");
		file.WriteString(Stu_Name + "\n");
		file.WriteString(Stu_Ma + "\n");
		file.WriteString(Stu_Mil + "\n");
		file.WriteString(book + "\n");
		file.WriteString(toeic + "\n");
		file.WriteString(Amen + "\n");
		CDialogEx::OnOK();
	}
	else
	{
		MessageBox(_T("빈 정보가 있습니다."), _T("오류"), MB_OK);
	}

}
