
// coil_test_and_switchC++Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "coil_test_and_switchC++.h"
#include "coil_test_and_switchC++Dlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

CString m_strTXData;
CString m_strRXData;
HANDLE hCommWatchThread;
HANDLE hComm;

// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();
	

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// Ccoil_test_and_switchCDlg dialog



Ccoil_test_and_switchCDlg::Ccoil_test_and_switchCDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(Ccoil_test_and_switchCDlg::IDD, pParent)
	, m_EditReceive(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void Ccoil_test_and_switchCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDITRec, m_EditReceive);
	DDX_Control(pDX, IDC_COMBO1, m_comb1);
}

BEGIN_MESSAGE_MAP(Ccoil_test_and_switchCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTONOpenClose, &Ccoil_test_and_switchCDlg::OnBnClickedButtonopenclose)
	ON_BN_CLICKED(IDC_BUTTONClear, &Ccoil_test_and_switchCDlg::OnBnClickedButtonclear)
//	ON_WM_TIMER()
ON_BN_CLICKED(IDC_BUTTON2, &Ccoil_test_and_switchCDlg::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON4, &Ccoil_test_and_switchCDlg::OnBnClickedButton4)
ON_BN_CLICKED(IDC_BUTTON5, &Ccoil_test_and_switchCDlg::OnBnClickedButton5)
ON_BN_CLICKED(IDC_BUTTON6, &Ccoil_test_and_switchCDlg::OnBnClickedButton6)
ON_BN_CLICKED(IDC_BUTTON7, &Ccoil_test_and_switchCDlg::OnBnClickedButton7)
ON_BN_CLICKED(IDC_BUTTON8, &Ccoil_test_and_switchCDlg::OnBnClickedButton8)
ON_BN_CLICKED(IDC_BUTTON9, &Ccoil_test_and_switchCDlg::OnBnClickedButton9)
ON_BN_CLICKED(IDC_BUTTONOpenClose2, &Ccoil_test_and_switchCDlg::OnBnClickedButtonopenclose2)
END_MESSAGE_MAP()


// Ccoil_test_and_switchCDlg message handlers

BOOL Ccoil_test_and_switchCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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
	//lei begin
	CString str;
	int i;
	for (i = 0; i<5; i++)
	{
		str.Format(_T("COM%d"), i + 1);
		m_comb1.InsertString(i, str);
	}
	m_comb1.SetCurSel(0);//预置COM口
	//lei end

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void Ccoil_test_and_switchCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void Ccoil_test_and_switchCDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR Ccoil_test_and_switchCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//added by lei.gao begin

//added by lei.gao end

void Ccoil_test_and_switchCDlg::OnBnClickedButtonopenclose()
{
	// TODO:  在此添加控件通知处理程序代码
	if (ComIsOpened())	
		CloseHandle(hComm);
	CString PortName, str1;
	GetDlgItemText(IDC_BUTTONOpenClose, str1);
	CWnd *h1;
	h1 = GetDlgItem(IDC_BUTTONOpenClose);
	PortName.Format(_T("COM%d"), m_comb1.GetCurSel() + 1);	
	hComm = CreateFile(PortName, 
		GENERIC_READ | GENERIC_WRITE, 
		0, 
		0, 
		OPEN_EXISTING, 
		0, //FILE_FLAG_OVERLAPPED使用异步通信
		0);
	//ASSERT(hComm != INVALID_HANDLE_VALUE);
	if (hComm == INVALID_HANDLE_VALUE)
	{
		AfxMessageBox(_T("Open Comm Failed"));
		UpdateData(FALSE);
	}
	else
	{
		AfxMessageBox(_T("Open Comm Success")); 
		UpdateData(FALSE);
	}	
	//设置串口参数
	DCB dcb;	
	GetCommState(hComm, &dcb);
	dcb.DCBlength = sizeof(dcb);
	dcb.BaudRate = 9600;
	dcb.Parity = NOPARITY;
	dcb.fParity = 0;
	dcb.StopBits = ONESTOPBIT;
	dcb.fBinary = TRUE;
	dcb.ByteSize = 8;
	SetCommState(hComm, &dcb);
	SetCommMask(hComm, EV_RXCHAR | EV_TXEMPTY);//设置事件驱动的类型
	SetupComm(hComm, 1024, 512); //设置输入、输出缓冲区的大小
	PurgeComm(hComm, PURGE_TXABORT | PURGE_RXABORT | PURGE_TXCLEAR | PURGE_RXCLEAR); //清干净输入、输出缓冲区 
	COMMTIMEOUTS timeouts;//定义超时结构，并填写该结构
	timeouts.ReadIntervalTimeout = MAXDWORD;
	timeouts.ReadTotalTimeoutConstant = 500;
	timeouts.ReadTotalTimeoutMultiplier = 2000;
	timeouts.WriteTotalTimeoutConstant = 50;
	timeouts.WriteTotalTimeoutMultiplier = 2000;
	SetCommTimeouts(hComm, &timeouts);//设置读写操作所允许的超时
	PurgeComm(hComm, PURGE_RXCLEAR | PURGE_TXCLEAR | PURGE_RXABORT | PURGE_TXABORT);
	SetTimer(1, 10, NULL);	
	if (SetCommState(hComm, &dcb))
	{
		str1 = _T("已打开");
		UpdateData(TRUE);
		h1->SetWindowText(str1);
	}
	m_bOpened = TRUE;
	//CDialogEx::OnOK();
}
bool Ccoil_test_and_switchCDlg::Close(VOID)
{
	if (CloseHandle(hComm))
		return TRUE;
	else
		return FALSE;
}

