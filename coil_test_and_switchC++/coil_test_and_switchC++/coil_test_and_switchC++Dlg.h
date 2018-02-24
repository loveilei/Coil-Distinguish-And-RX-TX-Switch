
// coil_test_and_switchC++Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// Ccoil_test_and_switchCDlg dialog
class Ccoil_test_and_switchCDlg : public CDialogEx
{
// Construction
public:
	Ccoil_test_and_switchCDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_COIL_TEST_AND_SWITCHC_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
private:
	CString m_EditReceive;
	CComboBox m_comb1;
public:
	afx_msg void OnBnClickedButtonopenclose();
	afx_msg void OnBnClickedButtonclear();
//	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();
	afx_msg void OnBnClickedButton8();
	afx_msg void OnBnClickedButton9();
	afx_msg void OnBnClickedButtonopenclose2();
	char HexChar(char c);
	size_t ReadComm(char *buf, DWORD dwLength);
	bool Close(VOID);
	
	BOOL ComIsOpened(void){ return(m_bOpened); }
protected:
	BOOL m_bOpened;
};
