#pragma once
#include "Figure2D.h"
#include "PaintDlg.h"
#include <atltypes.h>
using namespace std;

class MyRectangle : public Figure2D
{
private:

public:
	MyRectangle(CPoint&, CPoint&);
	MyRectangle();
	//virtual void draw(const CClientDC&);
	virtual int whoAmI();
	/*double getMinOrMax(double n1, double n2, bool isMin);
	virtual void print();
	virtual void Shift(double dx, double dy);*/

};

