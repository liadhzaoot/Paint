
// PaintDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "Paint.h"
#include "PaintDlg.h"
#include "afxdialogex.h"
#include "Segment.h"
#include "Figure2D.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "MyRectangle.h"
#include "MyCircle.h"
#include "MySquare.h"
#include "MyEllipse.h"
#include "MyTriangle.h"
#include "MyMagenDavid.h"
#include "math.h"
#include <stack>
#include<fstream>

using namespace std;

stack<Figure2D*> figureStack;
stack<Figure2D*> redoStack;
stack<Figure2D*> helpStack;
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	
// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPaintDlg dialog



CPaintDlg::CPaintDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PAINT_DIALOG, pParent),
	_mouseDownPoint(0, 0),
	_brush(RGB(1, 1, 1)),
	_shape(Line),
	_mouseUpPoint(0, 0),
	_penStyle(PS_SOLID)
	, PenSizeBox(1)
{
	//figureArr = new Figure2D*[100];
	
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPaintDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, ID_PenSize, PenSizeBox);
	DDX_Control(pDX, IDC_BrushColorButton, brushColorButton);
	DDX_Control(pDX, IDC_PenColorButton, PenColorButton);
}

BEGIN_MESSAGE_MAP(CPaintDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_Line, &CPaintDlg::OnBnClickedLine)
	ON_BN_CLICKED(IDC_Rectangle, &CPaintDlg::OnBnClickedRectangle)
	ON_WM_LBUTTONDOWN()
	ON_WM_NCLBUTTONUP()
	ON_WM_LBUTTONUP()
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_FreeDraw, &CPaintDlg::OnBnClickedFreedraw)
	ON_BN_CLICKED(IDC_CircleButton, &CPaintDlg::OnBnClickedCirclebutton)
	ON_BN_CLICKED(IDC_Square, &CPaintDlg::OnBnClickedSquare)
	ON_BN_CLICKED(IDC_UndoBottun, &CPaintDlg::OnBnClickedUndobottun)
	ON_BN_CLICKED(IDC_SaveBtn, &CPaintDlg::OnBnClickedSavebtn)
	ON_BN_CLICKED(IDC_Load, &CPaintDlg::OnBnClickedLoad)
	ON_BN_CLICKED(IDC_RedoButton, &CPaintDlg::OnBnClickedRedobutton)
	ON_BN_CLICKED(IDC_EllipseBtn, &CPaintDlg::OnBnClickedEllipsebtn)
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDOWN()
	ON_BN_CLICKED(IDC_Triangle, &CPaintDlg::OnBnClickedTriangle)
	ON_BN_CLICKED(IDC_Clear, &CPaintDlg::OnBnClickedClear)
	ON_BN_CLICKED(IDC_MagenDavid, &CPaintDlg::OnBnClickedMagendavid)
END_MESSAGE_MAP()


// CPaintDlg message handlers

BOOL CPaintDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPaintDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPaintDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPaintDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}
void CPaintDlg::OnBnClickedLine()
{
	_shape = Line;
}


void CPaintDlg::OnBnClickedRectangle()
{
	_shape = Rectangle;
}

void CPaintDlg::OnBnClickedFreedraw()
{
	_shape = FreeDraw;
}

void CPaintDlg::OnLButtonDown(UINT nFlags, CPoint point)
{
	_isLButtonClicked = true;
	_mouseDownPoint.SetPoint(point.x, point.y);
	//checkIsInside(_mouseDownPoint);
	CDialogEx::OnLButtonDown(nFlags, point);
	
}


void CPaintDlg::OnLButtonUp(UINT nFlags, CPoint point)
{
	_isLButtonClicked = false;
	_mouseUpPoint.SetPoint(point.x, point.y);
	CClientDC canvas(this);
	if (_shape == Line)// create Line
	{
		drawLine();
	}
	else if (_shape == Rectangle)// create Rectangle
	{
		drawRectangle();
	}
	else if (_shape == Circle)
	{
		drawCircle();
	}
	else if (_shape == Square)
	{
		drawSquare();
	}
	else if (_shape == Ellipse)
	{
		drawEllipse();
	}
	else if (_shape == Triangle)
	{
		drawTriangle();
	}
	else if (_shape == MagenDavid)
	{
		drawMyMagenDavid();
	}
	CDialogEx::OnLButtonUp(nFlags, point);
}


