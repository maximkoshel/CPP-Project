#pragma once


// DIALOG_DELETE dialog

class DIALOG_DELETE : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_DELETE)

public:
	DIALOG_DELETE(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DIALOG_DELETE();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_DELETE };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnEnChangeEdit1();
	int m_number_to_delete;
};
