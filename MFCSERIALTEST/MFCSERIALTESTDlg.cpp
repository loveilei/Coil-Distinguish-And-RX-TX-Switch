
// MFCSERIALTESTDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "MFCSERIALTEST.h"
#include "MFCSERIALTESTDlg.h"
#include "afxdialogex.h"
#include "SERIALPORT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// 用于应用程序“关于”菜单项的 CAboutDlg 对话框
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// 对话框数据
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	// 实现
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

// CMFCSERIALTESTDlg 对话框

CMFCSERIALTESTDlg::CMFCSERIALTESTDlg(CWnd* pParent /*=NULL*/)
: CDialogEx(CMFCSERIALTESTDlg::IDD, pParent)
, m_Receive(_T(""))
//, m_Send(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCSERIALTESTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_Receive);
	//DDX_Text(pDX, IDC_EDIT2, m_Send);
	DDX_Control(pDX, IDC_COMBO2, m_ComPortNO);
	//DDX_Control(pDX, IDC_COMBO1, m_PortBaud);
	//DDX_Control(pDX, IDC_COMBO3, m_PortDataBits);
	//DDX_Control(pDX, IDC_COMBO4, m_PortStopBits);
	//DDX_Control(pDX, IDC_COMBO5, m_PortParity);
	//DDX_Control(pDX, IDC_CHECK3, m_HexRcvCBtn);
	//DDX_Control(pDX, IDC_CHECK4, m_CharRcvCBtn);
	//DDX_Control(pDX, IDC_CHECK1, m_HexSendCBtn);
	//DDX_Control(pDX, IDC_CHECK2, m_CharSendCBtn);
}

BEGIN_MESSAGE_MAP(CMFCSERIALTESTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CMFCSERIALTESTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON3, &CMFCSERIALTESTDlg::OnBnClickedButton3)
	ON_BN_CLICKED(IDC_BUTTON7, &CMFCSERIALTESTDlg::OnBnClicked_ClosePort)
	ON_MESSAGE(WM_COMM_RXCHAR, &CMFCSERIALTESTDlg::OnRecvData)
	//ON_BN_CLICKED(IDC_CHECK3, &CMFCSERIALTESTDlg::OnBnClickedRecCBtn)
	//ON_BN_CLICKED(IDC_CHECK4, &CMFCSERIALTESTDlg::OnBnClickedCharRecCBtn)
	//ON_BN_CLICKED(IDC_CHECK1, &CMFCSERIALTESTDlg::OnBnClickedHexSendCBtn)
	//ON_BN_CLICKED(IDC_CHECK2, &CMFCSERIALTESTDlg::OnBnClickedCharSendCBtn)
	//ON_BN_CLICKED(IDC_BUTTON5, &CMFCSERIALTESTDlg::OnBnClickedClrSData)
	ON_BN_CLICKED(IDC_BUTTON2, &CMFCSERIALTESTDlg::OnBnClickedSendData)
	//ON_BN_CLICKED(IDC_BUTTON4, &CMFCSERIALTESTDlg::OnBnClickedReFindPort)
	//ON_BN_CLICKED(IDC_BUTTON6, &CMFCSERIALTESTDlg::OnBnClickedSaveRecData)
	ON_BN_CLICKED(IDC_BUTTON4, &CMFCSERIALTESTDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON5, &CMFCSERIALTESTDlg::OnBnClickedButton5)
	ON_BN_CLICKED(IDC_BUTTON6, &CMFCSERIALTESTDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON8, &CMFCSERIALTESTDlg::OnBnClickedButton8)
	ON_BN_CLICKED(IDC_BUTTON9, &CMFCSERIALTESTDlg::OnBnClickedButton9)
	ON_BN_CLICKED(IDC_BUTTON10, &CMFCSERIALTESTDlg::OnBnClickedButton10)
END_MESSAGE_MAP()

// CMFCSERIALTESTDlg 消息处理程序
BOOL CMFCSERIALTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 将“关于...”菜单项添加到系统菜单中。

	// IDM_ABOUTBOX 必须在系统命令范围内。
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

	// 设置此对话框的图标。  当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO:  在此添加额外的初始化代码
	//m_SerialPort = new CSerialPort();
	//初始化串口配置
	m_SerialPort.Hkey2ComboBox(m_ComPortNO);//搜索串口，并将有效串口显示到下拉列表中
	//m_PortBaud.SetCurSel(6);//默认波特率9600
	//m_PortDataBits.SetCurSel(0);//默认数据位8bit
	//m_PortStopBits.SetCurSel(0);//默认停止位1bit
	//m_PortParity.SetCurSel(0);//默认奇偶校检位是无

	//count = 0;
	//初始化发送/接收类型
	//m_HexRcvCBtn.SetCheck(1);//默认十六进制显示接收
	//m_HexSendCBtn.SetCheck(1);//默认十六进制发送

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

void CMFCSERIALTESTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。  对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void CMFCSERIALTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CMFCSERIALTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//接收到数据的消息响应函数
LRESULT CMFCSERIALTESTDlg::OnRecvData(WPARAM wParam, LPARAM lParam)
{
	/*
	CString recvStr((char *)wParam);
	m_Receive += recvStr;
	//for (int k = 0; k < lParam; k++)
	//{
	//m_Send += (char *)wParam + k;
	//}
	UpdateData(false);
	return TRUE;
	int count(0);
	count++;
	unsigned char buffer[1024];
	buffer[count] = (char)wParam;
	m_Receive.Format(_T("%d"), count);
	*/
	
	m_Receive = m_Receive + (char)wParam;
	
	//OutputDebugString(m_Receive + "\n");
	if (-1 != m_Receive.Find(_T("3A72006C")))
		m_Receive = "苏州众志 8通道 膝关节线圈";
	else if (-1 != m_Receive.Find(_T("3A73005C")))
		m_Receive = "苏州众志 8通道 膝关节线圈";
	else if (-1 != m_Receive.Find(_T("3A72007C")))
		m_Receive = "苏州众志 4通道 肩关节线圈";
	else if (-1 != m_Receive.Find(_T("3A73007C")))
		m_Receive = "苏州众志 4通道 肩关节线圈";
	else if (-1 != m_Receive.Find(_T("3A72017C")))
		m_Receive = "苏州众志 8通道 头线圈";
	else if (-1 != m_Receive.Find(_T("3A73004C")))
		m_Receive = "苏州众志 8通道 头线圈";
	else if (-1 != m_Receive.Find(_T("3A72018C")))
		m_Receive = "苏州众志 8通道 躯干线圈";
	else if (-1 != m_Receive.Find(_T("3A72019C")))
		m_Receive = "苏州众志 8通道 颈胸联合线圈";
	else if (-1 != m_Receive.Find(_T("3A72040C")))
		m_Receive = "苏州众志 6通道 脊柱线圈";
	else if (-1 != m_Receive.Find(_T("3A73009C")))
		m_Receive = "苏州众志 6通道 脊柱线圈";
	else if (-1 != m_Receive.Find(_T("3A73016C")))
		m_Receive = "苏州众志 8通道 乳腺线圈";
	

	UpdateData(FALSE);
	return TRUE;
}

//打开串口
void CMFCSERIALTESTDlg::OnBnClickedButton1()
{
	//int portnr = ;
	CString portnrStr;
	UINT portnr;
	UINT baud;
	//UINT parityNum;
	char parity;
	UINT databits;
	UINT stopbits;

	m_ComPortNO.GetLBText(m_ComPortNO.GetCurSel(), portnrStr);
	for (int i = 3; i < portnrStr.GetLength(); i++)
	{
		char ch = portnrStr[i];
		//portnr = (UINT)ch;
		m_Receive += ch;
	}
	portnr = atoi(m_Receive);
	m_Receive = "打开串口" + m_Receive;
	UpdateData(FALSE);
	m_Receive = "";
	//UpdateData(FALSE);
	//110;300;600;1200;2400;4800;9600;14400;19200;28800;38400;56000;57600;115200;128000;256000;


	BOOL IsOpen = m_SerialPort.InitPort(this, portnr, 9600, 8, 1, 0, EV_RXCHAR | EV_RXFLAG, 1024, 1, 1, 1, 1, 1);
	//判断串口是否打开
	if (IsOpen)
	{
		AfxMessageBox(_T("成功打开串口"));
	}
	else
	{
		AfxMessageBox(_T("打开串口失败，请重新打开！"));
	}

	if (m_SerialPort.StartMonitoring())
	{
		//AfxMessageBox(_T("串口线程已成功启动"));
	}
	else
	{
		AfxMessageBox(_T("串口线程启动失败，请检查原因！"));
	}
}

//清除接收框内容
void CMFCSERIALTESTDlg::OnBnClickedButton3()
{
	m_Receive = "";
	UpdateData(false);
}

//关闭串口
void CMFCSERIALTESTDlg::OnBnClicked_ClosePort()
{
	if (m_SerialPort.IsOpen())
	{
		m_SerialPort.ClosePort();
	}
}

