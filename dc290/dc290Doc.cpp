// dc290Doc.cpp : implementation of the CDc290Doc class
//

#include "stdafx.h"
#include "dc290.h"

#include "dc290Doc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDc290Doc

IMPLEMENT_DYNCREATE(CDc290Doc, CDocument)

BEGIN_MESSAGE_MAP(CDc290Doc, CDocument)
	//{{AFX_MSG_MAP(CDc290Doc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDc290Doc construction/destruction

CDc290Doc::CDc290Doc()
{
	// TODO: add one-time construction code here

}

CDc290Doc::~CDc290Doc()
{
}

BOOL CDc290Doc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CDc290Doc serialization

void CDc290Doc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CDc290Doc diagnostics

#ifdef _DEBUG
void CDc290Doc::AssertValid() const
{
	CDocument::AssertValid();
}

void CDc290Doc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CDc290Doc commands
BOOL LoadBmpFile(char* BmpFileName);


BOOL CDc290Doc::OnOpenDocument(LPCTSTR lpszPathName) 
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;
	
	// TODO: Add your specialized creation code here
	LoadBmpFile((char*)lpszPathName);
	return TRUE;
}
