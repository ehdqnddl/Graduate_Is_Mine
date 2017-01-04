
// testDlg.cpp : ���� ����
//

#include "stdafx.h"
#include "test.h"
#include "testDlg.h"
#include "afxdialogex.h"
#include "ADD_Stu.h"
#include "Main_page.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CtestDlg ��ȭ ����



CtestDlg::CtestDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_TEST_DIALOG, pParent)
	, Stu_Num(_T(""))
	, Stu_Pass(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CtestDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, Stu_Num);
	DDX_Text(pDX, IDC_EDIT2, Stu_Pass);
	DDX_Control(pDX, IDC_EXPLORER1, inguk);
}

BEGIN_MESSAGE_MAP(CtestDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CtestDlg::OnBnClickedOk)
	ON_BN_CLICKED(IDC_BUTTON1, &CtestDlg::OnBnClickedButton1)
	ON_EN_CHANGE(IDC_EDIT1, &CtestDlg::OnEnChangeEdit1)
END_MESSAGE_MAP()


// CtestDlg �޽��� ó����

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// �� ��ȭ ������ �������� �����մϴ�.  ���� ���α׷��� �� â�� ��ȭ ���ڰ� �ƴ� ��쿡��
	//  �����ӿ�ũ�� �� �۾��� �ڵ����� �����մϴ�.
	SetIcon(m_hIcon, TRUE);			// ū �������� �����մϴ�.
	SetIcon(m_hIcon, FALSE);		// ���� �������� �����մϴ�.

	// TODO: ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	CComVariant var(_T("http://board.sejong.ac.kr/boardlist.do?bbsConfigFK=335"));
	inguk.Navigate2(&var, NULL, NULL, NULL, NULL);

	return TRUE;  // ��Ŀ���� ��Ʈ�ѿ� �������� ������ TRUE�� ��ȯ�մϴ�.
}

// ��ȭ ���ڿ� �ּ�ȭ ���߸� �߰��� ��� �������� �׸�����
//  �Ʒ� �ڵ尡 �ʿ��մϴ�.  ����/�� ���� ����ϴ� MFC ���� ���α׷��� ��쿡��
//  �����ӿ�ũ���� �� �۾��� �ڵ����� �����մϴ�.

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // �׸��⸦ ���� ����̽� ���ؽ�Ʈ�Դϴ�.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Ŭ���̾�Ʈ �簢������ �������� ����� ����ϴ�.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// �������� �׸��ϴ�.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// ����ڰ� �ּ�ȭ�� â�� ���� ���ȿ� Ŀ���� ǥ�õǵ��� �ý��ۿ���
//  �� �Լ��� ȣ���մϴ�.
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(TRUE);
	CString a = Stu_Num + ".txt";
	CStdioFile file;
	
	if(!file.Open(a, CFile::modeRead | CFile::typeText))
	{
		MessageBox(_T("���� �й��Դϴ�."), _T("login����"), MB_OK);
	}
	else 
	{
		file.ReadString(a);
		if (a != Stu_Pass)
		{
			MessageBox(_T("��й�ȣ�� Ʋ���ϴ�."), _T("login����"), MB_OK);
		}
		else
		{
			file.ReadString(a);
			Stu_Name = a;
			file.ReadString(a);
			Stu_Ma = a;
			file.ReadString(a);
			Stu_Mil = a;
			file.Close();
			CDialogEx::OnOK();
			Main_page mp;
			mp.DoModal();
			mp.DestroyWindow();
		}
	}


}


void CtestDlg::OnBnClickedButton1()
{
	
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	ADD_Stu ADDDlg;
	ADDDlg.DoModal();
	ADDDlg.DestroyWindow();
}


void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
