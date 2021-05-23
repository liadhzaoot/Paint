#include "pch.h"
#include "MyRectangle.h"
#include "Figure2D.h"
#include <math.h>
#include <iostream>
using namespace std;

MyRectangle::MyRectangle(CPoint& p1, CPoint& p2) :Figure2D(p1, p2)
{
	//Figure2D::Figure2D(p1, p2);
	//this->setStartPoint(CPoint(min(p1.x, p2.x), min(p1.y, p2.y)));
	//this->setEndPoint(CPoint(max(p1.x, p2.x), max(p1.y, p2.y)));
	//this->setLength(abs(p1.x - p2.x));
	//this->setHeight(abs(p1.y - p2.y));
	//this->setStartPoint(CPoint(min(p1.x,p2.x),min(p1.y,p2.y)));
	//this->setEndPoint(CPoint(max(p1.x, p2.x), max(p1.y, p2.y)));
	//this->setLength(abs(p1.x - p2.x));
	//this->setHeight(abs(p1.y - p2.y));

}
MyRectangle::MyRectangle()
{
	this->setStartPoint(CPoint(0,0));
	this->setEndPoint(CPoint(0, 0));
	this->setLength(0);
	this->setHeight(0);
	//this->setName("");
}
int MyRectangle::whoAmI()
{
	return 2;
}
//void  MyRectangle::draw(const CClientDC& canvas)
//{
//	CBrush b(RGB(255, 0, 0));
//	canvas.SelectObject(b);
//}
//double MyRectangle::getMinOrMax(double n1, double n2, bool isMin)
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
//void MyRectangle::print()
//{
//	cout <<  ": Point(" << this->_p1.x << "," << this->_p1.y << ")-" <<
//		"Point(" << this->_p2.x << "," << this->_p2.y << ")" << endl;
//}
////void MyRectangle::Resize(double newL, double newH)
////{
////	this->_p2.SetPoint(this->_p2.x + (newL - this->getLength()), this->_p2.y + newH - this->getHeight());
////	Figure2D::Resize(newL, newH);
////}
//void MyRectangle::Shift(double dx, double dy)
//{
//	this->_p1.SetPoint(this->_p1.x + dx, this->_p1.y + dy);
//	this->_p2.SetPoint(this->_p2.x + dx, this->_p2.y + dy);
//	Figure2D::Shift(dx, dy);
//}