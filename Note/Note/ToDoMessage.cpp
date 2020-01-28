#include "pch.h"
#include "ToDoMessage.h"
#include "NoteDlg.h"
#include "VMessage.h"


IMPLEMENT_SERIAL(ToDoMessage, CObject, 0)

ToDoMessage::ToDoMessage(void) {

}

ToDoMessage::ToDoMessage(const ToDoMessage &msg) {
	this->color = msg.GetColor();
	this->Font = msg.GetFont();
	this->txt = msg.GetText();
}

ToDoMessage::ToDoMessage(CString txt, CString font, COLORREF color) {
	this->color = color;

	this->Font = font;
	this->txt = txt;
}

 void ToDoMessage::SetColor(COLORREF color) {
	 this->color = color;
}

 COLORREF ToDoMessage::GetColor()const {
	 return this->color;
 }

 void ToDoMessage::SetText(CString txt){
	 this->txt = txt;
 }

 CString ToDoMessage::GetText()const{
	 return this->txt;
 }

void ToDoMessage::SetFont(CString fonta){
	this->Font = fonta;
}

CString ToDoMessage::GetFont()const {
	return this->Font;
 }

void ToDoMessage::Draw(CPaintDC *points,int x,int y) {
	
	CFont font;
	font.CreateFontW(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, this->Font);
	CFont *oldfont = points->SelectObject(&font);
	points->SetTextColor(this->color);
	
	points->TextOutW(x, y, this->txt);
}

void ToDoMessage::DrawNumber(CPaintDC *points, int x, int y,CString number) {

	CFont font;
	font.CreateFontW(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, this->Font);
	CFont *oldfont = points->SelectObject(&font);
	points->SetTextColor(this->color);

	points->TextOutW(x, y, number);
}

void ToDoMessage::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->color << this->Font;
	 }
	else
	{
		ar >> this->txt >> this->color >> this->Font;

	}
 }