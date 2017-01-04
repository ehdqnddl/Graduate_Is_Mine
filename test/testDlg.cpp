
// testDlg.cpp : 구현 파일
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


// CtestDlg 대화 상자



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


// CtestDlg 메시지 처리기

BOOL CtestDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.
	CComVariant var(_T("http://board.sejong.ac.kr/boardlist.do?bbsConfigFK=335"));
	inguk.Navigate2(&var, NULL, NULL, NULL, NULL);

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 응용 프로그램의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CtestDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CtestDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CtestDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(TRUE);
	CString a = Stu_Num + ".txt";
	CStdioFile file;
	
	if(!file.Open(a, CFile::modeRead | CFile::typeText))
	{
		MessageBox(_T("없는 학번입니다."), _T("login오류"), MB_OK);
	}
	else 
	{
		file.ReadString(a);
		if (a != Stu_Pass)
		{
			MessageBox(_T("비밀번호가 틀립니다."), _T("login오류"), MB_OK);
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
	
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	ADD_Stu ADDDlg;
	ADDDlg.DoModal();
	ADDDlg.DestroyWindow();
}


void CtestDlg::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
