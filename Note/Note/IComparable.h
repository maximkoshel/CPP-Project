#pragma once



class IComparable
{

public:

	virtual ~IComparable() {};


	virtual bool operator > (const IComparable&)const = 0;
	virtual bool operator < (const IComparable&)const = 0;
};
