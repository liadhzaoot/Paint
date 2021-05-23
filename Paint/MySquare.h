#pragma once
#include "MyRectangle.h"
class MySquare :public MyRectangle
{
private:
	int size;
public:
	MySquare(CPoint p1, CPoint p2);
	MySquare(CPoint& p1, int size);
	virtual int whoAmI();
	int getSize()const;
	void setSize(const int size);
};

