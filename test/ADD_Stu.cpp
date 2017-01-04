// ADD_Stu.cpp : 구현 파일입니다.
//
#include <afx.h>
#include "stdafx.h"
#include "test.h"
#include "ADD_Stu.h"
#include "afxdialogex.h"

// ADD_Stu 대화 상자입니다.

IMPLEMENT_DYNAMIC(ADD_Stu, CDialogEx)

ADD_Stu::ADD_Stu(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, Stu_Ma(_T(""))
	, Stu_Name(_T(""))
	, Stu_pass(_T(""))

	, Stu_id(_T(""))
{

}

ADD_Stu::~ADD_Stu()
{
}

void ADD_Stu::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT4, Stu_Ma);
	DDX_Text(pDX, IDC_EDIT3, Stu_Name);
	DDX_Text(pDX, IDC_EDIT2, Stu_pass);
	DDX_Text(pDX, IDC_EDIT1, Stu_id);
}


BEGIN_MESSAGE_MAP(ADD_Stu, CDialogEx)
	ON_BN_CLICKED(IDOK, &ADD_Stu::OnBnClickedOk)
END_MESSAGE_MAP()


// ADD_Stu 메시지 처리기입니다.


void ADD_Stu::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CFile fout;
	UpdateData(TRUE);

	CString m_Path = Stu_id+_T(".txt");

	CStdioFile file;

	// CFile file;

	CFileException ex;

	file.Open(m_Path, CFile::modeCreate | CFile::modeReadWrite, &ex);
	file.WriteString(Stu_pass+ "\n");
	file.WriteString(Stu_Name + "\n");
	file.WriteString(Stu_Ma + "\n");
	file.Write("0", 1);

	file.Close();
	m_Path = Stu_id + _T("_sub.txt");
	file.Open(m_Path, CFile::modeCreate | CFile::modeReadWrite, &ex);
	CDialogEx::OnOK();
}
