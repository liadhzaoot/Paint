#include "pch.h"
#include "MyTriangle.h"
#include "Segment.h"
MyTriangle::MyTriangle(CPoint startP,CPoint endP) :Segment(startP, endP)
{
	this->_topPoint.SetPoint(min(startP.x, endP.x) + (abs(endP.x - startP.x)) / 2, min(endP.y, startP.y));
	this->_leftBottomPoint.SetPoint(min(startP.x, endP.x), max(startP.y, endP.y));
	this->_rightBottomPoint.SetPoint(max(startP.x, endP.x), max(startP.y, endP.y));
}
CPoint MyTriangle::getTopPoint()const
{
	return this->_topPoint;
}
void MyTriangle::setTopPoint(CPoint& topPoint)
{
	this->_topPoint = topPoint;
}

CPoint MyTriangle::getLeftBottomPoint()const
{
	return this->_leftBottomPoint;
}
void MyTriangle::setLeftBottomPoint(CPoint& leftBottomPoint)
{
	this->_leftBottomPoint = leftBottomPoint;
}

CPoint MyTriangle::getRightBottomPoint()const
{
	return this->_rightBottomPoint;
}
void MyTriangle::setRightBottomPoint(CPoint& rightBottomPoint)
{
	this->_rightBottomPoint = rightBottomPoint;
}
int MyTriangle::whoAmI()
{
	return 7;
}
double MyTriangle::Area()const
{
	return (this->getLength() * this->getHeight()) * 2;
}
double MyTriangle::Perimeter()const
{
	Segment s1(CPoint(this->_topPoint.x,this->_topPoint.y), CPoint(this->_leftBottomPoint.x, this->_leftBottomPoint.y));
	Segment s2(CPoint(this->_topPoint.x,this->_topPoint.y), CPoint(this->_rightBottomPoint.x, this->_rightBottomPoint.y));
	Segment s3(CPoint(this->_rightBottomPoint.x,this->_rightBottomPoint.y), CPoint(this->_leftBottomPoint.x, this->_leftBottomPoint.y));

	return s1.Perimeter() + s2.Perimeter() + s3.Perimeter();
}