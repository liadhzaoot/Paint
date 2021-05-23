#include "pch.h"
#include "MyEllipse.h"
MyEllipse::MyEllipse(CPoint& p1, CPoint& p2):Figure2D(p1, p2)
{
	
	//this->setStartPoint(p1);
	//this->setEndPoint(p2);
	//this->setLength(abs(p1.x - p2.x));
	//this->setHeight(abs(p1.y - p2.y));
	this->_radius1 = this->getHeight() / 2;
	this->_radius2 = this->getLength() / 2;
}
MyEllipse::MyEllipse() :_radius1(0), _radius2(0)
{

}

double MyEllipse::Area()const
{
	return this->_radius1 * this->_radius2 * this->_pi;
}
double MyEllipse::Perimeter()const
{
	return (sqrt((this->_radius1 * this->_radius1) + (this->_radius2 * this->_radius2)) / 2) * this->_pi;
}
int MyEllipse::whoAmI()
{
	return 6;
}