void CPaintDlg::drawRectangle()
{
	CClientDC canvas(this);
	Figure2D* r = new MyRectangle(CPoint(_mouseDownPoint.x, _mouseDownPoint.y), 
					CPoint(_mouseUpPoint.x, _mouseUpPoint.y));
	r->setPenColor(PenColorButton.GetColor());
	r->setBrushColor(brushColorButton.GetColor());
	//set the pen size
	UpdateData(true);
	r->setPenSize(PenSizeBox);
	figureStack.push(r);

	this->drawTop(false, false,false);
}
void CPaintDlg::drawEllipse()
{
	CClientDC canvas(this);
	Figure2D* Ellipse = new MyEllipse(CPoint(_mouseDownPoint.x, _mouseDownPoint.y),
		CPoint(_mouseUpPoint.x, _mouseUpPoint.y));

	Ellipse->setPenColor(PenColorButton.GetColor());
	Ellipse->setBrushColor(brushColorButton.GetColor());

	//set the pen size
	UpdateData(true);
	Ellipse->setPenSize(PenSizeBox);

	figureStack.push(Ellipse);
	this->drawTop(false, false,false);
}


void CPaintDlg::drawTriangle()
{
	CClientDC canvas(this);
	Figure2D* triangle = new MyTriangle(CPoint(_mouseDownPoint.x, _mouseDownPoint.y),
		CPoint(_mouseUpPoint.x, _mouseUpPoint.y));

	triangle->setPenColor(PenColorButton.GetColor());
	triangle->setBrushColor(brushColorButton.GetColor());

	//set the pen size
	UpdateData(true);
	triangle->setPenSize(PenSizeBox);

	figureStack.push(triangle);
	this->drawTop(false, false, false);
}
void CPaintDlg::drawMyMagenDavid()
{
	CClientDC canvas(this);
	Figure2D* magenDavid = new MyMagenDavid(CPoint(_mouseDownPoint.x, _mouseDownPoint.y),
		CPoint(_mouseUpPoint.x, _mouseUpPoint.y));

	magenDavid->setPenColor(PenColorButton.GetColor());
	magenDavid->setBrushColor(brushColorButton.GetColor());

	//set the pen size
	UpdateData(true);
	magenDavid->setPenSize(PenSizeBox);

	figureStack.push(magenDavid);
	this->drawTop(false, false, false);
}
void CPaintDlg::drawSquare()
{
	CPoint startSquarePoint(min(_mouseDownPoint.x, _mouseUpPoint.x), min(_mouseDownPoint.y, _mouseUpPoint.y));
	CClientDC canvas(this);
	/*
	check the start 
	*/

	Figure2D* square = new MySquare(startSquarePoint,
					min(abs(_mouseDownPoint.x - _mouseUpPoint.x),abs( _mouseDownPoint.y - _mouseUpPoint.y)));//the size of square
	square->setPenColor(PenColorButton.GetColor());
	square->setBrushColor(brushColorButton.GetColor());

	//set the pen size
	UpdateData(true);
	square->setPenSize(PenSizeBox);

	figureStack.push(square);
	//CBrush myBrush(r->getBrushColor);
	this->drawTop(false, false,false);
}

void CPaintDlg::drawLine()
{
	CClientDC canvas(this);
	Figure2D* segment;
	segment = new Segment(CPoint(_mouseDownPoint.x, _mouseDownPoint.y),
								CPoint(_mouseUpPoint.x, _mouseUpPoint.y));
	segment->setPenColor(PenColorButton.GetColor());
	//set the pen size
	UpdateData(true);
	segment->setPenSize(PenSizeBox);

	//figureArr[0] = f1;
	figureStack.push(segment);

	this->drawTop(false, false,false);
}

void CPaintDlg::drawCircle()
{
	CClientDC canvas(this);
	Figure2D* circle = new MyCircle(CPoint(_mouseDownPoint.x, _mouseDownPoint.y),
		CPoint(_mouseUpPoint.x, _mouseUpPoint.y));

	circle->setPenColor(PenColorButton.GetColor());
	circle->setBrushColor(brushColorButton.GetColor());

	//set the pen size
	UpdateData(true);
	circle->setPenSize(PenSizeBox);

	figureStack.push(circle);
	this->drawTop(false, false,false);
}

void CPaintDlg::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (_shape == FreeDraw && _isLButtonClicked)
	{
		UpdateData(true);
		CClientDC canvas(this);
		CBrush myBrush(brushColorButton.GetColor());
		CPen myPen(PS_SOLID,1, brushColorButton.GetColor());
		canvas.SelectObject(myBrush);
		canvas.SelectObject(myPen);
		canvas.Rectangle(point.x, point.y, point.x + PenSizeBox, point.y + PenSizeBox);
		CDialogEx::OnMouseMove(nFlags, point);
	}
	
}

void CPaintDlg::OnBnClickedCirclebutton()
{
	_shape = Circle;
}

void CPaintDlg::OnBnClickedSquare()
{
	_shape = Square;

}


