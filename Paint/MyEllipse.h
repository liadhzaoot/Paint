#pragma once
#include "Figure2D.h"
#include <iostream>
#include <math.h>
#include <atltypes.h>
using namespace std;
class MyEllipse : public Figure2D
{
private:
	//CPoint _center;
	double _radius1;
	double _radius2;
	const double _pi = 3.1415926535897931;
public:
	MyEllipse(CPoint&, CPoint&);
	MyEllipse();
	virtual double Area()const;
	virtual double Perimeter()const;
	virtual int whoAmI();
};

