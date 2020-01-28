// Dialog_Add_not.cpp : implementation file
//

#include "pch.h"
#include "Note.h"
#include "Dialog_Add_not.h"
#include "afxdialogex.h"


// Dialog_Add_not dialog

IMPLEMENT_DYNAMIC(Dialog_Add_not, CDialogEx)

Dialog_Add_not::Dialog_Add_not(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG_ADD_NOTE, pParent)
{

}

Dialog_Add_not::~Dialog_Add_not()
{
}

void Dialog_Add_not::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(Dialog_Add_not, CDialogEx)
	ON_EN_CHANGE(IDC_EDIT1, &Dialog_Add_not::OnEnChangeEdit1)
END_MESSAGE_MAP()


// Dialog_Add_not message handlers


void Dialog_Add_not::OnEnChangeEdit1()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
}
