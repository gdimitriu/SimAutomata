// automatesDlg.h : header file
//

#if !defined(AFX_AUTOMATESDLG_H__860BD627_4357_11DB_B910_85365F6ADA7F__INCLUDED_)
#define AFX_AUTOMATESDLG_H__860BD627_4357_11DB_B910_85365F6ADA7F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CAutomatesDlg dialog

class CAutomatesDlg : public CDialog
{
// Construction
public:
	CAutomatesDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CAutomatesDlg)
	enum { IDD = IDD_AUTOMATES_DIALOG };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAutomatesDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CAutomatesDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnDfa();
	afx_msg void OnPda();
	afx_msg void Onclientserver();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_AUTOMATESDLG_H__860BD627_4357_11DB_B910_85365F6ADA7F__INCLUDED_)
