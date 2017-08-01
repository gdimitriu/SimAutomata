// PDADlg.cpp : implementation file
//
/*
	Copyright 2003 Gabriel Dimitriu

	This file is part of PDA.
	This is the implementation for dialog class for PDA.

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


#include "stdafx.h"
#include "Automates.h"
#include "PDADlg.h"
#include<fstream>
#include<stdlib.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif


/////////////////////////////////////////////////////////////////////////////
// CPDADlg dialog

CPDADlg::CPDADlg(CWnd* pParent /*=NULL*/)
	: CDialog(CPDADlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CPDADlg)
	m_Q = _T("");
	m_q0 = _T("");
	m_S = _T("");
	m_G = _T("");
	m_file = _T("");
	m_str = _T("");
	m_z0 = _T("");
	m_state = _T("");
	m_elem = _T("");
	m_stack = _T("");
	m_know = _T("");
	m_ostate = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPDADlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CPDADlg)
	DDX_Text(pDX, IDC_PDA_Q, m_Q);
	DDX_Text(pDX, IDC_PDA_q0, m_q0);
	DDX_Text(pDX, IDC_PDA_S, m_S);
	DDX_Text(pDX, IDC_PDA_G, m_G);
	DDX_Text(pDX, IDC_PDA_file, m_file);
	DDX_Text(pDX, IDC_PDA_str, m_str);
	DDX_Text(pDX, IDC_PDA_z0, m_z0);
	DDX_Text(pDX, IDC_PDA_state, m_state);
	DDX_Text(pDX, IDC_PDA_elem, m_elem);
	DDX_Text(pDX, IDC_PDA_stack, m_stack);
	DDX_Text(pDX, IDC_PDA_know, m_know);
	DDX_Text(pDX, IDC_PDA_ostate, m_ostate);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CPDADlg, CDialog)
	//{{AFX_MSG_MAP(CPDADlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_PDA_init, On_init)
	ON_BN_CLICKED(IDC_PDA_load, On_load)
	ON_BN_CLICKED(IDC_PDAHELP, OnHelp)
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BROWSEPDA, &CPDADlg::OnBnClickedBrowsepda)
	ON_BN_CLICKED(IDC_PDA_next, &CPDADlg::On_Next)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CPDADlg message handlers

BOOL CPDADlg::OnInitDialog()
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
	Q=NULL;
	load=false;
	return TRUE;  // return TRUE  unless you set the focus to a control
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPDADlg::OnPaint() 
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
HCURSOR CPDADlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CPDADlg::On_init() 
{
	UpdateData(TRUE);
	if(m_state.IsEmpty()==0) m_state.Empty();
	if(m_know.IsEmpty()==0) m_know.Empty();
	while(!pdstack.empty()) pdstack.pop();
	int i;
	q0=0;
	for(i=0;i<nr_state;i++) if(Q[i]==m_q0[0]) q0=i;
	z0=m_z0[0];
	it=G.begin();
	tmp[0]=*it;
	if(z0!=tmp[0])
	{
		for(++it;it!=G.end();++it)
		{
			tmp[0]=*it;
			if(z0==tmp[0])
			{
				pdstack.push(z0);
				tmp[0]=pdstack.top();
				m_stack.Insert(0,tmp);
			}
		}
	}
	else z0='\0';
	tmp[0]=Q[q0];
	m_state.Empty();
	m_state.Insert(0,tmp);
	tmp[0]='\0';
	m_elem.Empty();
	m_elem.Insert(0,tmp);
	current_state=q0;
	UpdateData(FALSE);
}