void CPaintDlg::OnBnClickedUndobottun()
{
	if (!figureStack.empty())
	{
		drawTop(true, false,false);

		redoStack.push(figureStack.top());

		figureStack.pop();
		this->drawAllStack();
	}
}
void CPaintDlg::drawTop(bool undo,bool redoS, bool choose)
{

	Figure2D* f = NULL;
	CString str;
	bool flag = false;
	if (redoS)
		if (!redoStack.empty())
		{
			f = redoStack.top();
			figureStack.push(f);
			//redoStack.pop();
			flag = true;
		}
	if(!redoS)
		if (!figureStack.empty())
		{
			f = figureStack.top();
			//figureStack.pop();
			flag = true;
		}
	if (flag)
	{
		CClientDC canvas(this);
		COLORREF myPenColor;
		COLORREF myBrushColor;
		int penSize = 1;
		if (undo)
		{
			 myPenColor = RGB(240, 240, 240);
			 myBrushColor = RGB(240, 240, 240);
			 penSize = f->getPenSize();
			 //redoStack.push(f);
		}
		else if(choose)
		{


			UpdateData(true);
			myPenColor = PenColorButton.GetColor();
			myBrushColor = brushColorButton.GetColor();
			penSize = PenSizeBox;
			f->setPenColor(myPenColor);
			f->setBrushColor(myBrushColor);
			f->setPenSize(penSize);
		}
		else
		{
			myPenColor = f->getPenColor();
			myBrushColor = f->getBrushColor();
			penSize = f->getPenSize();
			
		}

		//draw(myPen, myBrush, f);	
		
		CBrush myBrush(myBrushColor);
		CPen myPen(f->getPenStyle(), penSize, myPenColor);
		canvas.SelectObject(myPen);
		canvas.SelectObject(myBrush);
		
		
			if (f->whoAmI() == Rectangle || f->whoAmI() == Square)
			{
				canvas.Rectangle(f->getStartPoint().x, f->getStartPoint().y,
					f->getEndPoint().x, f->getEndPoint().y);
				str.Format(_T("shape = Type: Rectangle, Area: %08.lf, Perimeter: %07.lf"), f->Area(), f->Perimeter());
				if (f->getHeight() == f->getLength())
					str.Format(_T("shape = Type: Square, Area: %08.lf, Perimeter: %07.lf"), f->Area(), f->Perimeter());
			}
			else if (f->whoAmI() == Line)
			{
				canvas.MoveTo(f->getStartPoint().x, f->getStartPoint().y);
				canvas.LineTo(f->getEndPoint().x, f->getEndPoint().y);
				str.Format(_T("shape = Type: Line, Area: %08.lf, Perimeter: %07.lf"), f->Area(), f->Perimeter());
			}
			else if (f->whoAmI() == Ellipse || f->whoAmI() == Circle)
			{
				canvas.Ellipse(f->getStartPoint().x, f->getStartPoint().y,
					f->getEndPoint().x, f->getEndPoint().y);
				str.Format(_T("shape = Circle: Ellipse, Area: %08.lf, Perimeter: %07.lf"), f->Area(), f->Perimeter());
				if (f->getHeight() == f->getLength())
					str.Format(_T("shape = Type: Circle, Area: %08.lf, Perimeter: %07.lf"), f->Area(), f->Perimeter());
			}
			else if (f->whoAmI() == Triangle|| f->whoAmI() == MagenDavid)
			{
				
				CPoint topTriangle;
				CPoint leftBottomTriangle;
				CPoint rightBottomTriangle;
				topTriangle.SetPoint(min(f->getStartPoint().x, f->getEndPoint().x) +
					(abs(f->getStartPoint().x - f->getEndPoint().x)) / 2, min(f->getStartPoint().y, f->getEndPoint().y));
				leftBottomTriangle.SetPoint(min(f->getStartPoint().x, f->getEndPoint().x), max(f->getStartPoint().y, f->getEndPoint().y));
				rightBottomTriangle.SetPoint(max(f->getStartPoint().x, f->getEndPoint().x), max(f->getStartPoint().y, f->getEndPoint().y));
				canvas.MoveTo(topTriangle);
				canvas.LineTo(leftBottomTriangle);

				canvas.MoveTo(topTriangle);
				canvas.LineTo(rightBottomTriangle);

				canvas.MoveTo(rightBottomTriangle);
				canvas.LineTo(leftBottomTriangle);

				str.Format(_T("shape = Type: Triangle, Area: %08.lf, Perimeter: %07.lf"),f->Area(), f->Perimeter());
				if (f->whoAmI() == MagenDavid)
				{
					CPoint topLeftPoint;
					CPoint topRightPoint;
					CPoint buttomPoint;
					double ofset = f->getHeight() * 0.4;
					topLeftPoint.SetPoint(min(f->getStartPoint().x, f->getEndPoint().x), min(f->getEndPoint().y, f->getStartPoint().y) + ofset);
					topRightPoint.SetPoint(max(f->getEndPoint().x, f->getStartPoint().x), min(f->getEndPoint().y, f->getStartPoint().y) + ofset);
					buttomPoint.SetPoint(min(f->getStartPoint().x, f->getEndPoint().x)
						+ (abs(f->getEndPoint().x - f->getStartPoint().x)) / 2,
						max(f->getEndPoint().y, f->getStartPoint().y) + ofset);

					canvas.MoveTo(topLeftPoint);
					canvas.LineTo(topRightPoint);

					canvas.MoveTo(topLeftPoint);
					canvas.LineTo(buttomPoint);

					canvas.MoveTo(buttomPoint);
					canvas.LineTo(topRightPoint);
					str.Format(_T("shape = Type: MagenDavid"));

				}
			}
		
		
		canvas.TextOutW(10, 660, str);
	}
}
void CPaintDlg::saveToFile(ostream& out)
{
	int count = 0;
	while (!figureStack.empty())
	{
		count++;
		helpStack.push(figureStack.top());
		figureStack.pop();
	}
	while (!helpStack.empty())
	{
		figureStack.push(helpStack.top());
		helpStack.pop();
	}
	out.write((char*)&count, sizeof(int));
	while (!figureStack.empty())
	{
		helpStack.push(figureStack.top());
		out.write((char*)&*(figureStack.top()), sizeof(*(figureStack.top())));
		figureStack.pop();
	}
	while (!helpStack.empty())
	{
		figureStack.push(helpStack.top());
		helpStack.pop();
	}
	
}
void CPaintDlg::loadFromFile(istream& in)
{
	int count = 0;
	
	in.read((char*)&count, sizeof(int));
	Figure2D* f = new Figure2D[count];
	for (int i = 0; i < count; i++)
	{
		in.read((char*)&f[i], sizeof(Figure2D));
	}
	for (int i = 0; i < count; i++)
	{
		figureStack.push(&f[i]);

	}
	
	this->drawAllStack();
}

