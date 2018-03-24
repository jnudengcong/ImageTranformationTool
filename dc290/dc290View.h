// dc290View.h : interface of the CDc290View class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DC290VIEW_H__64CD06E1_C31F_4F31_B1FA_DA5E9CEEED70__INCLUDED_)
#define AFX_DC290VIEW_H__64CD06E1_C31F_4F31_B1FA_DA5E9CEEED70__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDc290View : public CScrollView
{
protected: // create from serialization only
	CDc290View();
	DECLARE_DYNCREATE(CDc290View)

// Attributes
public:
	CDc290Doc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDc290View)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual void OnInitialUpdate(); // called first time after construct
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDc290View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDc290View)
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnGray();
	afx_msg void OnUpdateGray(CCmdUI* pCmdUI);
	afx_msg void OnHistogram();
	afx_msg void OnUpdateHistogram(CCmdUI* pCmdUI);
	afx_msg void OnLinetrans();
	afx_msg void OnUpdateLinetrans(CCmdUI* pCmdUI);
	afx_msg void OnEqualize();
	afx_msg void OnUpdateEqualize(CCmdUI* pCmdUI);
	afx_msg void OnUpdateFourier(CCmdUI* pCmdUI);
	afx_msg void OnFourier();
	afx_msg void OnIFourier();
	afx_msg void OnUpdateIFourier(CCmdUI* pCmdUI);
	afx_msg void OnFft();
	afx_msg void OnUpdateFft(CCmdUI* pCmdUI);
	afx_msg void OnIfft();
	afx_msg void OnUpdateIfft(CCmdUI* pCmdUI);
	afx_msg void OnAverageFilter();
	afx_msg void OnUpdateAverageFilter(CCmdUI* pCmdUI);
	afx_msg void OnMedianFilter();
	afx_msg void OnUpdateMedianFilter(CCmdUI* pCmdUI);
	afx_msg void OnGradSharp();
	afx_msg void OnUpdateGradSharp(CCmdUI* pCmdUI);
	afx_msg void OnRaplasSharp();
	afx_msg void OnUpdateRaplasSharp(CCmdUI* pCmdUI);
	afx_msg void OnIdealFilter();
	afx_msg void OnUpdateIdealFilter(CCmdUI* pCmdUI);
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in dc290View.cpp
inline CDc290Doc* CDc290View::GetDocument()
   { return (CDc290Doc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DC290VIEW_H__64CD06E1_C31F_4F31_B1FA_DA5E9CEEED70__INCLUDED_)
