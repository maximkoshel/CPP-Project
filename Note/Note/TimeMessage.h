#pragma once
#include "ToDoMessage.h"
#include "IComparable.h"
#include "pch.h"

class TimeMessage:  public IComparable, public ToDoMessage 
{
public:

	static int numberOfTimeMessage;

	TimeMessage(void);

	TimeMessage(const TimeMessage&);

	TimeMessage(CString, CString, COLORREF,int,int,int,int,int);

	int GetDay()const;
	int GetMonth()const;
	int GetYear()const;
	int GetHours()const;
	int GetMinutes()const;

	void SetDay(int);
	void SetMonth(int);
	void SetYear(int);
	void SetHours(int);
	void SetMinutes(int);

	virtual ~TimeMessage() {};

	bool operator > (const IComparable&)const;

	bool operator < (const IComparable&)const;

	void equels (TimeMessage some);

	TimeMessage SendAllDate();

	void Serialize(CArchive&);

	void Draw(CPaintDC *, int x, int y);

	void DrawNumber(CPaintDC *, int x, int y, CString);

protected:
DECLARE_SERIAL(TimeMessage);
int day, month, year, hours, minutes;
};

