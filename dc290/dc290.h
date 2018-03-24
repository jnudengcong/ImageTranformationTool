// dc290.h : main header file for the DC290 application
//

#if !defined(AFX_DC290_H__208B6513_4C13_40A6_9B0A_0990D9E93AC5__INCLUDED_)
#define AFX_DC290_H__208B6513_4C13_40A6_9B0A_0990D9E93AC5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CDc290App:
// See dc290.cpp for the implementation of this class
//

class CDc290App : public CWinApp
{
public:
	CDc290App();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDc290App)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CDc290App)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DC290_H__208B6513_4C13_40A6_9B0A_0990D9E93AC5__INCLUDED_)
