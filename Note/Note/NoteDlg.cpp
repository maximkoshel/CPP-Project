
// NoteDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Note.h"
#include "NoteDlg.h"
#include "afxdialogex.h"
#include "Dialog_Add_Note.h"
#include "VMessage.h"
#include "ToDoMessage.h"
#include "DIALOG_DELETE.h"
#include "DIALOG_EDITNOTE_TODO.h"
#include "TimeMessage.h"
#include <iostream>
#include <fstream>
#include <list>
#include <string>
using namespace std;


#ifdef _DEBUG
#define new DEBUG_NEW
#endif

//list instence
list<ToDoMessage> listTODO;
std::list<ToDoMessage>::iterator iterator_todo;

list<TimeMessage> listTimeMessage;
std::list<TimeMessage>::iterator iterator_timeMessage;


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CNoteDlg dialog



CNoteDlg::CNoteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_NOTE_DIALOG, pParent)

{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CNoteDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PAGE, m_page_todo_number);
	DDX_Control(pDX, IDC_TITLE, m_title);
}

BEGIN_MESSAGE_MAP(CNoteDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_ADDNOTE, &CNoteDlg::OnBnClickedAddnote)
	ON_BN_CLICKED(IDC_BUTTON_DOWN, &CNoteDlg::OnBnClickedButtonDown)
	ON_BN_CLICKED(IDC_BUTTON_UP, &CNoteDlg::OnBnClickedButtonUp)
	ON_BN_CLICKED(IDC_BUTTON_Delete, &CNoteDlg::OnBnClickedButtonDelete)
	ON_BN_CLICKED(IDC_BUTTON_EDITNOTE, &CNoteDlg::OnBnClickedButtonEditnote)
	ON_BN_CLICKED(IDC_BUTTON_SAVE, &CNoteDlg::OnBnClickedButtonSave)
	ON_BN_CLICKED(IDC_BUTTON_REDO, &CNoteDlg::OnBnClickedButtonRedo)
	ON_BN_CLICKED(IDC_BUTTON_RIGHT, &CNoteDlg::OnBnClickedButtonRight)
	ON_BN_CLICKED(IDC_BUTTON_LEFT, &CNoteDlg::OnBnClickedButtonLeft)
END_MESSAGE_MAP()


// CNoteDlg message handlers

