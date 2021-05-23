#include "pch.h"
#include "Segment.h"
#include "Figure2D.h"
#include <iostream>
using namespace std;
Segment::Segment(CPoint& p1, CPoint& p2)
{
	//Figure2D::Figure2D(p1, p2);
	/*this->setStartPoint(CPoint(min(p1.x, p2.x), min(p1.y, p2.y)));
	this->setEndPoint(CPoint(max(p1.x, p2.x), max(p1.y, p2.y)));
	this->setLength(abs(p1.x - p2.x));
	this->setHeight(abs(p1.y - p2.y));*/
	this->setStartPoint(p1);
	this->setEndPoint(p2);
	this->setLength(abs(p1.x - p2.x));
	this->setHeight(abs(p1.y - p2.y));
}
double  Segment::Area()const
{
	return 0;
}
double Segment::Perimeter()const
{
	return sqrt(this->getLength() * this->getLength() + this->getHeight() * this->getHeight());
}
int Segment::whoAmI()
{
	return 1;
}


