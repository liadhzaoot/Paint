#pragma once
#include <math.h>
#include <iostream>
#include "PaintDlg.h"
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
class Figure2D{
	friend ostream& operator<<(ostream& out, const Figure2D& other);
private:
	CPoint _startP;
	CPoint _endP;
	double _length;
	double _height;
	COLORREF _penColor;
	COLORREF _brushColor;
	int _penStyle;
	int _penSize;
	//char* name = NULL;//=NULL Needed for compiler of the testing engine
public:
	Figure2D(double l, double h, double x = 0, double y = 0);
	Figure2D(const Figure2D& f);
	Figure2D();
	Figure2D(CPoint &p1,CPoint& p2);
	~Figure2D();
	const Figure2D& operator=(Figure2D& d);
	/*double getStartX()const;
	double getStartY()const;*/
	double getLength()const;
	double getHeight()const;
	void setLength(const int length);
	void setHeight(const int height);
	CPoint getStartPoint()const;
	void setStartPoint(const CPoint);
	CPoint getEndPoint()const;
	void setEndPoint(const CPoint);
	void setPenColor(COLORREF color);
	COLORREF getPenColor()const;
	void setBrushColor(COLORREF color);
	COLORREF getBrushColor()const;
	void setPenSize(const int size);
	int getPenSize()const;
	int getPenStyle()const;
	void getPenStyle(const int penStyle );

	virtual int whoAmI();
	//virtual void draw(const CClientDC&);
	virtual double Area()const;
	virtual double Perimeter()const;
	//virtual void Shift(double dx, double dy);
	//void MoveTo(double newX, double newY);
	//virtual void Resize(double newL, double newH);
	//virtual void Scale(double kx, double ky);
	virtual bool isInside(CPoint& P)const;//Point(P->getX(),P->getY()) lies inside the figure
};

