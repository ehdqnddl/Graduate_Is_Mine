// mTree.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "test.h"
#include "mTree.h"
#include "afxdialogex.h"
#include "Main_page.h"
#include "board.h"
// mTree 대화 상자입니다.


IMPLEMENT_DYNAMIC(mTree, CDialogEx)

mTree::mTree(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG5, pParent)
	, stu_am(_T(""))
	, stuto(_T(""))
	, stbo(_T(""))
{

}

mTree::~mTree()
{
}

void mTree::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_STATIC1, sub_tot);
	DDX_Control(pDX, IDC_STATIC2, sub_ma);
	DDX_Control(pDX, IDC_STATIC3, sub_cho);
	DDX_Control(pDX, IDC_STATIC4, stu_bo);
	DDX_Control(pDX, IDC_STATIC5, stu_to);
	DDX_Text(pDX, IDC_STATIC6, stu_am);
	DDX_Text(pDX, IDC_STATIC5, stuto);
	DDX_Text(pDX, IDC_STATIC4, stbo);
	DDX_Control(pDX, IDC_STATIC6, stu_amen);
	CStdioFile file;
	CString Stu_id, Stu_Ma, Stu_To, Stu_Am, Stu_bo;
	CString my_path, a;
	CString sub_id[100], sub_name[100], sub_pr[100], sub_cre[100], sub_type[100];
	int n = 0, i, tot = 0, vi = 0, ch = 0;
	Stu_id = ((Main_page*)GetParent())->Stuid;
	Stu_Ma = ((Main_page*)GetParent())->StuMa;
	my_path = Stu_id + _T(".txt");
	if (file.Open(my_path, CFile::modeRead | CFile::typeText))
	{
		file.ReadString(a);
		file.ReadString(a);
		file.ReadString(Stu_Ma);
		file.ReadString(a);
		if (file.ReadString(Stu_bo))
		{
			file.ReadString(Stu_To);
			file.ReadString(Stu_Am);
		}
		else
		{
			Stu_bo = _T("0");
			Stu_To = _T("0");
			Stu_Am = _T("0");
		}
		file.Close();
	}
	my_path = Stu_id + _T("_sub.txt");
	a = Stu_Ma + _T(".txt");
	if (file.Open(a, CFile::modeRead | CFile::typeText))
	{
		while (file.ReadString(a))
		{
			AfxExtractSubString(sub_id[n], a, 0, ' ');
			AfxExtractSubString(sub_name[n], a, 1, ' ');
			AfxExtractSubString(sub_pr[n], a, 2, ' ');
			AfxExtractSubString(sub_cre[n], a, 3, ' ');
			AfxExtractSubString(sub_type[n], a, 4, ' ');

			n++;
		}
		file.Close();
	}

	if (file.Open(my_path, CFile::modeRead | CFile::typeText))
	{
		while (file.ReadString(a))
		{
			for (i = 0; i < n; i++)
			{
				if (sub_id[i] == a)
				{
					tot += _ttoi(sub_cre[i]);
					if (_ttoi(sub_type[i]) == 0)
						vi += _ttoi(sub_cre[i]);
					if (_ttoi(sub_type[i]) == 1)
						ch += _ttoi(sub_cre[i]);
				}
			}
		}
		a.Format(_T("%d"), tot);
		sub_tot.SetWindowText(a + _T("/130"));
		a.Format(_T("%d"), vi);
		sub_ma.SetWindowText(a + _T("/15"));
		a.Format(_T("%d"), ch);
		sub_cho.SetWindowText(a + _T("/24"));
		stu_bo.SetWindowText(Stu_bo + _T("/10"));
		stu_to.SetWindowText(Stu_To + _T("/700"));
		stu_amen.SetWindowText(Stu_Am + _T("/30"));
	}

}


BEGIN_MESSAGE_MAP(mTree, CDialogEx)
	ON_BN_CLICKED(IDC_BUTTON1, &mTree::OnBnClickedButton1)
	ON_WM_DRAWITEM()
END_MESSAGE_MAP()


// mTree 메시지 처리기입니다.


void mTree::OnBnClickedButton1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	board fp;
	fp.DoModal();
	fp.DestroyWindow();
}


void mTree::OnDrawItem(int nIDCtl, LPDRAWITEMSTRUCT lpDrawItemStruct)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	UpdateData(TRUE);
	CDC dc;
	RECT rect;
	dc.Attach(lpDrawItemStruct->hDC);   // Get the Button DC to CDC

	rect = lpDrawItemStruct->rcItem;     //Store the Button rect to our local rect.
	dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
	dc.FillSolidRect(&rect, RGB(255, 100, 100));//Here you can define the required color to appear on the Button.

	UINT state = lpDrawItemStruct->itemState;  //This defines the state of the Push button either pressed or not. 
	if ((state & ODS_SELECTED))
		dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
	else
		dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

	TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
	ZeroMemory(buffer, MAX_PATH);     //Intializing the buffer to zero
	::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH); //Get the Caption of Button Window 

	dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//Redraw the  Caption of Button Window 
	dc.Detach();  // Detach the Button DC

	CStdioFile file;
	CString Stu_id;
	CString my_path, a;
	int n;
	Stu_id = ((Main_page*)GetParent())->Stuid;
	my_path = Stu_id + _T("_sub.txt");
	if (file.Open(my_path, CFile::modeRead | CFile::typeText))
	{
		while (file.ReadString(a))
		{
			n = _ttoi(a);
			if (n <= 16)
			{
				if (nIDCtl == IDC_BUTTON1 + n - 1)
				{
					CDC dc;
					RECT rect;
					dc.Attach(lpDrawItemStruct->hDC);   // Get the Button DC to CDC

					rect = lpDrawItemStruct->rcItem;     //Store the Button rect to our local rect.
					dc.Draw3dRect(&rect, RGB(255, 255, 255), RGB(0, 0, 0));
					dc.FillSolidRect(&rect, RGB(100, 255, 100));//Here you can define the required color to appear on the Button.

					UINT state = lpDrawItemStruct->itemState;  //This defines the state of the Push button either pressed or not. 
					if ((state & ODS_SELECTED))
						dc.DrawEdge(&rect, EDGE_SUNKEN, BF_RECT);
					else
						dc.DrawEdge(&rect, EDGE_RAISED, BF_RECT);

					TCHAR buffer[MAX_PATH];           //To store the Caption of the button.
					ZeroMemory(buffer, MAX_PATH);     //Intializing the buffer to zero
					::GetWindowText(lpDrawItemStruct->hwndItem, buffer, MAX_PATH); //Get the Caption of Button Window 

					dc.DrawText(buffer, &rect, DT_CENTER | DT_VCENTER | DT_SINGLELINE);//Redraw the  Caption of Button Window 
					dc.Detach();  // Detach the Button DC
				}
			}
		}
	}
	//	CDialog::OnDrawItem(nIDCtl, lpDrawItemStruct);

}
