// automataDlg.cpp : implementation file
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
#include "stdafx.h"
#include "automates.h"
#include "automataDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAutomataDlg dialog

CAutomataDlg::CAutomataDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CAutomataDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAutomataDlg)
	m_Coada = _T("");
	m_StareA = _T("");
	m_StareC = _T("");
	m_Introducere = 0;
	m_Iesire = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CAutomataDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAutomataDlg)
	DDX_Text(pDX, IDC_Coada, m_Coada);
	DDX_Text(pDX, IDC_StareA, m_StareA);
	DDX_Text(pDX, IDC_StareC, m_StareC);
	DDX_Text(pDX, IDC_Introducere, m_Introducere);
	DDX_Text(pDX, IDC_Iesire, m_Iesire);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAutomataDlg, CDialog)
	//{{AFX_MSG_MAP(CAutomataDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_Avanseaza, OnAvanseaza)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAutomataDlg message handlers

BOOL CAutomataDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
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
	m_cap=NULL;
	Stari[0]="abb";
	Stari[1]="bbb";
	Stari[2]="bab";
	Stari[3]="caa";
	Stari[4]="aab";
	Stari[5]="cba";
	m_Stare=0;
	m_StareA=m_StareC=Stari[0];
	UpdateData(FALSE);
	return TRUE;  // return TRUE  unless you set the focus to a control
}


// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CAutomataDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

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
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CAutomataDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CAutomataDlg::OnAvanseaza() 
{
	// TODO: Add your control notification handler code here
	int n;
	UpdateData(TRUE);
	switch(m_Stare)
	{
	case 0:
		{
			if(m_Introducere==1)
			{
				m_Stare=1;
				m_StareA=Stari[0];
				m_StareC=Stari[1];
			}		
			break;
		}
	case 1:
		{
			if(m_Introducere==1)
			{
				m_Stare=3;
				m_StareA=Stari[1];
				m_StareC=Stari[3];
				introduce();
				n=m_Coada.GetLength();
				n=m_Coada.Delete(0,n);
				coada_s *temp;
				temp=m_cap;
				char temp1;
				while(temp!=NULL)
				{
					temp=printare(&temp1,temp);
					n=m_Coada.Insert(n,temp1);
				}
			}
			else
			{
				m_Stare=5;
				m_StareA=Stari[1];
				m_StareC=Stari[5];
			}
			int n=m_Iesire.GetLength();
			m_Iesire.Insert(n,'1');
			break;
		}
	case 2:
		{
			m_Stare=3;
			m_StareA=Stari[2];
			m_StareC=Stari[3];
			if(m_Introducere==1)
			{
				introduce();
				n=m_Coada.GetLength();
				n=m_Coada.Delete(0,n);
				coada_s *temp;
				temp=m_cap;
				char temp1;
				while(temp!=NULL)
				{
					temp=printare(&temp1,temp);
					n=m_Coada.Insert(n,temp1);
				}
			}
			int n=m_Iesire.GetLength();
			m_Iesire.Insert(n,'1');
			break;
		}
	case 3:
		{
			m_Stare=4;
			m_StareA=Stari[3];
			m_StareC=Stari[4];
			if(m_Introducere==1)
			{
				introduce();
				n=m_Coada.GetLength();
				n=m_Coada.Delete(0,n);
				coada_s *temp;
				temp=m_cap;
				char temp1;
				while(temp!=NULL)
				{
					temp=printare(&temp1,temp);
					n=m_Coada.Insert(n,temp1);
				}
			}
			break;
		}
	case 4:
		{
			coada_s *temp;
			char temp1,temp2;
			temp=m_cap;
			temp=printare(&temp1,temp);
			temp=printare(&temp2,temp);
			if(m_Introducere==1 || (m_Introducere==0 && temp1=='1' && temp2=='1'))
			{
				m_Stare=2;
				m_StareA=Stari[4];
				m_StareC=Stari[2];
				if(m_Introducere==0)
				{
					scoate();
					n=m_Coada.GetLength();
					n=m_Coada.Delete(0,n);
					temp=m_cap;
					while(temp!=NULL)
					{
						temp=printare(&temp1,temp);
						n=m_Coada.Insert(n,temp1);
					}
				}
			}
			else
			{
				m_Stare=1;
				m_StareA=Stari[4];
				m_StareC=Stari[1];
				scoate();
				n=m_Coada.GetLength();
				m_Coada.Delete(0,n);
				coada_s *temp;
				temp=m_cap;
				char temp1;
				n=0;
				while(temp!=NULL)
				{
					temp=printare(&temp1,temp);
					n=m_Coada.Insert(n,temp1);
				}
			}
			break;
		}
	case 5:
		{
			if(m_Introducere==1)
			{
				m_Stare=4;
				m_StareA=Stari[5];
				m_StareC=Stari[4];
				introduce();
				n=m_Coada.GetLength();
				n=m_Coada.Delete(0,n);
				coada_s *temp;
				temp=m_cap;
				char temp1;
				while(temp!=NULL)
				{
					temp=printare(&temp1,temp);
					n=m_Coada.Insert(n,temp1);
				}
			}
			else
			{
				m_Stare=0;
				m_StareA=Stari[5];
				m_StareC=Stari[0];
			}
			break;
		}
	}
	UpdateData(FALSE);
}

void CAutomataDlg::scoate()
{
	if(m_cap!=NULL)
	{
		coada_s *temp;
		temp=m_cap;
		m_cap=temp->next;
		free(temp);
	}
}

void CAutomataDlg::introduce()
{
	coada_s *temp,*temp1;
	temp=(coada_s *)calloc(1,sizeof(coada_s));
	temp->next=NULL;
	if(m_cap==NULL) m_cap=temp;
	else
	{
		temp1=m_cap;
		while(1)
		{
			if(temp1->next!=NULL) temp1=temp1->next;
			else
			{
				temp1->next=temp;
				return;
			}
		}
	}
}

coada_s *CAutomataDlg::printare(char *data,coada_s *temp)
{
	if(temp!=NULL)
	{
		*data='1';
		return temp->next;
	}
	else
	{
		*data='0';
		return NULL;
	}
}
