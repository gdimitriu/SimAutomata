// automates.h : main header file for the AUTOMATES application
//

#if !defined(AFX_AUTOMATES_H__860BD625_4357_11DB_B910_85365F6ADA7F__INCLUDED_)
#define AFX_AUTOMATES_H__860BD625_4357_11DB_B910_85365F6ADA7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CAutomatesApp:
// See automates.cpp for the implementation of this class
//

class CAutomatesApp : public CWinApp
{
public:
	CAutomatesApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutomatesApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CAutomatesApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOMATES_H__860BD625_4357_11DB_B910_85365F6ADA7F__INCLUDED_)
