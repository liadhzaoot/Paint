#pragma once
#include "Figure2D.h"
#include "MyEllipse.h"
#include <iostream>
#include <math.h>
using namespace std;
class MyCircle : public MyEllipse
{
private:
	CPoint _center;
	double _radius;
	const double pi = 3.1415926535897931;
public:
	MyCircle( CPoint&, double r);
	MyCircle( CPoint&, CPoint&);
	virtual double Area()const;
	virtual double Perimeter()const;
	virtual int whoAmI();
	//virtual void Resize(double newL, double newH);
	//virtual void Shift(double dx, double dy);
	//virtual void print();
	//double getMinOrMax(double n1, double n2, bool isMin);
	CPoint getCenter()const;

	void setCenter(CPoint& center);
	int getRadius()const;
	void setRadius(double radius);
	bool isInside(CPoint& P);
};


