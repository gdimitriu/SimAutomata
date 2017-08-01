; CLW file contains information for the MFC ClassWizard

[General Info]
Version=1
LastClass=CAutomatesDlg
LastTemplate=CDialog
NewFileInclude1=#include "stdafx.h"
NewFileInclude2=#include "automates.h"

ClassCount=6
Class1=CAutomatesApp
Class2=CAutomatesDlg
Class3=CAboutDlg
Class4=CDFADlg
Class5=CPDADlg
Class6=CAutomataDlg

ResourceCount=6
Resource1=IDD_PDA_DIALOG
Resource2=IDR_MAINFRAME
Resource3=IDD_ABOUTBOX
Resource4=IDD_DFA_DIALOG
Resource5=IDD_AUTOMATES_DIALOG
Resource6=IDD_AUTOMATA_DIALOG

[CLS:CAutomatesApp]
Type=0
HeaderFile=automates.h
ImplementationFile=automates.cpp
Filter=N

[CLS:CAutomatesDlg]
Type=0
HeaderFile=automatesDlg.h
ImplementationFile=automatesDlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_clientserver

[CLS:CAboutDlg]
Type=0
HeaderFile=automatesDlg.h
ImplementationFile=automatesDlg.cpp
Filter=D

[CLS:CDFADlg]
Type=0
HeaderFile=DFADlg.h
ImplementationFile=DFADlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_astr

[CLS:CPDADlg]
Type=0
HeaderFile=PDADlg.h
ImplementationFile=PDADlg.cpp
Filter=D
BaseClass=CDialog
VirtualFilter=dWC
LastObject=IDC_q0

[CLS:CAutomataDlg]
Type=0
HeaderFile=automataDlg.h
ImplementationFile=automataDlg.cpp
Filter=D
LastObject=CAutomataDlg
BaseClass=CDialog
VirtualFilter=dWC

[DLG:IDD_ABOUTBOX]
Type=1
Class=CAboutDlg
ControlCount=4
Control1=IDC_STATIC,static,1342177283
Control2=IDC_STATIC,static,1342308480
Control3=IDC_STATIC,static,1342308352
Control4=IDOK,button,1342373889

[DLG:IDD_AUTOMATES_DIALOG]
Type=1
Class=CAutomatesDlg
ControlCount=5
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_DFA,button,1342242816
Control4=IDC_PDA,button,1342242816
Control5=IDC_clientserver,button,1342242816

[DLG:IDD_DFA_DIALOG]
Type=1
Class=CDFADlg
ControlCount=26
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1342308352
Control3=IDC_Q,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_S,edit,1350633600
Control6=IDC_STATIC,static,1350696961
Control7=IDC_STATIC,static,1342308352
Control8=IDC_F,edit,1350633600
Control9=IDC_file,edit,1350631552
Control10=IDC_STATIC,static,1342308352
Control11=IDC_STATIC,static,1342308352
Control12=IDC_str,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_astr,edit,1350633600
Control15=IDC_load,button,1342242816
Control16=IDC_init,button,1342242816
Control17=IDC_next,button,1342242816
Control18=IDC_STATIC,static,1342308352
Control19=IDC_cstate,edit,1350633600
Control20=IDC_q0,edit,1350631552
Control21=IDC_STATIC,static,1342308352
Control22=IDC_STATIC,static,1342308352
Control23=IDC_ostate,edit,1350633600
Control24=IDC_STATIC,static,1342308352
Control25=IDC_elem,edit,1350633600
Control26=IDC_Help,button,1342242816

[DLG:IDD_PDA_DIALOG]
Type=1
Class=CPDADlg
ControlCount=30
Control1=IDOK,button,1342242817
Control2=IDC_STATIC,static,1350697473
Control3=IDC_STATIC,static,1342308352
Control4=IDC_PDA_Q,edit,1350633600
Control5=IDC_STATIC,static,1342308352
Control6=IDC_PDA_S,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_PDA_G,edit,1350633600
Control9=IDC_STATIC,static,1342308352
Control10=IDC_PDA_q0,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_PDA_z0,edit,1350631552
Control13=IDC_STATIC,static,1342308352
Control14=IDC_PDA_stack,edit,1350633600
Control15=IDC_STATIC,static,1342308352
Control16=IDC_PDA_str,edit,1350631552
Control17=IDC_next,button,1342242816
Control18=IDC_STATIC,static,1342308352
Control19=IDC_PDA_file,edit,1350631552
Control20=IDC_PDA_load,button,1342242816
Control21=IDC_PDA_init,button,1342242816
Control22=IDC_STATIC,static,1342308352
Control23=IDC_PDA_state,edit,1350633600
Control24=IDC_STATIC,static,1342308352
Control25=IDC_PDA_elem,edit,1350633600
Control26=IDC_PDAHELP,button,1342242816
Control27=IDC_PDA_know,edit,1350633600
Control28=IDC_STATIC,static,1342308352
Control29=IDC_STATIC,static,1342308352
Control30=IDC_PDA_ostate,edit,1350633600

[DLG:IDD_AUTOMATA_DIALOG]
Type=1
Class=CAutomataDlg
ControlCount=13
Control1=IDOK,button,1342242817
Control2=IDCANCEL,button,1342242816
Control3=IDC_Coada,edit,1350633600
Control4=IDC_STATIC,static,1342308352
Control5=IDC_StareC,edit,1350633600
Control6=IDC_StareA,edit,1350633600
Control7=IDC_STATIC,static,1342308352
Control8=IDC_STATIC,static,1342308352
Control9=IDC_Avanseaza,button,1342242816
Control10=IDC_Introducere,edit,1350631552
Control11=IDC_STATIC,static,1342308352
Control12=IDC_Iesire,edit,1350633600
Control13=IDC_STATIC,static,1342308352

