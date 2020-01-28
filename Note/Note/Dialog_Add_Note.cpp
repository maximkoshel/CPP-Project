// Dialog_Add_Note.cpp : implementation file
//

#include "pch.h"
#include "Note.h"
#include "Dialog_Add_Note.h"
#include "afxdialogex.h"


// Dialog_Add_Note dialog

IMPLEMENT_DYNAMIC(Dialog_Add_Note, CDialogEx)

Dialog_Add_Note::Dialog_Add_Note(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_NOTE, pParent)
	, m_Hours(0)
	, m_minutes(0)
	, m_TXT(_T("Enter Your Note text here"))


	, m_red(0)
	, m_green(0)
	, m_blue(0)
	, m_BOOL_ADDTIME(FALSE)
{

}

Dialog_Add_Note::~Dialog_Add_Note()
{
}

void Dialog_Add_Note::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT2, m_Hours);
	DDV_MinMaxInt(pDX, m_Hours, 0, 23);
	DDX_Text(pDX, IDC_EDIT3, m_minutes);
	DDV_MinMaxInt(pDX, m_minutes, 0, 59);

	DDX_Text(pDX, IDC_EDIT1, m_TXT);




	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_font_combo_box);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_colorButton);
	DDX_Check(pDX, IDC_CHECK2, m_BOOL_ADDTIME);
	DDX_Control(pDX, IDC_DATETIMEPICKER, m_Datetime);
}


BEGIN_MESSAGE_MAP(Dialog_Add_Note, CDialogEx)
	ON_BN_CLICKED(IDC_ADDNOTE, &Dialog_Add_Note::OnBnClickedAddnote)
	ON_CBN_SELCHANGE(IDC_FONT_BUTTON, &Dialog_Add_Note::OnCbnSelchangeFontButton)
	ON_BN_CLICKED(IDOK, &Dialog_Add_Note::OnBnClickedOk)

	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO1, &Dialog_Add_Note::OnCbnSelchangeMfcfontcombo1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &Dialog_Add_Note::OnBnClickedMfccolorbutton1)
	ON_NOTIFY(DTN_DATETIMECHANGE, IDC_DATETIMEPICKER, &Dialog_Add_Note::OnDtnDatetimechangeDatetimepicker)
END_MESSAGE_MAP()


// Dialog_Add_Note message handlers


void Dialog_Add_Note::OnBnClickedAddnote()
{
	// TODO: Add your control notification handler code here

}


void Dialog_Add_Note::OnCbnSelchangeFontButton()
{
	
	// TODO: Add your control notification handler code here
}


void Dialog_Add_Note::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}




void Dialog_Add_Note::OnCbnSelchangeMfcfontcombo1()
{
	// TODO: Add your control notification handler code here

	CMFCFontInfo *pInfo = m_font_combo_box.GetSelFont();
	m_font_name = pInfo->m_strName;


}




void Dialog_Add_Note::OnBnClickedMfccolorbutton1()
{
	// TODO: Add your control notification handler code here
	m_color = m_colorButton.GetColor();
}


void Dialog_Add_Note::OnDtnDatetimechangeDatetimepicker(NMHDR *pNMHDR, LRESULT *pResult)
{
	LPNMDATETIMECHANGE pDTChange = reinterpret_cast<LPNMDATETIMECHANGE>(pNMHDR);
	// TODO: Add your control notification handler code here
	*pResult = 0;
	COleDateTime time;
	this->m_Datetime.GetTime(time);

	this->day = time.GetDay();
	this->month = time.GetMonth();
	this->year = time.GetYear();

}

