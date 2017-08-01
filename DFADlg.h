// DFADlg.h : header file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of DFA.
	This is the definion of dialog class for DFA.

    DFA is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    DFA is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with DFA; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/


#if !defined(AFX_DFADLG_H__85C6EACB_402B_4496_A93B_651AF2CB24B3__INCLUDED_)
#define AFX_DFADLG_H__85C6EACB_402B_4496_A93B_651AF2CB24B3__INCLUDED_
#include<stack>
#include<list>
#include<string>
//#include "resource.h"
using namespace std ;

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CDFADlg dialog

class CDFADlg : public CDialog
{
// Construction
public:
	CDFADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CDFADlg)
	enum { IDD = IDD_DFA_DIALOG };
	CString	m_F;
	CString	m_file;
	CString	m_cstate;
	CString	m_ostate;
	CString	m_astr;
	CString	m_Q;
	CString	m_S;
	CString	m_str;
	CString	m_elem;
	CString	m_q0;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDFADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CDFADlg)
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void Oninit();
	afx_msg void Onload();
	afx_msg void Onnext();
	afx_msg void OnHelp();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool flag;
	char tmp[2];
	//My data
	int q0; //initial state
	char *Q = NULL; //state vector
	int nr_state; //nr of state
	list<char> S; //list of symbols for input
	int current_state; //current state
	list<char>::iterator it; //iterator for list of chars
	struct data
	{
		int istate;
		char input;
		int ostate;
	} datatmp;
	list<struct data> l_data;
	list<struct data>::iterator it_data;
	afx_msg void OnBnClickedBrowsedfa();
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DFADLG_H__85C6EACB_402B_4496_A93B_651AF2CB24B3__INCLUDED_)
