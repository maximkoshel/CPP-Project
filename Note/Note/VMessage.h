#pragma once

#include "pch.h"
#include "resource.h"
#include <iostream>
using namespace std;



class VMessage
{
public :

	virtual ~VMessage() {};
	virtual void SetColor(COLORREF) = 0;
	virtual COLORREF GetColor()const = 0;

	virtual void SetText(CString) = 0;
	virtual CString GetText() const = 0 ;

	virtual void SetFont(CString) = 0;
	virtual CString GetFont() const = 0 ;
	virtual void Serialize(CArchive&)=0;



};


