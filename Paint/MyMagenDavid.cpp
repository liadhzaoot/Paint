#include "pch.h"
#include "MyMagenDavid.h"

MyMagenDavid::MyMagenDavid(CPoint startP, CPoint endP) :Segment(startP, endP)
{
	double ofset = this->getHeight() * 0.4;

		this->_topPoint.SetPoint(min(startP.x, endP.x) + (abs(endP.x - startP.x)) / 2, min(endP.y, startP.y));
	this->_leftBottomPoint.SetPoint(min(startP.x, endP.x), max(startP.y, endP.y));
	this->_rightBottomPoint.SetPoint(max(startP.x, endP.x), max(startP.y, endP.y));

	this->_topLeftPoint.SetPoint(min(startP.x, endP.x), min(endP.y, startP.y) + ofset);
	this->_topRightPoint.SetPoint(max(endP.x, startP.x), min(endP.y, startP.y) + ofset);
	this->_buttomPoint.SetPoint(min(startP.x, endP.x) + (abs(endP.x - startP.x)) / 2,
		max(endP.y, startP.y) + ofset);
}
CPoint MyMagenDavid::getTopPoint()const
{
	return this->_topPoint;
}
void MyMagenDavid::setTopPoint(CPoint& topPoint)
{
	this->_topPoint = topPoint;
}

CPoint MyMagenDavid::getLeftBottomPoint()const
{
	return this->_leftBottomPoint;
}
void MyMagenDavid::setLeftBottomPoint(CPoint& LeftBottomPoint)
{
	this->_leftBottomPoint = LeftBottomPoint;
}

CPoint MyMagenDavid::getRightBottomPoint()const
{
	return this->_rightBottomPoint;
}
void MyMagenDavid::setRightBottomPoint(CPoint& RightBottomPoint)
{
	this->_rightBottomPoint = RightBottomPoint;
}
//-------------------opposite triangle---------------------
CPoint MyMagenDavid::getButtomPoint()const
{
	return this->_buttomPoint;
}
void MyMagenDavid::setButtomPoint(CPoint& buttomPoint)
{
	this->_buttomPoint = buttomPoint;
}

CPoint MyMagenDavid::getTopLeftPoint()const
{
	return this->_topLeftPoint;
}
void MyMagenDavid::setTopLeftPoint(CPoint& topLeftPoint)
{
	this->_topLeftPoint = topLeftPoint;
}

CPoint MyMagenDavid::getTopRightPoint()const
{
	return this->_topRightPoint;
}
void MyMagenDavid::setTopRightPoint(CPoint& topRightButtom)
{
	this->_topRightPoint = topRightButtom;
}
//----------------------------------
int MyMagenDavid::whoAmI()
{
	return 8;
}
double MyMagenDavid::Area()const
{
	return 0;
}
double MyMagenDavid::Perimeter()const
{
	return 0;
}