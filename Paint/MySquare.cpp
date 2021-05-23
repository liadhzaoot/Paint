#include "pch.h"
#include "MySquare.h"
#include "Figure2D.h"
MySquare::MySquare(CPoint p1, CPoint p2)
{
	//Figure2D::Figure2D(p1, p2);
	this->setStartPoint(CPoint(min(p1.x, p2.x), min(p1.y, p2.y)));
	this->setEndPoint(CPoint(max(p1.x, p2.x), max(p1.y, p2.y)));
	this->setLength(abs(p1.x - p2.x));
	this->setHeight(abs(p1.y - p2.y));
	//this->setStartPoint(p1);
	//this->setEndPoint(p2);
	//this->setLength(abs(p1.x - p2.x));
	//this->setHeight(abs(p1.y - p2.y));
}
MySquare::MySquare(CPoint& p1, int size)
{
	this->setStartPoint(p1);
	this->setEndPoint(CPoint(p1.x+size,p1.y+size));
	this->setLength(size);
	this->setHeight(size);
	this->size = size;
}
int  MySquare::whoAmI()
{
	return 5;
}
int MySquare::getSize()const
{
	return this->size;
}
void MySquare::setSize(const int size)
{
	this->size = size;
}