/*
// 工作者线程，负责监视串口
UINT CommProc(LPVOID lParam)
{
	COMSTAT commstat;//这个结构体主要是用来获取端口信息的
	DWORD dwError;
	DWORD dwMask;
	DWORD dwLength;
	OVERLAPPED overlapped;
	//OVERLAPPED结构体用来设置I/O异步，具体可以参见MSDN
	memset(&overlapped, 0, sizeof(OVERLAPPED));
	//初始化OVERLAPPED对象
	overlapped.hEvent = CreateEvent(NULL, TRUE, FALSE, NULL);
	//创建CEvent对象
	Ccoil_test_and_switchCDlg* dlg = (Ccoil_test_and_switchCDlg*)lParam;
	if (dlg->hComm == NULL)
	{
		AfxMessageBox(_T("串口句柄为空!"));
		return -1;
	}
	while (dlg->m_bConnected)
	{
		ClearCommError(dlg->hComm, &dwError, &commstat);
		if (commstat.cbInQue)
			//如果串口inbuf中有接收到的字符就执行下面的操作
		{
			WaitForSingleObject(dlg->m_hPostMsgEvent, INFINITE);
			//无线等待。。。
			ResetEvent(dlg->m_hPostMsgEvent);
			//设置CEvent对象为无信号状态
			::PostMessage(dlg->m_hWnd, WM_COMMSG, EV_RXCHAR, 0);
			//发送特定信息，用来通知特定函数进行处理
			continue;
		}
		if (!WaitCommEvent(dlg->hComm, &dwMask, &overlapped))
		{
			if (GetLastError() == ERROR_IO_PENDING)
				//如果操作被挂起，也就说正在读取或这在写，则进行下面的操作
				GetOverlappedResult(dlg->hComm,
				&overlapped, &dwLength, TRUE);
			//无限等待这个I/O操作的完成
			else
			{
				CloseHandle(overlapped.hEvent);
				return (UINT)-1;
			}
		}
	}
	CloseHandle(overlapped.hEvent);
	return 0;
}
*/


