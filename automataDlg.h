// automataDlg.h : header file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of Modelare Client-Server.
	
    Modelare Client-Server is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    Modelare Client-Server is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with Modelare Client-Server; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  
*/
#if !defined(AFX_AUTOMATADLG_H__20747E89_6534_4D97_8652_D20CE0CF604C__INCLUDED_)
#define AFX_AUTOMATADLG_H__20747E89_6534_4D97_8652_D20CE0CF604C__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutomataDlg dialog
#include<stdlib.h>
#include"coada_s.h"
class CAutomataDlg : public CDialog
{
// Construction
public:
	int m_Stare;
	coada_s *m_cap;
	coada_s *printare(char *data,coada_s *temp);
	void introduce(void);
	void scoate(void);
	CAutomataDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutomataDlg)
	enum { IDD = IDD_AUTOMATA_DIALOG };
	CString	m_Coada;
	CString	m_StareA;
	CString	m_StareC;
	int		m_Introducere;
	CString	m_Iesire;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutomataDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;
	CString Stari[6];
	// Generated message map functions
	//{{AFX_MSG(CAutomataDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnAvanseaza();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOMATADLG_H__20747E89_6534_4D97_8652_D20CE0CF604C__INCLUDED_)
