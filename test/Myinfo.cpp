// Myinfo.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "Myinfo.h"
#include "afxdialogex.h"
#include "testDlg.h"
#include "Main_page.h"

CString Stu_id;
// Myinfo 대화 상자입니다.

IMPLEMENT_DYNAMIC(Myinfo, CDialogEx)

Myinfo::Myinfo(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
	, sub_num(_T(""))
	, msub(_T(""))
{

}

Myinfo::~Myinfo()
{
}

void Myinfo::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_LIST3, mlist);
	DDX_Text(pDX, IDC_EDIT1, msub);
	CString Stu_Ma, a;
	CString sub_id, sub_name, sub_pr, sub_cre, sub_type;
	CStdioFile file;
	Stu_id = ((Main_page*)GetParent())->Stuid;
	Stu_Ma = ((Main_page*)GetParent())->StuMa;
	a = Stu_Ma + _T(".txt");
	if (mlist.GetCount() == 0)
	{
		if (file.Open(a, CFile::modeRead | CFile::typeText))
		{
			while (file.ReadString(a))
			{
				AfxExtractSubString(sub_id, a, 0, ' ');
				AfxExtractSubString(sub_name, a, 1, ' ');
				AfxExtractSubString(sub_pr, a, 2, ' ');
				AfxExtractSubString(sub_cre, a, 3, ' ');
				AfxExtractSubString(sub_type, a, 4, ' ');
				mlist.AddString(sub_id + _T(" ") + sub_name + _T(" ") + sub_pr);
			}
			file.Close();
		}
	}
	DDX_Control(pDX, IDC_EDIT1, medit);
}


BEGIN_MESSAGE_MAP(Myinfo, CDialogEx)
	ON_BN_CLICKED(IDOK, &Myinfo::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &Myinfo::OnBnClickedCancel)
	ON_BN_CLICKED(IDC_BUTTON3, &Myinfo::OnBnClickedButton3)
END_MESSAGE_MAP()


// Myinfo 메시지 처리기입니다.

void Myinfo::OnBnClickedOk()
{
	UpdateData(TRUE);
	if (msub != "")
	{
		int che = 0;
		CString a, my_path;
		CStdioFile file;
		my_path = Stu_id + _T("_sub.txt");
		if (msub.GetLength() == 1)
		{
			msub = _T("00") + msub;
		}
		if (msub.GetLength() == 2)
		{
			msub = _T("0") + msub;
		}
		if (file.Open(my_path, CFile::modeRead | CFile::typeText))
		{
			while (file.ReadString(a))
			{
				if (a == msub)
				{
					che = 1;
					break;
				}
			}
		}
		file.Close();
		if (che == 0)
		{
			file.Open(my_path, CFile::modeNoTruncate | CFile::modeWrite | CFile::typeText);
			file.SeekToEnd();
			file.WriteString(msub + "\n");
			file.Close();
			MessageBox(_T("학수번호 ") + msub + _T("가 추가되었습니다."), _T("추가"), MB_OK);
		}
		else
		{
			MessageBox(_T("이미 등록된 과목입니다."), _T("Error"), MB_OK);
		}
	}
	else
	{
		MessageBox(_T("과목을 입력하세요."), _T("Error"), MB_OK);
	}
	medit.SetSel(0, -1, TRUE);
	medit.Clear();
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	
	//CDialogEx::OnOK();
}



void Myinfo::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	
	CDialogEx::OnCancel();
}


void Myinfo::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	if (msub != "")
	{
		int che = 0;
		int n = 0, i;
		CString a[100], my_path;
		CStdioFile file;
		my_path = Stu_id + _T("_sub.txt");
		if (msub.GetLength() == 1)
		{
			msub = _T("00") + msub;
		}
		if (msub.GetLength() == 2)
		{
			msub = _T("0") + msub;
		}
		if (file.Open(my_path, CFile::modeRead | CFile::typeText))
		{
			while (file.ReadString(a[n]))
			{
				if (a[n] == msub)
				{
					n--;
					che = 1;
				}
				n++;
			}
		}
		file.Close();
		file.Open(my_path, CFile::modeCreate | CFile::modeWrite | CFile::typeText);
		if (che == 1)
		{
			for (i = 0; i < n; i++)
				file.WriteString(a[i] + "\n");
			file.Close();
			MessageBox(_T("학수번호 ") + msub + _T("가 삭제되었습니다."), _T("삭제"), MB_OK);
		}
		else
		{
			MessageBox(_T("수강하지 않은 과목입니다."), _T("Error"), MB_OK);
		}
	}
	else
	{
		MessageBox(_T("과목을 입력하세요."), _T("Error"), MB_OK);
	}
	medit.SetSel(0, -1, TRUE);
	medit.Clear();
}
