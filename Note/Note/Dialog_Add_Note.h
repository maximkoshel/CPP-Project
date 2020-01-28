#pragma once


// Dialog_Add_Note dialog

class Dialog_Add_Note : public CDialogEx
{
	DECLARE_DYNAMIC(Dialog_Add_Note)

public:
	Dialog_Add_Note(CWnd* pParent = nullptr);   // standard constructor
	virtual ~Dialog_Add_Note();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_ADD_NOTE};
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddnote();
	int m_Hours;
	int m_minutes;

	CString m_TXT;
	afx_msg void OnCbnSelchangeFontButton();
	
	afx_msg void OnBnClickedOk();

	int m_red;
	int m_green;
	int m_blue;

	int day;
	int month;
	int year;

	CMFCFontComboBox m_font_combo_box;
	CString m_font_name;
	afx_msg void OnCbnSelchangeMfcfontcombo1();
	CMFCColorButton m_colorButton;
	afx_msg void OnBnClickedMfccolorbutton1();
	COLORREF m_color;
	afx_msg void OnDtnDatetimechangeDatetimepicker(NMHDR *pNMHDR, LRESULT *pResult);
	BOOL m_BOOL_ADDTIME;
	CDateTimeCtrl m_Datetime;
};