void CPDADlg::On_load() 
{
	char temp[50];
	char count=1;
	int i,j;
	UpdateData(TRUE);
	m_Q.Empty();
	m_S.Empty();
	m_G.Empty();
	m_z0.Empty();
	m_q0.Empty();
	m_str.Empty();
	m_state.Empty();
	m_elem.Empty();
	m_stack.Empty();
	str.Empty();
	m_know.Empty();
	m_ostate.Empty();
	while(!pdstack.empty()) pdstack.pop();
	if(Q!=NULL)
	{
		free(Q);
		Q=NULL;
	}
	S.clear();
	G.clear();
	l_data.clear();
	CString message;
	//make initialization of strings
	tmp[1]='\0';
	//load data from file
	ifstream file(m_file);
	for(i=0;i<5;i++)
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
		case 'G':
			m_G.Insert(0,&temp[2]);
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
		case 'z':
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
				if(m_G.Find(temp[3])!=-1) m_z0.Insert(0,&temp[3]);
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
	Q=(char *)calloc(nr_state,sizeof(char));
	load=true;
	for(j=0;j<nr_state;j++) Q[j]=0;
	j=0;
	for(i=0;i<m_Q.GetLength();i++) if(m_Q[i]!=',' && m_Q[i]!='\n' && m_Q[i]!='\0') {Q[j]=m_Q[i]; j++;}
	Q[j]='\0';
	for(i=0;i<m_S.GetLength();i++) if(m_S[i]!=',' && m_S[i]!='\n' && m_S[i]!='\0')	S.insert(S.end(),m_S[i]);
	for(i=0;i<m_G.GetLength();i++) if(m_G[i]!=',' && m_G[i]!='\n' && m_G[i]!='\0')	G.insert(G.end(),m_G[i]);
	//read the function definition
	while(!file.eof())
	{
		for(j=0;j<50;j++) temp[j]='\0';
		file.getline(temp,50,'\n');
		if(temp[0]=='\0') break;
		//I have function definition
		if(temp[5]=='=' && temp[1]==',' && temp[3]==',' && temp[7]==',')
		{
			//parsing define domain
			//parsing state
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
			//parsing stack
			flag=false;
			for(it=G.begin();it!=G.end();++it)
			{
				tmp[0]=*it;
				if(temp[4]==tmp[0])
				{
					datatmp.istack=temp[4];
					flag=true;
					break;
				}
			}
			if(flag==false)
			{
				message.Empty();
				message.Format("Error in file unknown stack value %c at line %d",temp[4],count);
				MessageBox(message);
				file.close();
				return;
			}
			//parsing value domain
			//parsing new state
			for(i=0;i<nr_state;i++)
				if(temp[6]==Q[i])
				{
					datatmp.ostate=i;
					break;
				}
			if(i==nr_state)
			{
				message.Empty();
				message.Format("Error in file unknown state temp[6] at line %d",count);
				MessageBox(message);
				file.close();
				return;
			}
			//parsing stack operation
			char tmpch[6];
			j=0;
			for(i=8;i<13;i++) { tmpch[j]=temp[i]; j++;}
			tmpch[j]='\0';
			CString strtmp;
			strtmp.Insert(0,tmpch);
			if(strtmp.CompareNoCase("push(")==0)
			{
				datatmp.func=0;
				flag=false;
				for(it=G.begin();it!=G.end();++it)
				{
					tmp[0]=*it;
					if(temp[13]==tmp[0])
					{
						datatmp.out=temp[13];
						flag=true;
						break;
					}
				}
				if(flag==false)
				{
					message.Empty();
					message.Format("Error in file unknown stack value %c at line %d",temp[13],count);
					MessageBox(message);
					file.close();
					return;
				}
			}
			else if(strtmp.CompareNoCase("pop()")==0)
			{
				datatmp.func=1;
			}
			else
			{
				message.Empty();
				message.Format("Error in file unknown stack operation %s at line %d",strtmp,count);
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

void CPDADlg::On_Next() 
{
	UpdateData(TRUE);
	if(m_S.Find(m_str[0])==-1) MessageBox("This input data is wrong");
	else
	{
		int j;
		flag=false;
		for(it_data=l_data.begin();it_data!=l_data.end();++it_data)
		{
			datatmp=*it_data;
			if(current_state==datatmp.istate) //it is the the state
			{ 
				it=G.begin();
				if(pdstack.empty()==true) tmp[0]=*it;
				else tmp[0]=pdstack.top(); //get top element of stack
				if(tmp[0]==datatmp.istack) //it is the element in stack
				{
					if(m_str.IsEmpty()!=0)
					{
						MessageBox("Input string is empty,put some data in string and if you want a new run pres init after that");
						flag=true;
						break;
					}
					if(m_str[0]=='\0') { flag=true; break;}
					if(m_str[0]==datatmp.input) //it is the input element
					{
						tmp[0]=m_str[0];
						m_elem.Empty();
						m_elem.Insert(0,tmp);
						m_str.Delete(0,1); //erase the element from input string
						if(datatmp.func==0) pdstack.push(datatmp.out); //it is a push op
						else
						{
							if(pdstack.empty()==false) pdstack.pop(); //it is a pop op
							else
							{
								MessageBox("Stack is empty, this input sting is not generated by this automata");
								break;
							}
						}
						m_know.Insert(m_know.GetLength(),tmp);
						current_state=datatmp.ostate; //set the new state
						//print the new state
						tmp[0]=Q[current_state];
						m_ostate.Empty();
						m_ostate.Insert(0,m_state);
						m_state.Empty();
						m_state.Insert(0,tmp);
						//print the new stack
						while(pdstack.empty()==false)
						{
							tmpstack.push(pdstack.top());
							pdstack.pop();
						}
						m_stack.Empty();
						j=0;
						while(tmpstack.empty()==false)
						{
							tmp[0]=tmpstack.top();
							pdstack.push(tmp[0]);
							tmpstack.pop();
							m_stack.Insert(j,tmp);
							j++;
						}
						flag=true;
						break;
					}
				}
			}
		}
		if(flag==false) 
			MessageBox("this input sting is not generated by this automata");
		UpdateData(FALSE);
	}
}

void CPDADlg::OnOK() 
{
	if(Q!=NULL) free(Q);
	CDialog::OnOK();
}

void CPDADlg::OnHelp() 
{
	MessageBox("Automata is M=(Q,S,G,F,q0,z0) and one file example is\nQ=q,p\nS=a,b\nG=z,A\nq0=q\nz0=z\nq,a,z=q,push(A)\nq,b,A=p,pop()\nAfter loading the data from file you must push the init config for loading the init data and when you want a fresh new simulator.\nObs: the first element of stack language must be the null element for the stack.");
}

void CPDADlg::OnBnClickedBrowsepda()
{
	CFileDialog file(TRUE);
	file.DoModal();
	CString tmp=file.GetPathName();
	m_file.Empty();
	m_file.Insert(0,tmp);
	UpdateData(FALSE);
}

