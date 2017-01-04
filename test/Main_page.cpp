// Main_page.cpp : ���� �����Դϴ�.
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
// Main_page ��ȭ �����Դϴ�.

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


// Main_page �޽��� ó�����Դϴ�.

void Main_page::OnBnClickedButton1()
{

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	Myinfo mf;
	mf.DoModal();
	mf.DestroyWindow();
}


void Main_page::OnBnClickedButton4()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	upl_dlg uf;
	uf.DoModal();
	uf.DestroyWindow();
}


void Main_page::OnBnClickedButton2()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	mTree tf;
	tf.DoModal();
	tf.DestroyWindow();
}


void Main_page::OnBnClickedButton3()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
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
	// ���࿡ ũ�⸦ ���� ��Ű�� �ʹٸ� StretchBit�� ���
	memdc.DeleteDC();
	cBitmap.DeleteObject();


}
