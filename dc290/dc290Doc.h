// dc290Doc.h : interface of the CDc290Doc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_DC290DOC_H__0506ED17_C694_49C0_B7E4_60261A7E1965__INCLUDED_)
#define AFX_DC290DOC_H__0506ED17_C694_49C0_B7E4_60261A7E1965__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CDc290Doc : public CDocument
{
protected: // create from serialization only
	CDc290Doc();
	DECLARE_DYNCREATE(CDc290Doc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDc290Doc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	virtual BOOL OnOpenDocument(LPCTSTR lpszPathName);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CDc290Doc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CDc290Doc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DC290DOC_H__0506ED17_C694_49C0_B7E4_60261A7E1965__INCLUDED_)
