#pragma once
#include "Figure2D.h"
#include "Segment.h"
class MyTriangle:public Segment 
{
private:
	CPoint _topPoint;
	CPoint _leftBottomPoint;
	CPoint _rightBottomPoint;

public:
	MyTriangle(CPoint startP, CPoint endP);
	CPoint getTopPoint()const;
	void setTopPoint(CPoint& topPoint);

	CPoint getLeftBottomPoint()const;
	void setLeftBottomPoint(CPoint& topPoint);

	CPoint getRightBottomPoint()const;
	void setRightBottomPoint(CPoint& topPoint);

	virtual int whoAmI();
	virtual double Area()const;
	virtual double Perimeter()const;

};

