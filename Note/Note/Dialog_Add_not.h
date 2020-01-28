#pragma once


// Dialog_Add_not dialog

class Dialog_Add_not : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog_Add_not)

public:
	Dialog_Add_not(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Dialog_Add_not();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_NOTE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeEdit1();
};
