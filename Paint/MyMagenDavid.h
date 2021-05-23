#pragma once
#include "Figure2D.h"
#include "Segment.h"
#include <atltypes.h>
class MyMagenDavid :public Segment
{
private:
	//------------------regular triangle ------------------------
	CPoint _topPoint;
	CPoint _leftBottomPoint;
	CPoint _rightBottomPoint;
	//-------------------opposite triangle---------------------
	CPoint _buttomPoint;
	CPoint _topLeftPoint;
	CPoint _topRightPoint;
	//----------------------------------------------------------
public:
	//----------------------regular triangle------------------
	MyMagenDavid(CPoint startP, CPoint endP);
	CPoint getTopPoint()const;
	void setTopPoint(CPoint& topPoint);

	CPoint getLeftBottomPoint()const;
	void setLeftBottomPoint(CPoint& LeftBottomPoint);

	CPoint getRightBottomPoint()const;
	void setRightBottomPoint(CPoint& RightBottomPoint);
	//-------------------opposite triangle---------------------
	CPoint getButtomPoint()const;
	void setButtomPoint(CPoint& topPoint);

	CPoint getTopLeftPoint()const;
	void setTopLeftPoint(CPoint& topLeftPoint);

	CPoint getTopRightPoint()const;
	void setTopRightPoint(CPoint& topRightButtom);
	//----------------------------------
	virtual int whoAmI();
	virtual double Area()const;
	virtual double Perimeter()const;
};
