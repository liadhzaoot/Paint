#pragma once
#include "Figure2D.h"
#include <iostream>
using namespace std;

class Segment : public Figure2D
{
private:
	//bool _isUtoD;//is up to down or down to up
	//bool checkSegmentDirection(CPoint& p1, CPoint& p2) const; // check the direction of segment
	

public:
	Segment(CPoint&, CPoint&);
	/*virtual void print();
	virtual void Resize(double newL, double newH);
	virtual void Shift(double dx, double dy);*/
	virtual int whoAmI();
	virtual double Area()const;
	virtual double Perimeter()const;

};

