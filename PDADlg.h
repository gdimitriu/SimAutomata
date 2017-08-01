// PDADlg.h : header file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of PDA.
	This is the definition for dialog class for PDA.

    PDA is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    PDA is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with PDA; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/

#if !defined(AFX_PDADLG_H__5E940EBB_135E_45CA_BCAC_22CCBA511B5B__INCLUDED_)
#define AFX_PDADLG_H__5E940EBB_135E_45CA_BCAC_22CCBA511B5B__INCLUDED_
#include<stack>
#include<list>
#include<string>
using namespace std ;
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CPDADlg dialog

class CPDADlg : public CDialog
{
// Construction
public:
	CPDADlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CPDADlg)
	enum { IDD = IDD_PDA_DIALOG };
	CString	m_Q;
	CString	m_q0;
	CString	m_S;
	CString	m_G;
	CString	m_file;
	CString	m_str;
	CString	m_z0;
	CString	m_state;
	CString	m_elem;
	CString	m_stack;
	CString str;
	CString	m_know;
	CString	m_ostate;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CPDADlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CPDADlg)
	afx_msg BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void On_init();
	afx_msg void On_load();
	virtual void OnOK();
	afx_msg void OnHelp();
	afx_msg void OnBnClickedBrowsepda();
	afx_msg void On_Next();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool flag;
	char tmp[2];
	//My data
	int q0; //initial state
	char z0; //initial element in stack
	char *Q; //state vector
	int nr_state; //nr of state
	list<char> S; //list of symbols for input
	list<char> G; //list of symbols for stack
	stack<char> pdstack; //PDA stack
	stack<char> tmpstack; //temporary stack
	int current_state; //current state
	list<char>::iterator it; //iterator for list of chars
	struct data
	{
		int istate;
		char input;
		char istack;
		int ostate;
		int func;
		char out;
	} datatmp;
	list<struct data> l_data;
	list<struct data>::iterator it_data;
	bool load;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_PDADLG_H__5E940EBB_135E_45CA_BCAC_22CCBA511B5B__INCLUDED_)
