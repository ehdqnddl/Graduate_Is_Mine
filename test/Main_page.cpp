// Main_page.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "Main_page.h"
#include "upl_dlg.h"
#include "fix.h"
#include "mTree.h"
#include "afxdialogex.h"
#include "Myinfo.h"
#include "testDlg.h"
// Main_page 대화 상자입니다.

IMPLEMENT_DYNAMIC(Main_page, CDialogEx)

Main_page::Main_page(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
{

}

Main_page::~Main_page()
{
}

void Main_page::DoDataExchange(CDataExchange* pDX)
{
	int n;
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_STATIC1, te_na);
	DDX_Control(pDX, IDC_STATIC2, te_num);
	DDX_Control(pDX, IDC_STATIC3, te_ma);
	DDX_Control(pDX, IDC_STATIC4, te_mil);

	Stuid = ((CtestDlg*)GetParent())->Stu_Num;

	
	CStdioFile file;
	CString m_Path,a,Stubo, StuTo, StuAm;
	CFileException ex;
	
	m_Path = Stuid + _T(".txt");
	if (file.Open(m_Path, CFile::modeRead | CFile::typeText))
	{
		file.ReadString(StuPass);
		file.ReadString(StuNa);
		file.ReadString(StuMa);
		file.ReadString(StuMil);
		if (file.ReadString(Stubo))
		{
			file.ReadString(StuTo);
			file.ReadString(StuAm);
		}
		else
		{
			Stubo = _T("0");
			StuTo = _T("0");
			StuAm = _T("0");
		}
		file.Close();
	}
	te_na.SetWindowText(StuNa);
	te_ma.SetWindowText(StuMa);
	te_mil.SetWindowText(StuMil);
	te_num.SetWindowText(Stuid);
	n = _ttoi(StuMil);
	n = n + 5;
	StuMil.Format(_T("%d"), n);

	file.Open(m_Path, CFile::modeCreate | CFile::modeReadWrite, &ex);
	file.WriteString(StuPass + "\n");
	file.WriteString(StuNa + "\n");
	file.WriteString(StuMa + "\n");
	file.WriteString(StuMil + "\n");
	file.WriteString(Stubo + "\n");
	file.WriteString(StuTo + "\n");
	file.WriteString(StuAm + "\n");
	file.Close();
}	

BEGIN_MESSAGE_MAP(Main_page, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &Main_page::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &Main_page::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON2, &Main_page::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &Main_page::OnBnClickedButton3)
	ON_WM_PAINT()
END_MESSAGE_MAP()


// Main_page 메시지 처리기입니다.

void Main_page::OnBnClickedButton1()
{

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	Myinfo mf;
	mf.DoModal();
	mf.DestroyWindow();
}


void Main_page::OnBnClickedButton4()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	upl_dlg uf;
	uf.DoModal();
	uf.DestroyWindow();
}


void Main_page::OnBnClickedButton2()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	mTree tf;
	tf.DoModal();
	tf.DestroyWindow();
}


void Main_page::OnBnClickedButton3()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	fix ff;
	ff.DoModal();
	ff.DestroyWindow();
}


void Main_page::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	HANDLE bmp;
	CBitmap cBitmap;
	BITMAP bmpinfo;
	CDC memdc;
	bmp = LoadImage(NULL, _T("sul.bmp"), IMAGE_BITMAP, 0, 0, LR_LOADFROMFILE);
	cBitmap.Attach(bmp);
	cBitmap.GetBitmap(&bmpinfo);
	memdc.CreateCompatibleDC(&dc);
	memdc.SelectObject(bmp);

	CRect rect;
	GetClientRect(&rect);
	int x = (rect.Width() - bmpinfo.bmWidth);

	dc.BitBlt(x, 0, bmpinfo.bmWidth, bmpinfo.bmHeight, &memdc, 0, 0, SRCCOPY);
	// 만약에 크기를 고정 시키고 싶다면 StretchBit를 사용
	memdc.DeleteDC();
	cBitmap.DeleteObject();


}
