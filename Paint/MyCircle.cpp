#include "pch.h"
#include "MyCircle.h"
#include "MyEllipse.h"
#include "Figure2D.h"
#include <math.h>
MyCircle::MyCircle( CPoint& p1, double r)
{
	/*this->MoveTo(p1.x, p1.y);
	this->Resize(2 * r, 2 * r);*/
	//this->_center.SetPoint((p1.x + p1.x + this->getLength()) / 2, (p1.y + p1.y + this->getHeight()) / 2);
	this->_radius = r;
}
MyCircle::MyCircle(CPoint& p1, CPoint& p2)
{

	double size = min(abs(p1.x - p2.x), abs(p1.y - p2.y));
	this->setStartPoint(CPoint(min(p1.x,p2.x), min(p1.y, p2.y)));
	this->setEndPoint(CPoint(this->getStartPoint().x + size, this->getStartPoint().y + size));
	this->setLength(size);
	this->setHeight(size);
	this->_center.SetPoint(p1.x + abs(p1.x - p2.x), p1.y + abs(p1.y - p2.y));
	this->_radius = this->getHeight() / 2;
}
int MyCircle::whoAmI()
{
	return 4;
}
//virtual
double MyCircle::Area()const
{
	return this->_radius * this->_radius * pi;
}
//virtual
double MyCircle::Perimeter()const
{
	return 2 * pi * this->_radius;
}

////void MyCircle::Resize(double newL, double newH)
////{
////	Figure2D::Resize(newL, newH);
////	this->_center.SetPoint((this->getX() + this->getX() + this->getLength()) / 2, (this->getY() + this->getY() + this->getHeight()) / 2);
////	this->setRadius(this->getMinOrMax(this->_center.x - this->getX(), this->_center.y - this->getY(), true));
////}
//void MyCircle::Shift(double dx, double dy)
//{
//	this->_center.SetPoint(this->_center.x + dx, this->_center.y + dy);
//	Figure2D::Shift(dx, dy);
//}
//void MyCircle::print()
//{
//	cout << ", with center" << "(" <<
//		this->getCenter().x << "," << this->getCenter().y << ")"
//		<< " and radius = " << this->getRadius() << endl;
//}

CPoint  MyCircle::getCenter()const
{
	return this->_center;
}
int  MyCircle::getRadius()const
{
	return this->_radius;

}
void  MyCircle::setCenter(CPoint& center)
{
	this->_center = center;
}
void  MyCircle::setRadius(double radius)
{
	this->_radius = radius;
}
//double MyCircle::getMinOrMax(double n1, double n2, bool isMin)
//{
//	if (isMin)//return min if isMin = true
//	{
//		if (n1 < n2)
//			return n1;
//		else
//			return n2;
//	}
//	else//return max if isMin = false
//	{
//		if (n1 > n2)
//			return n1;
//		else
//			return n2;
//	}
//	return NULL;
//}
bool MyCircle::isInside(CPoint& P)
{
	double distance = sqrt(pow(P.x - (this->getStartPoint().x + this->getLength() / 2), 2) + pow(P.y - (this->getStartPoint().y + getHeight() / 2), 2));
	if (distance < this->getRadius())return true;
	return false;
}
