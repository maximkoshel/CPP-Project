#include "pch.h"
#include "TimeMessage.h"
#include "NoteDlg.h"
IMPLEMENT_SERIAL(TimeMessage, CObject, 0)

TimeMessage::TimeMessage() {

}

TimeMessage::TimeMessage(const TimeMessage& other) {
	this->txt = other.txt;
	this->color = other.color;
	this->Font = other.Font;
	this->day = other.day;
	this->month = other.month;
	this->year = other.year;
	this->hours = other.hours;
	this->minutes = other.minutes;
}

TimeMessage::TimeMessage(CString txt, CString font, COLORREF color, int day, int month, int year, int hours, int minutes):ToDoMessage(txt,font,color) {
	this->day = day;
	this->month = month;
	this->year = year;
	this->hours = hours;
	this->minutes = minutes;
}

int TimeMessage::GetDay()const {
	return this->day;
}

int TimeMessage::GetMonth()const {
	return this->month;

}

int TimeMessage::GetYear()const {
	return this->year;

}

int TimeMessage::GetHours()const {
	return this->hours;

}

int TimeMessage::GetMinutes()const {
	return this->minutes;

}

bool TimeMessage:: operator > (const IComparable& other) const {

	const TimeMessage* temp = dynamic_cast<const TimeMessage*>(&other);

	if (this->year > temp->GetYear())
		return true;
	if (this->year < temp->GetYear())
		return false;
	if (this->month > temp->GetMonth())
		return true;
	if (this->month < temp->GetMonth())
		return false;
	if (this->month == temp->GetMonth()&&this->day > temp->GetDay())
		return true;
	if (this->month == temp->GetMonth() && this->day < temp->GetDay())
		return false;

	return false;
}

bool TimeMessage:: operator < (const IComparable& other) const {

	const TimeMessage* temp = dynamic_cast<const TimeMessage*>(&other);
	if (this->year < temp->GetYear())
		return true;
	if (this->month < temp->GetMonth())
		return true;
	if (this->day < temp->GetDay())
		return true;
	if (this->hours < temp->GetHours())
		return true;
	if (this->minutes < temp->GetMinutes())
		return true;

	return false;
}

void TimeMessage::Serialize(CArchive& ar) {
	CObject::Serialize(ar);
	if (ar.IsStoring()) {
		ar << this->txt << this->color << this->Font << this->year << this->month << this->day << this->hours << this->minutes;
	}
	else
	{
		ar >> this->txt >> this->color >> this->Font >> this->year >> this->month >> this->day >> this->hours >> this->minutes;

	}
}

void TimeMessage::Draw(CPaintDC *points, int x, int y) {

	CFont font;
	font.CreateFontW(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, this->Font);
	CFont *oldfont = points->SelectObject(&font);
	points->SetTextColor(this->color);

	CString Syear, Smonth, Sday, Shours, Sminutes;
	Syear.Format(_T("%d"),year);
	Smonth.Format(_T("%d"), month);
	Sday.Format(_T("%d"), day);
	Shours.Format(_T("%d"), hours);
	Sminutes.Format(_T("%d"), minutes);


	points->TextOutW(x, y, Syear+ L"/"+Smonth+ L"/"+ Sday+ L" "+Shours+ L":"+Sminutes);
	points->TextOutW(x, y+20, this->txt);

}

void TimeMessage::DrawNumber(CPaintDC *points, int x, int y, CString number) {

	CFont font;
	font.CreateFontW(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, this->Font);
	CFont *oldfont = points->SelectObject(&font);
	points->SetTextColor(this->color);

	points->TextOutW(x, y, number);
}

void  TimeMessage::equels(TimeMessage temp)  {


	this->txt = temp.GetText();
	this->color = temp.GetColor();
	this->Font = temp.GetFont();
	this->day = temp.GetDay();
	this->month = temp.GetMonth();
	this->year = temp.GetYear();
	this->hours = temp.GetHours();
	this->minutes = temp.GetMinutes();


}

TimeMessage TimeMessage::SendAllDate() {
	TimeMessage temp;
	temp.SetText(this->txt);
	temp.SetColor(this->color);
	temp.SetFont(this->Font);
	temp.SetYear(this->year);
	temp.SetMonth(this->month);
	temp.SetDay(this->day);
	temp.SetHours(this->hours);
	temp.SetMinutes(this->minutes);
	return temp;
}

void TimeMessage::SetDay(int day) {
	this->day = day;
}
void TimeMessage::SetMonth(int month) {
	this->month = month;
}
void TimeMessage::SetYear(int year) {
	this->year = year;
}
void TimeMessage::SetHours(int hours) {
	this->hours = hours;
}
void TimeMessage::SetMinutes(int minutes) {
	this->minutes = minutes;
}