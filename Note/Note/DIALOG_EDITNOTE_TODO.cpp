// DIALOG_EDITNOTE_TODO.cpp : implementation file
//

#include "pch.h"
#include "Note.h"
#include "DIALOG_EDITNOTE_TODO.h"
#include "afxdialogex.h"


// DIALOG_EDITNOTE_TODO dialog

IMPLEMENT_DYNAMIC(DIALOG_EDITNOTE_TODO, CDialogEx)

DIALOG_EDITNOTE_TODO::DIALOG_EDITNOTE_TODO(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_EDITNOTE_TODO, pParent)
	, m_BOOL_change_text(FALSE)
	, m_BOOL_change_color(FALSE)
	, m_BOOL_change_font(FALSE)
	, m_edit_number(1)
	, m_text(_T(""))
{

}

DIALOG_EDITNOTE_TODO::~DIALOG_EDITNOTE_TODO()
{
}

void DIALOG_EDITNOTE_TODO::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Check(pDX, IDC_CHECK1, m_BOOL_change_text);
	DDX_Check(pDX, IDC_CHECK2, m_BOOL_change_color);
	DDX_Check(pDX, IDC_CHECK3, m_BOOL_change_font);
	DDX_Text(pDX, IDC_EDIT2, m_edit_number);
	DDV_MinMaxInt(pDX, m_edit_number, 1, INT_MAX);
	DDX_Control(pDX, IDC_MFCFONTCOMBO1, m_fontBox);
	DDX_Control(pDX, IDC_MFCCOLORBUTTON1, m_ColorButton);
	DDX_Text(pDX, IDC_EDIT1, m_text);
}


BEGIN_MESSAGE_MAP(DIALOG_EDITNOTE_TODO, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT2, &DIALOG_EDITNOTE_TODO::OnEnChangeEdit2)
	ON_CBN_SELCHANGE(IDC_MFCFONTCOMBO1, &DIALOG_EDITNOTE_TODO::OnCbnSelchangeMfcfontcombo1)
	ON_BN_CLICKED(IDC_MFCCOLORBUTTON1, &DIALOG_EDITNOTE_TODO::OnBnClickedMfccolorbutton1)
END_MESSAGE_MAP()


// DIALOG_EDITNOTE_TODO message handlers



void DIALOG_EDITNOTE_TODO::OnEnChangeEdit2()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}


void DIALOG_EDITNOTE_TODO::OnCbnSelchangeMfcfontcombo1()
{
	// TODO: Add your control notification handler code here
	CMFCFontInfo *pInfo = m_fontBox.GetSelFont();
	m_font_name = pInfo->m_strName;
}


void DIALOG_EDITNOTE_TODO::OnBnClickedMfccolorbutton1()
{
	// TODO: Add your control notification handler code here
	m_color = m_ColorButton.GetColor();
}
