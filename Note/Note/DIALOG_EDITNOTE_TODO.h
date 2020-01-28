#pragma once


// DIALOG_EDITNOTE_TODO dialog

class DIALOG_EDITNOTE_TODO : public CDialogEx
{
	DECLARE_DYNAMIC(DIALOG_EDITNOTE_TODO)

public:
	DIALOG_EDITNOTE_TODO(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DIALOG_EDITNOTE_TODO();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG_EDITNOTE_TODO };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	BOOL m_BOOL_change_text;
	BOOL m_BOOL_change_color;
	BOOL m_BOOL_change_font;
	afx_msg void OnEnChangeEdit2();
	int m_edit_number;
	CMFCFontComboBox m_fontBox;
	CString m_font_name;
	CMFCColorButton m_ColorButton;
	COLORREF m_color;

	afx_msg void OnCbnSelchangeMfcfontcombo1();
	afx_msg void OnBnClickedMfccolorbutton1();
	CString m_text;
};
