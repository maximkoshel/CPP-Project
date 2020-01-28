#pragma once

#include "VMessage.h"

class ToDoMessage: public VMessage, public CObject
{
public:
	static int numberOfTODO;

	ToDoMessage(void);

	ToDoMessage(const ToDoMessage&);

	virtual ~ToDoMessage() {};

	 ToDoMessage(CString,CString,COLORREF);

	 virtual void SetColor(COLORREF);
	 virtual COLORREF GetColor()const;

	 virtual void SetText(CString);
	 virtual CString GetText()const;

	 virtual void SetFont(CString);
	 virtual CString GetFont()const;

	 virtual void Draw(CPaintDC *,int x,int y);
	 virtual void DrawNumber(CPaintDC *, int x, int y,CString);

	 void Serialize(CArchive&);

protected:
	COLORREF color;
	CString txt;
	CString Font;
	DECLARE_SERIAL(ToDoMessage);

};

