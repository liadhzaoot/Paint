
// PaintDlg.h : header file
//
#pragma once
#include <stack>
#include "Figure2D.h"

using namespace std;

// CPaintDlg dialog
class CPaintDlg : public CDialogEx
{
// Construction
public:
	CPaintDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PAINT_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:

	afx_msg void OnBnClickedLine();
	
	afx_msg void OnBnClickedRectangle();
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedFreedraw();
	afx_msg void OnBnClickedCirclebutton();

	void drawRectangle();
	void drawLine();
	void drawCircle();
	void drawSquare();
	void drawEllipse();
	void drawTriangle();
	void drawMyMagenDavid();
	void drawAllStack();
	bool checkIsInside(CPoint&);
	void drawTop(bool undo,bool redoStack,bool choose);
	void saveToFile(ostream& out);
	void loadFromFile(istream& in);
	//void draw(const CPen& p, const CBrush& b, Figure2D* f);

	enum Shape { Figure,Line, Rectangle,FreeDraw,Circle,Square,Ellipse,Triangle,MagenDavid };
	Shape _shape;
	CPoint _mouseDownPoint;
	CPoint _mouseUpPoint;
	CBrush _brush;
	int _penStyle;
	bool _isLButtonClicked = false;
	int PenSizeBox;
	CMFCColorButton colorButton;
	CMFCColorButton brushColor;
	CMFCColorButton brushColorButton;
	CMFCColorButton PenColorButton;

	//stack<Figure2D*> stackFigure2D;
	//stack<int> s;
	afx_msg void OnBnClickedSquare();
	afx_msg void OnBnClickedUndobottun();
	afx_msg void OnBnClickedSavebtn();
	afx_msg void OnBnClickedLoad();
	afx_msg void OnBnClickedRedobutton();
	afx_msg void OnBnClickedEllipsebtn();
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedChangeshape();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnBnClickedTriangle();
	afx_msg void OnBnClickedClear();
	afx_msg void OnBnClickedMagendavid();
};
