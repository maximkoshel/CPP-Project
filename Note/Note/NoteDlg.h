
// NoteDlg.h : header file
//

#pragma once
#include "VMessage.h"

// CNoteDlg dialog
class CNoteDlg : public CDialogEx
{
// Construction
public:
	CNoteDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NOTE_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedAddnote();
	void draw(CPaintDC *,int);
	afx_msg void OnBnClickedButtonDown();
	afx_msg void OnBnClickedButtonUp();

	void SaveToDolist();
	void SaveTimelist();

	void OpenToDolist();
	void OpenTimelist();

	void sortTimeOut();


	void ChangeMessageText(VMessage&,CString);
	void ChangeMessageColor(VMessage&, COLORREF);
	void ChangeMessageCFont(VMessage&, CString);


	void drawToDoList(CPaintDC *pDC, int page);
	void drawTimeList(CPaintDC *pDC, int page);

	CStatic m_page_todo_number;
	int int_todo_page_number= 1;
	afx_msg void OnBnClickedButtonDelete();
	afx_msg void OnBnClickedButtonEditnote();
	afx_msg void OnBnClickedButtonSave();
	afx_msg void OnBnClickedButtonRedo();


	afx_msg void OnBnClickedButtonRight();
	afx_msg void OnBnClickedButtonLeft();
	CStatic m_title;

	int status = 1;
};