bool CPaintDlg::checkIsInside(CPoint &p1)
{
	bool isFound = false;
	CClientDC canvas(this);
	CPen p(PS_SOLID, 3, RGB(255, 0, 0));
	canvas.SelectObject(p);
	while (!figureStack.empty())
	{
		Figure2D* f = figureStack.top();
		if (f->isInside(p1))
		{
			
			this->drawTop(true,false,false);
			//figureStack.push(f);
			this->drawTop(false, false,true);
			isFound =  true;
		}
		helpStack.push(f);
		figureStack.pop();
	}
	while (!helpStack.empty())
	{
		figureStack.push(helpStack.top());
		helpStack.pop();
	}
	return isFound;
}

void CPaintDlg::drawAllStack()
{	
	while (!figureStack.empty())
	{
		
		Figure2D* f = figureStack.top();
		helpStack.push(f);
		this->drawTop(false, false, false);
		figureStack.pop();
	}

	while (!helpStack.empty())
	{
		figureStack.push(helpStack.top());
		helpStack.pop();
	}
}
//void CPaintDlg::draw(const CPen& p, const CBrush& b,Figure2D* f)
//{
//	
//}

void CPaintDlg::OnBnClickedSavebtn()
{
	ofstream outBin("Paint.bin");
	saveToFile(outBin);
	outBin.close();
}


void CPaintDlg::OnBnClickedLoad()
{
	Invalidate(true);
	UpdateWindow();
	while (!figureStack.empty())
		figureStack.pop();

	ifstream inBin("Paint.bin");
	loadFromFile(inBin);
	inBin.close();
}


void CPaintDlg::OnBnClickedRedobutton()
{

		this->drawTop(false, true, false);
		if (!redoStack.empty())
			redoStack.pop();

}


void CPaintDlg::OnBnClickedEllipsebtn()
{
	_shape = Ellipse;
}


void CPaintDlg::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	if (_shape == -1)
	{
		checkIsInside(point);
		CDialogEx::OnLButtonDblClk(nFlags, point);
	}
}


void CPaintDlg::OnBnClickedChangeshape()
{
	_shape = Shape(-1);
}


void CPaintDlg::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	checkIsInside(point);
	CDialogEx::OnRButtonDown(nFlags, point);
}


void CPaintDlg::OnBnClickedTriangle()
{
	_shape = Triangle;
}


void CPaintDlg::OnBnClickedClear()
{
	Invalidate(true);
	UpdateWindow();
	while (!figureStack.empty())
		figureStack.pop();
}


void CPaintDlg::OnBnClickedMagendavid()
{
	_shape = MagenDavid;
}