size_t Ccoil_test_and_switchCDlg::ReadComm(char *buf, DWORD dwLength)
{
	COMSTAT comstat;
	DWORD dwError;
	DWORD length;
	DWORD dwByteReaded;
	ClearCommError(hComm, &dwError, &comstat);
	length = min(comstat.cbInQue, dwLength);
	if (!ReadFile(hComm, buf, length, &dwByteReaded, NULL))
		return 0;
	//m_EditRecieve += dwByteReaded;
	return dwByteReaded;

}
void Ccoil_test_and_switchCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "This is some test data to write to the file.";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure
	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");
		
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");
			
		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("请重新插拔线圈获取信息"));
		}
	}
	//AfxMessageBox(_T("请重新插拔线圈获取信息"));
	//int a = MessageBox(TEXT("请重新插拔线圈获取信息？"), TEXT("Warning!!"), 4);
}
void Ccoil_test_and_switchCDlg::OnBnClickedButtonclear()
{
	// TODO: Add your control notification handler code here
	m_strRXData = "";
	UpdateData(FALSE);
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "BEF0DF00000OV";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure
	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");

	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");

		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("切换为常规接收模式"));
		}
	}
	//AfxMessageBox(_T("请重新插拔线圈获取信息"));
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "BEF0DF11111OV";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure
	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");

	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");

		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("切换为体线圈接收模式"));
		}
	}
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "BEF0DF00100OV";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure
	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");

	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");

		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("只开头线圈"));
		}
	}
	//AfxMessageBox(_T("请重新插拔线圈获取信息"));
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton7()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "BEF0DF01000OV";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure
	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");

	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");

		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("只开颈线圈"));
		}
	}
	//AfxMessageBox(_T("请重新插拔线圈获取信息"));
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	//reset check box 
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK4))->SetCheck(BST_UNCHECKED);
	BOOL bErrorFlag = FALSE;
	char DataBuffer[] = "BEF0DF00000OV";
	DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
	DWORD dwBytesWritten = 0;
	bErrorFlag = WriteFile(
		hComm,           // open file handle
		DataBuffer,      // start of data to write
		dwBytesToWrite,  // number of bytes to write
		&dwBytesWritten, // number of bytes that were written
		NULL);            // no overlapped structure

	if (FALSE == bErrorFlag)
	{
		printf("Terminal failure: Unable to write to file.\n");
	}
	else
	{
		if (dwBytesWritten != dwBytesToWrite)
		{
			printf("Error: dwBytesWritten != dwBytesToWrite\n");

		}
		else
		{
			printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
			AfxMessageBox(_T("打开所有通道"));
		}
	}
}
void Ccoil_test_and_switchCDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	int a = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	int b = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
	int c = ((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck();
	int d = ((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck();	
	if (a==1 && b==0 && c==0 && d==0)
	{
		char DataBuffer[] = "BEF0DF00111OV";
		

		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开1-4通道"));
			}
		}
	}
	else if (a==0 && b==1 && c==0 && d==0)
	{
		char DataBuffer[] = "BEF0DF01011OV";
	
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开5-8通道"));
			}
		}
	}

	else if (a == 0 && b == 0 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01101OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开9-12通道"));
			}
		}
	}
	else if (a == 0 && b == 0 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01110OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开13-16通道"));
			}
		}
	}
	else if (a == 1 && b == 1 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00011OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开1-8通道"));
			}
		}
	}
	else if (a == 1 && b == 0 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00101OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开1-4和9-12通道"));
			}
		}
	}
	else if (a == 1 && b == 0 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF00110OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开1-4和13-16通道"));
			}
		}
	}
	else if (a == 0 && b == 1 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01001OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开5-12通道"));
			}
		}
	}
	else if (a == 0 && b == 1 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01010OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开5-8和13-16通道"));
			}
		}
	}
	else if (a == 0 && b == 0 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01100OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开9-16通道"));
			}
		}
	}
	else if (a == 1 && b == 1 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00001OV";
	
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开1-12通道"));
			}
		}
	}
	else if (a == 0 && b == 1 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01000OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("只开5-16通道"));
			}
		}
	}
	else if (a == 1 && b == 1 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF00000OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("开所有通道"));
			}
		}
	}
	else if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01111OV";
		
		DWORD dwBytesToWrite = (DWORD)strlen(DataBuffer);
		DWORD dwBytesWritten = 0;
		bErrorFlag = WriteFile(
			hComm,           // open file handle
			DataBuffer,      // start of data to write
			dwBytesToWrite,  // number of bytes to write
			&dwBytesWritten, // number of bytes that were written
			NULL);            // no overlapped structure
		if (FALSE == bErrorFlag)
		{
			printf("Terminal failure: Unable to write to file.\n");

		}
		else
		{
			if (dwBytesWritten != dwBytesToWrite)
			{
				printf("Error: dwBytesWritten != dwBytesToWrite\n");

			}
			else
			{
				printf("Wrote %d bytes to test.txt successfully.\n", dwBytesWritten);
				AfxMessageBox(_T("关闭所有通道"));
			}
		}
	}
	else 
	{
		char DataBuffer[] = " ";
		AfxMessageBox(_T(" 错误 "));
	}	
}
void Ccoil_test_and_switchCDlg::OnBnClickedButtonopenclose2()
{
	KillTimer(1);
	CloseHandle(hComm);
	UpdateData(TRUE);//读取编辑框内容
	char strTX[1024] = { 0 };
	BOOL bWrite = TRUE;
	BOOL bResult = TRUE;
	DWORD BytesSent = 0;
	CString str;
	//HANDLE m_hWriteEvent;
	int i = 0;
	for (i = 0; i<m_strTXData.GetLength(); i++)
		strTX[i] = (char)m_strTXData.GetAt(i);
	bResult = WriteFile(hComm, strTX, m_strTXData.GetLength(), &BytesSent, NULL);
	// TODO: Add your control notification handler code here
}