BOOL CNoteDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	CNoteDlg::OnBnClickedButtonRedo(); //OPENS THE SAVED FILE ONCE THE PROGRAMM IS LOADED

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CNoteDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CNoteDlg::OnPaint()
{
	if (IsIconic())
	{
		  

		CPaintDC dc(this); // device context for painting
		CDialogEx::OnPaint();
		draw(&dc, this->int_todo_page_number);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		draw(&dc,this->int_todo_page_number);
	
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CNoteDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


void CNoteDlg::OnBnClickedAddnote()
{


	Dialog_Add_Note dialog_add_note;
	if (dialog_add_note.DoModal() == IDOK) {
		
		//CMFCFontComboBox name = dialog_add_note.m_Font;
		//CString font = name->GetFullName();

		CString font(dialog_add_note.m_font_name);
		//new class instence
		int red = dialog_add_note.m_red;
		int green = dialog_add_note.m_green;
		int blue = dialog_add_note.m_blue;

		if (dialog_add_note.m_BOOL_ADDTIME) {
			TimeMessage newTimeMessage(dialog_add_note.m_TXT, font, dialog_add_note.m_color, dialog_add_note.year, dialog_add_note.month, dialog_add_note.day, dialog_add_note.m_Hours, dialog_add_note.m_minutes);
			listTimeMessage.push_back(newTimeMessage);
			TimeMessage::numberOfTimeMessage += 1;
			//CNoteDlg::sortTimeOut();
		}

		else {
			ToDoMessage newToDoMessage(dialog_add_note.m_TXT, font, dialog_add_note.m_color);
			listTODO.push_back(newToDoMessage);
			ToDoMessage::numberOfTODO += 1;
		}
	}

	Invalidate();
	UpdateWindow();
}


void CNoteDlg::draw(CPaintDC *pDC,int page) {


	if (status == 1)
		CNoteDlg::drawToDoList(pDC, page);
	else 
		CNoteDlg::drawTimeList(pDC, page);
}


void CNoteDlg::drawToDoList(CPaintDC *pDC, int page) {
	CString num;
	int x = 0, y = 65;
	int capacity = 5;
	int spacing = 35;

	if ((ToDoMessage::numberOfTODO != 0 && ToDoMessage::numberOfTODO > (page - 1)*capacity && ToDoMessage::numberOfTODO <= (page)* capacity) || (ToDoMessage::numberOfTODO > page*capacity)) {
		iterator_todo = listTODO.begin();
		//Moving the itterator
		if (page != 1) {
			for (int j = 0; j < ((page - 1)*capacity); j++)
				iterator_todo++;
		}

		//Printing the content
		for (int i = 0; ((page - 1)*capacity + i) < ToDoMessage::numberOfTODO && i < capacity; i++) {

			//Calculating the Number
			num.Format(_T("%d"), i + 1 + (page - 1)*capacity);

			y += spacing;

			//Drawing the text
			iterator_todo->DrawNumber(pDC, x, y, num + _T("."));
			iterator_todo->Draw(pDC, x + 25, y);
			iterator_todo++;

		}
	}
}


void CNoteDlg::drawTimeList(CPaintDC *pDC, int page) {

	CString num;
	int x = 0, y = 65;
	int capacity = 5;
	int spacing = 35;

	if ((TimeMessage::numberOfTimeMessage != 0 && TimeMessage::numberOfTimeMessage > (page - 1)*capacity && TimeMessage::numberOfTimeMessage <= (page)* capacity) || (TimeMessage::numberOfTimeMessage > page*capacity)) {
		iterator_timeMessage = listTimeMessage.begin();
		//Moving the itterator
		if (page != 1) {
			for (int j = 0; j < ((page - 1)*capacity); j++)
				iterator_timeMessage++;
		}

		//Printing the content
		for (int i = 0; ((page - 1)*capacity + i) < TimeMessage::numberOfTimeMessage && i < capacity; i++) {

			//Calculating the Number
			num.Format(_T("%d"), i + 1 + (page - 1)*capacity);

			y += spacing;

			//Drawing the text
			iterator_timeMessage->DrawNumber(pDC, x, y, num + _T("."));
			iterator_timeMessage->Draw(pDC, x + 25, y);
			iterator_timeMessage++;

		}
	}
}


void CNoteDlg::OnBnClickedButtonDown()
{
	// Increasing number page
	int_todo_page_number += 1;
	CString num;
	num.Format(_T("%d"), int_todo_page_number);
	m_page_todo_number.SetWindowTextW(num);
	CPaintDC dc(this);
	draw(&dc, this->int_todo_page_number);
	Invalidate();
	UpdateWindow();
}


void CNoteDlg::OnBnClickedButtonUp()
{
	// Decreasing number page
	if (int_todo_page_number > 1) {
		int_todo_page_number -= 1;
		CString num;
		num.Format(_T("%d"), int_todo_page_number);
		m_page_todo_number.SetWindowTextW(num);
		CPaintDC dc(this);
		draw(&dc, int_todo_page_number);
		Invalidate();
		UpdateWindow();
	}
}


void CNoteDlg::OnBnClickedButtonDelete()
{
	DIALOG_DELETE dialog_delete;

	if (dialog_delete.DoModal() == IDOK) {

		if (status == 1) {

			if (dialog_delete.m_number_to_delete > ToDoMessage::numberOfTODO)
				AfxThrowInvalidArgException();
			else {
				iterator_todo = listTODO.begin();
				for (int i = 0; i < dialog_delete.m_number_to_delete - 1; i++) {
					iterator_todo++;
				}
				listTODO.erase(iterator_todo);
				ToDoMessage::numberOfTODO--;
			}
		}
		else {
			
			if (dialog_delete.m_number_to_delete > TimeMessage::numberOfTimeMessage)
				AfxThrowInvalidArgException();
			else {
				iterator_timeMessage = listTimeMessage.begin();
				for (int i = 0; i < dialog_delete.m_number_to_delete - 1; i++) {
					iterator_timeMessage++;
				}
				listTimeMessage.erase(iterator_timeMessage);
				TimeMessage::numberOfTimeMessage--;
			}
		}


	}
	Invalidate();
	UpdateWindow();
}


void CNoteDlg::OnBnClickedButtonEditnote()
{
	DIALOG_EDITNOTE_TODO dialog_edit_todo;
	if (dialog_edit_todo.DoModal() == IDOK) {

		if (status == 1) {
			if (dialog_edit_todo.m_edit_number > ToDoMessage::numberOfTODO) {
				AfxThrowInvalidArgException();
			}
			else {
				iterator_todo = listTODO.begin();
				for (int i = 0; i < dialog_edit_todo.m_edit_number - 1; i++)
					iterator_todo++;


				if (dialog_edit_todo.m_BOOL_change_color) {
					ChangeMessageColor(*iterator_todo, dialog_edit_todo.m_color);
				}
				if (dialog_edit_todo.m_BOOL_change_font) {
					ChangeMessageCFont(*iterator_todo, dialog_edit_todo.m_font_name);
				}
				if (dialog_edit_todo.m_BOOL_change_text) {
					ChangeMessageText(*iterator_todo, dialog_edit_todo.m_text);
				}
			}
		}
		else {
			if (dialog_edit_todo.m_edit_number > TimeMessage::numberOfTimeMessage) {
				AfxThrowInvalidArgException();
			}
			else {
				iterator_timeMessage = listTimeMessage.begin();
				for (int i = 0; i < dialog_edit_todo.m_edit_number - 1; i++)
					iterator_timeMessage++;


				if (dialog_edit_todo.m_BOOL_change_color) {
					ChangeMessageColor(*iterator_timeMessage, dialog_edit_todo.m_color);
				}
				if (dialog_edit_todo.m_BOOL_change_font) {
					ChangeMessageCFont(*iterator_timeMessage, dialog_edit_todo.m_font_name);
				}
				if (dialog_edit_todo.m_BOOL_change_text) {
					ChangeMessageText(*iterator_timeMessage, dialog_edit_todo.m_text);
				}
			}
		}
	}
	Invalidate();
	UpdateWindow();
	}



void CNoteDlg::ChangeMessageText(VMessage& mes, CString txt) {

	ToDoMessage *temp = dynamic_cast<ToDoMessage *>(&mes);
	temp->SetText(txt);
}


void CNoteDlg::ChangeMessageColor(VMessage& mes, COLORREF col) {
	ToDoMessage *temp = dynamic_cast<ToDoMessage *>(&mes);
	temp->SetColor(col);
}


void CNoteDlg::ChangeMessageCFont(VMessage& mes, CString font) {
	ToDoMessage *temp = dynamic_cast<ToDoMessage *>(&mes);
	temp->SetFont(font);
}


void CNoteDlg::OnBnClickedButtonSave()
{

	CNoteDlg::SaveToDolist();
	CNoteDlg::SaveTimelist();
}


void CNoteDlg::SaveToDolist() {

	//Writing the static number of TODO  
	ofstream myfile("TODOMESSAGEINFONEW_ALLNUMBER.txt");
	myfile << ToDoMessage::numberOfTODO;
	myfile.close();
	CFile file;

	file.Open(L"TODOMESSAGEINFONEW.hse", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	iterator_todo = listTODO.begin();
	for (int i = 0; i < ToDoMessage::numberOfTODO; i++) {
		iterator_todo->Serialize(ar);
		iterator_todo++;
	}
	ar.Close();
	file.Close();


}


void CNoteDlg::SaveTimelist() {
	//Writing the static number of Time  
	ofstream myfile("TIMEMESSAGEINFONEW_ALLNUMBER.txt");
	myfile << TimeMessage::numberOfTimeMessage;
	myfile.close();


	//Wrinting the TODO list


	CFile file;
	file.Open(L"TIMEMESSAGEINFONEW.hse", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	iterator_timeMessage = listTimeMessage.begin();
	for (int i = 0; i < TimeMessage::numberOfTimeMessage; i++) {
		iterator_timeMessage->Serialize(ar);
		iterator_timeMessage++;
	}
	ar.Close();
	file.Close();
}


void CNoteDlg::OnBnClickedButtonRedo()
{
	CNoteDlg::OpenToDolist();
	CNoteDlg::OpenTimelist();
	Invalidate();
	UpdateWindow();
}


void CNoteDlg::OpenToDolist(){
	listTODO.clear();

	//Writing the static number of TODO  
	string line;
	ifstream myfile("TODOMESSAGEINFONEW_ALLNUMBER.txt");
	while (getline(myfile, line))
	{
		ToDoMessage::numberOfTODO = std::stoi(line);
	}

	//Reading the list
	CFile file;
	file.Open(L"TODOMESSAGEINFONEW.hse", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	iterator_todo = listTODO.begin();
	for (int i = 0; i < ToDoMessage::numberOfTODO; i++) {
		ToDoMessage temp;
		temp.Serialize(ar);
		listTODO.push_back(temp);

	}
	ar.Close();
	file.Close();
	myfile.close();

}


void CNoteDlg::OpenTimelist(){

	listTimeMessage.clear();

	//Writing the static number of TimeMessage  
	string line;
	ifstream myfile("TIMEMESSAGEINFONEW_ALLNUMBER.txt");
	while (getline(myfile, line))
	{
		TimeMessage::numberOfTimeMessage = std::stoi(line);
	}

	//Reading the list
	CFile file;
	file.Open(L"TIMEMESSAGEINFONEW.hse", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	iterator_todo = listTODO.begin();
	for (int i = 0; i < TimeMessage::numberOfTimeMessage; i++) {
		TimeMessage temp;
		temp.Serialize(ar);
		listTimeMessage.push_back(temp);

	}
	ar.Close();
	file.Close();
	myfile.close();


}


void CNoteDlg::OnBnClickedButtonRight()
{
	status *= -1;
	if(status == 1)
	m_title.SetWindowTextW(L"To Do List");
	else
	m_title.SetWindowTextW(L"Time Stamps");

	Invalidate();
	UpdateWindow();
}


void CNoteDlg::OnBnClickedButtonLeft()
{
	status *= -1;
	if (status == 1)
		m_title.SetWindowTextW(L"To Do List");
	else
		m_title.SetWindowTextW(L"Time Stamps");
	Invalidate();
	UpdateWindow();
}
