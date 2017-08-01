// DFADlg.cpp : implementation file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of DFA.
	This is the implementation of dialog class for DFA.

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


#include "stdafx.h"
#include "Automates.h"
#include "DFADlg.h"
#include <fstream>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDFADlg dialog

CDFADlg::CDFADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDFADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDFADlg)
	m_F = _T("");
	m_file = _T("");
	m_cstate = _T("");
	m_ostate = _T("");
	m_astr = _T("");
	m_Q = _T("");
	m_S = _T("");
	m_str = _T("");
	m_elem = _T("");
	m_q0 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CDFADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDFADlg)
	DDX_Text(pDX, IDC_F, m_F);
	DDX_Text(pDX, IDC_file, m_file);
	DDX_Text(pDX, IDC_cstate, m_cstate);
	DDX_Text(pDX, IDC_ostate, m_ostate);
	DDX_Text(pDX, IDC_astr, m_astr);
	DDX_Text(pDX, IDC_Q, m_Q);
	DDX_Text(pDX, IDC_S, m_S);
	DDX_Text(pDX, IDC_str, m_str);
	DDX_Text(pDX, IDC_elem, m_elem);
	DDX_Text(pDX, IDC_q0, m_q0);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CDFADlg, CDialog)
	//{{AFX_MSG_MAP(CDFADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_init, Oninit)
	ON_BN_CLICKED(IDC_load, Onload)
	ON_BN_CLICKED(IDC_next, Onnext)
	ON_BN_CLICKED(IDC_Help, OnHelp)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BROWSEDFA, &CDFADlg::OnBnClickedBrowsedfa)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDFADlg message handlers

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CDFADlg::OnPaint() 
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
HCURSOR CDFADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CDFADlg::Onload() 
{
	char temp[50];
	char count=1;
	int i,j;
	CString message;
	UpdateData(TRUE);
	m_F.Empty();
	m_cstate.Empty();
	m_ostate.Empty();
	m_astr.Empty();
	m_Q.Empty();
	m_S.Empty();
	m_str.Empty();
	m_elem.Empty();
	m_q0.Empty();
	//make initialization of strings
	tmp[1]='\0';
	//load data from file
	ifstream file(m_file);
	for(i=0;i<4;i++)
	{
		for(j=0;j<50;j++) temp[j]='\0';
		file.getline(temp,50,'\n');
		switch(temp[0])
		{
		case 'Q':
			m_Q.Insert(0,&temp[2]);
			break;
		case 'S':
			m_S.Insert(0,&temp[2]);
			break;
		case 'F':
			tmp[0]=temp[2];
			i=2;
			j=0;
			m_F.Empty();
			while(tmp[0]!='\0')
			{
				if(tmp[0]!=',')
				{
					if (m_Q.Find(tmp[0])!=-1)
					{
						m_F.Insert(j,tmp[0]);
						m_F.Insert(j+1,',');
						j=j+2;
					}
					else
					{
						message.Empty();
						message.Format("Error in file unknown state %c at line %d",temp[3],count);
						MessageBox(message);
						file.close();
						return;
					}
				}
				i++;
				tmp[0]=temp[i];
			}
			m_F.Delete(j-1,1);
			break;
		case 'q':
			if(temp[1]!='0')
			{
				message.Empty();
				message.Format("Error in file unknown description at line %d",count);
				MessageBox(message);
				file.close();
				return;
			}
			else
			{
				if (m_Q.Find(temp[3])!=-1)	m_q0.Insert(0,&temp[3]);
				else
				{
					message.Empty();
					message.Format("Error in file unknown state %c at line %d",temp[3],count);
					MessageBox(message);
					file.close();
					return;
				}
			}
			break;
		default:
			message.Empty();
			message.Format("Error in file unknown description at line %d",count);
			file.close();
			return;
		}
		count++;
	}
	//make the internal data
	nr_state=0;
	for(i=0;i<m_Q.GetLength();i++) if(m_Q[i]!=',')	nr_state++;
	Q=new char[nr_state];
	for(j=0;j<nr_state;j++) Q[j]=0;
	j=0;
	for(i=0;i<m_Q.GetLength();i++) if(m_Q[i]!=',' && m_Q[i]!='\n' && m_Q[i]!='\0') {Q[j]=m_Q[i]; j++;}
	Q[j]='\0';
	for(i=0;i<m_S.GetLength();i++) if(m_S[i]!=',' && m_S[i]!='\n' && m_S[i]!='\0')	S.insert(S.end(),m_S[i]);
	while(!file.eof())
	{
		for(j=0;j<50;j++) temp[j]='\0';
		file.getline(temp,50,'\n');
		if(temp[0]=='\0') break;
		if(temp[1]==',' && temp[3]=='=')
		{
			//parsing define domain
			//parsing input state
			for(i=0;i<nr_state;i++)
				if(temp[0]==Q[i])
				{
					datatmp.istate=i;
					break;
				}
			if(i==nr_state)
			{
				message.Empty();
				message.Format("This state is not define %c at line %d",temp[0],count);
				MessageBox(message);
				file.close();
				return;
			}
			//parsing input
			flag=false;
			for(it=S.begin();it!=S.end();++it)
			{
				tmp[0]=*it;
				if(temp[2]==tmp[0])
				{
					datatmp.input=temp[2];
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				message.Empty();
				message.Format("Error in file input %c value at line %d",temp[2],count);
				MessageBox(message);
				file.close();
				return;
			}
			//parsing output state
			for(i=0;i<nr_state;i++)
				if(temp[4]==Q[i])
				{
					datatmp.ostate=i;
					break;
				}
			if(i==nr_state)
			{
				message.Empty();
				message.Format("This state is not define %c at line %d",temp[0],count);
				MessageBox(message);
				file.close();
				return;
			}
			l_data.insert(l_data.end(),datatmp);
		}
		else
		{
			message.Empty();
			message.Format("Error in file unknown description it must be function definition at line %d",count);
			MessageBox(message);
			file.close();
			return;
		}
		count++;
	}
	file.close();
	UpdateData(FALSE);
}

void CDFADlg::Oninit() 
{
	UpdateData(TRUE);
	m_astr.Empty();
	m_cstate.Empty();
	int i;
	q0=0;
	if (Q == NULL) {
		UpdateData(FALSE);
		return;
	}
	for(i=0;i<nr_state;i++) { if(Q[i]==m_q0[0]) q0=i; break;}
	tmp[0]=Q[q0];
	m_cstate.Insert(0,tmp);
	m_ostate.Empty();
	m_elem.Empty();
	current_state=q0;
	UpdateData(FALSE);
}

void CDFADlg::Onnext() 
{
	UpdateData(TRUE);
	if(m_str.IsEmpty()!=0) MessageBox("You don't have input data");
	else if(m_str[0]=='\0') MessageBox("You don't have nput data");
	else if(m_S.Find(m_str[0])==-1) MessageBox("This input is wrong");
	else
	{
		flag=false;
		for(it_data=l_data.begin();it_data!=l_data.end();++it_data)
		{
			datatmp=*it_data;
			if(current_state==datatmp.istate) //it is the the state
			{ 
				if(m_str[0]==datatmp.input) //it is the input element
				{
					m_ostate.Empty();
					m_ostate.Insert(0,m_cstate);
					current_state=datatmp.ostate;
					tmp[0]=Q[datatmp.ostate];
					m_cstate.Empty();
					m_cstate.Insert(0,tmp);
					m_elem.Empty();
					tmp[0]=m_str[0];
					m_elem.Insert(0,tmp);
					m_astr.Insert(m_astr.GetLength(),tmp);
					m_str.Delete(0,1);
					//verify if it is one of the final state
					if(m_F.Find(Q[current_state])!=-1 && m_str.IsEmpty()!=0)
						MessageBox("One of the final state is reach");
					flag=true;
					UpdateData(FALSE);
					break;
				}
			}
		}
		if(flag==false) MessageBox("Something is wrong");
	}
}

void CDFADlg::OnHelp() 
{
	MessageBox("Automata is M=(Q,S,q0,f,F)\nWhere\nQ=state vector\nS=input alphabet\nq0=initial state\nf=is the function who is describe by state,input=output state\nF=final states\n");
}

void CDFADlg::OnBnClickedBrowsedfa()
{
  CFileDialog file(TRUE);
  file.DoModal();
  CString tmp=file.GetPathName();
  m_file.Empty();
  m_file.Insert(0,tmp);
  UpdateData(FALSE);
}
