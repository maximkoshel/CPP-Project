// DIALOG_DELETE.cpp : implementation file
//

#include "pch.h"
#include "Note.h"
#include "DIALOG_DELETE.h"
#include "afxdialogex.h"


// DIALOG_DELETE dialog

IMPLEMENT_DYNAMIC(DIALOG_DELETE, CDialogEx)

DIALOG_DELETE::DIALOG_DELETE(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_DELETE, pParent)
	, m_number_to_delete(1)
{

}

DIALOG_DELETE::~DIALOG_DELETE()
{
}

void DIALOG_DELETE::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_number_to_delete);
	DDV_MinMaxInt(pDX, m_number_to_delete, 1, INT_MAX);
}


BEGIN_MESSAGE_MAP(DIALOG_DELETE, CDialogEx)
	ON_BN_CLICKED(IDOK, &DIALOG_DELETE::OnBnClickedOk)
	ON_EN_CHANGE(IDC_EDIT1, &DIALOG_DELETE::OnEnChangeEdit1)
END_MESSAGE_MAP()


// DIALOG_DELETE message handlers


void DIALOG_DELETE::OnBnClickedOk()
{
	// TODO: Add your control notification handler code here
	CDialogEx::OnOK();
}


void DIALOG_DELETE::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