//选择十六进制模式显示接收到的数据
//选择字符模式显示接收到的数据
//选择十六进制发送模式
//选择字符发送模式
//清除发送框内容
//void CMFCSERIALTESTDlg::OnBnClickedClrSData()
//{
//	m_Send = "";
//	UpdateData(FALSE);
//}
//发送数据
void CMFCSERIALTESTDlg::OnBnClickedSendData()
{
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("This is some test data to write to the file.");
		AfxMessageBox("请拔插线圈以获取线圈信息！");
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}

//字符串转十六进制
int CMFCSERIALTESTDlg::String2Hex(CString str, BYTE *senddata)
{
	int hexdata, lowhexdata;
	int hexdatalen = 0;
	int len = str.GetLength();
	//senddata.SetSize(len / 2);
	for (int i = 0; i < len;)
	{
		char lstr, hstr = str[i];
		if (hstr == ' ')
		{
			i++;
			continue;
		}
		i++;
		if (i >= len)
			break;
		lstr = str[i];
		hexdata = ConvertHexChar(hstr);
		lowhexdata = ConvertHexChar(lstr);
		if ((hexdata == 16) || (lowhexdata == 16))
			break;
		else
			hexdata = hexdata * 16 + lowhexdata;
		i++;
		senddata[hexdatalen] = (char)hexdata;
		hexdatalen++;
	}
	//senddata.SetSize(hexdatalen);
	return hexdatalen;
}

char CMFCSERIALTESTDlg::ConvertHexChar(char ch)
{
	if ((ch >= '0') && (ch <= '9'))
		return ch - 0x30;
	else if ((ch >= 'A') && (ch <= 'F'))
		return ch - 'A' + 10;
	else if ((ch >= 'a') && (ch <= 'f'))
		return ch - 'a' + 10;
	else return (-1);
}

//重新搜索串口


// 保存接收到的数据


void CMFCSERIALTESTDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF00000OV");
		AfxMessageBox(_T("切换为常规接收模式"));
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF11111OV");
		AfxMessageBox(_T("切换为体线圈接收模式"));
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF00100OV");
		AfxMessageBox(_T("只开头线圈"));
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF01000OV");
		AfxMessageBox(_T("只开颈线圈"));
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}
void CMFCSERIALTESTDlg::OnBnClickedButton9()
{
	// TODO: Add your control notification handler code here
	//reset check box 
	((CButton *)GetDlgItem(IDC_CHECK1))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK2))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK3))->SetCheck(BST_UNCHECKED);
	((CButton *)GetDlgItem(IDC_CHECK4))->SetCheck(BST_UNCHECKED);
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF00000OV");
		AfxMessageBox(_T("重置成功"));
	}
	else
	{
		AfxMessageBox("串口未打开，请打开串口再重试！");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton10()
{
	// TODO: Add your control notification handler code here
	BOOL bErrorFlag = FALSE;
	int a = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck();
	int b = ((CButton *)GetDlgItem(IDC_CHECK2))->GetCheck();
	int c = ((CButton *)GetDlgItem(IDC_CHECK3))->GetCheck();
	int d = ((CButton *)GetDlgItem(IDC_CHECK4))->GetCheck();
	if (a == 1 && b == 0 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00111OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开1-4通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 1 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01011OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开5-8通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 0 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01101OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开9-12通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 0 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01110OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开13-16通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 1 && b == 1 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00011OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开1-8通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 1 && b == 0 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00101OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开1-4和9-12通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 1 && b == 0 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF00110OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开1-4和13-16通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 1 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01001OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开5-12通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 1 && c == 0 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01010OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开5-8和13-16通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 0 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01100OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开9-16通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 1 && b == 1 && c == 1 && d == 0)
	{
		char DataBuffer[] = "BEF0DF00001OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开1-12通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 1 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF01000OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("只开5-16通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 1 && b == 1 && c == 1 && d == 1)
	{
		char DataBuffer[] = "BEF0DF00000OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("开所有通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else if (a == 0 && b == 0 && c == 0 && d == 0)
	{
		char DataBuffer[] = "BEF0DF01111OV";
		CString DatBuf = DataBuffer;
		if (m_SerialPort.IsOpen())
		{
			UpdateData(TRUE);
			m_SerialPort.WriteToPort(DatBuf);
			AfxMessageBox(_T("关闭所有通道"));
		}
		else
		{
			AfxMessageBox("串口未打开，请打开串口再重试！");
		}
	}
	else
	{
		//char DataBuffer[] = " ";
		AfxMessageBox(_T(" 错误 "));
	}
}
