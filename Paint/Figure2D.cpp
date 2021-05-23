//#define _CRT_SECURE_NO_WARNINGS
#pragma once
#include "pch.h"
#include "Figure2D.h"
#include "string.h"
#include <string.h>
#include <math.h>
#include <iostream>

using namespace std;

Figure2D::Figure2D(double l, double h, double x, double y):_startP(x,y),_endP(x+l,y+l),_penSize(1), _penStyle(PS_SOLID){
	
	this->_penColor = RGB(255, 255, 255);
	this->_brushColor = RGB(255, 255, 255);
	this->_length = abs(this->getStartPoint().x - this->getEndPoint().x);
	this->_height = abs(this->getStartPoint().y - this->getEndPoint().y);
}
Figure2D::Figure2D(const Figure2D& f):_penSize(1), _penStyle(PS_SOLID)
{
	//this->MoveTo(f.getStartPoint().x, f.getStartPoint().y);
	//this->Resize(f.getLength(), f.getHeight());
	this->_penColor = RGB(255, 255, 255);
	this->_brushColor = RGB(255, 255, 255);
	this->_length = abs(this->getStartPoint().x - this->getEndPoint().x);
	this->_height = abs(this->getStartPoint().y - this->getEndPoint().y);
}
Figure2D::Figure2D():_penSize(1), _penStyle(PS_SOLID)
{
	//const char* s = "";
	/*this->Resize(0, 0);
	this->MoveTo(0, 0);*/
	this->_penColor =RGB(255,255,255);
	this->_brushColor = RGB(255, 255, 255);
	this->setStartPoint(CPoint(0, 0));
	this->setEndPoint(CPoint(0, 0));
	this->_length = abs(this->getStartPoint().x - this->getEndPoint().x);
	this->_height = abs(this->getStartPoint().y - this->getEndPoint().y);
}
//virtual
Figure2D::~Figure2D()
{
}
Figure2D::Figure2D(CPoint& p1, CPoint& p2): _penSize(1), _penStyle(PS_SOLID)
{
	this->setStartPoint(CPoint(min(p1.x, p2.x), min(p1.y, p2.y)));
	this->setEndPoint(CPoint(max(p1.x, p2.x), max(p1.y, p2.y)));
	this->setLength(abs(p1.x - p2.x));
	this->setHeight(abs(p1.y - p2.y));
	//this->_length = abs(this->getStartPoint().x - this->getEndPoint().x);
	//this->_height = abs(this->getStartPoint().y - this->getEndPoint().y);
}
const Figure2D& Figure2D::operator=(Figure2D& d)
{
	//this->MoveTo(d.getStartPoint().x, d.getStartPoint().y);
	//this->Resize(d.getLength(), d.getHeight());
	this->_penColor = d.getPenColor();
	this->_brushColor = d.getBrushColor();
	this->_length = d._length;
	this->_height = d._height;
	//this->setBrushColor(d.getBrushColor()[0], d.getBrushColor()[1], d.getBrushColor()[2]);
	//this->setPenColor(d.getPenColor()[0], d.getPenColor()[1], d.getPenColor()[2]);
	return *this;
}
CPoint Figure2D::getStartPoint()const
{
	return this->_startP;
}
CPoint Figure2D::getEndPoint()const
{
	return this->_endP;
}
//double Figure2D::getX()const
//{
//	return this->x;
//}
//double Figure2D::getY()const
//{
//	return this->y;
//}
double Figure2D::getLength()const
{
	return this->_length;
}
double Figure2D::getHeight()const
{
	return this->_height;
}
//virtual
double Figure2D::Area()const
{
	return this->_length * this->_height;
}
////virtual
double Figure2D::Perimeter()const
{
	return 2 * this->_length + 2 * this->_height;
}
//void Figure2D::Shift(double dx, double dy)
//{
//	this->x += dx;
//	this->y += dy;
//}
//void Figure2D::MoveTo(double newX, double newY)
//{
//	this->x = newX;
//	this->y = newY;
//}
//void Figure2D::Resize(double newL, double newH)
//{
//	this->length = newL;
//	this->height = newH;
//}
//void Figure2D::Scale(double kx, double ky)
//{
//	this->Resize(kx * this->getLength(), ky * this->getHeight());
//}
//Point(P->getX(),P->getY()) lies inside the figure
bool Figure2D::isInside(CPoint& P)const
{
	if ((P.x > this->getStartPoint().x && 
		P.x < this->getStartPoint().x + this->getLength()) &&
		P.y > this->getStartPoint().y &&
		P.y < this->getStartPoint().y + this->getHeight())
		return true;
	return false;
}
void Figure2D::setPenColor(const COLORREF color)
{
	this->_penColor = color;
}
void Figure2D::setBrushColor(const COLORREF color)
{
	this->_brushColor = color;
}
COLORREF Figure2D::getPenColor()const
{
	return this->_penColor;
}
COLORREF Figure2D::getBrushColor()const
{
	return this->_brushColor;

}
void  Figure2D::setPenSize(const int size)
{
	this->_penSize = size;
}
int  Figure2D::getPenSize()const
{
	return this->_penSize;
}
int Figure2D::getPenStyle()const
{
	return this->_penStyle;
}
void Figure2D::getPenStyle(const int penStyle)
{
	this->_penStyle = penStyle;
}
void Figure2D::setStartPoint(const CPoint p)
{
	this->_startP = p;
}
void Figure2D::setEndPoint(const CPoint p )
{
	this->_endP = p;
}
void Figure2D::setLength(const int length)
{
	this->_length = length;
}
void Figure2D::setHeight(const int height)
{
	this->_height = height;

}
int Figure2D::whoAmI()
{
	return 0;
}
//void Figure2D::draw(const CClientDC& canvas)
//{
//	
//}
//COLORREF Figure2D::getPenRGB()const
//{
//	return RGB(this->getPenColor()[0], this->getPenColor()[1], this->getPenColor()[2]);
//}
//COLORREF Figure2D::getBrushRGB()const
//{
//	return RGB(this->getBrushColor()[0], this->getBrushColor()[1], this->getBrushColor()[2]);
//}

