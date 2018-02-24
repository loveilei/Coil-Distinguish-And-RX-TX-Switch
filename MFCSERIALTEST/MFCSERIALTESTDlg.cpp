
// MFCSERIALTESTDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "MFCSERIALTEST.h"
#include "MFCSERIALTESTDlg.h"
#include "afxdialogex.h"
#include "SERIALPORT.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���
class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

	// �Ի�������
	enum { IDD = IDD_ABOUTBOX };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	// ʵ��
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

// CMFCSERIALTESTDlg �Ի���

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

// CMFCSERIALTESTDlg ��Ϣ�������
BOOL CMFCSERIALTESTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO:  �ڴ���Ӷ���ĳ�ʼ������
	//m_SerialPort = new CSerialPort();
	//��ʼ����������
	m_SerialPort.Hkey2ComboBox(m_ComPortNO);//�������ڣ�������Ч������ʾ�������б���
	//m_PortBaud.SetCurSel(6);//Ĭ�ϲ�����9600
	//m_PortDataBits.SetCurSel(0);//Ĭ������λ8bit
	//m_PortStopBits.SetCurSel(0);//Ĭ��ֹͣλ1bit
	//m_PortParity.SetCurSel(0);//Ĭ����żУ��λ����

	//count = 0;
	//��ʼ������/��������
	//m_HexRcvCBtn.SetCheck(1);//Ĭ��ʮ��������ʾ����
	//m_HexSendCBtn.SetCheck(1);//Ĭ��ʮ�����Ʒ���

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CMFCSERIALTESTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CMFCSERIALTESTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

//���յ����ݵ���Ϣ��Ӧ����
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
		m_Receive = "������־ 8ͨ�� ϥ�ؽ���Ȧ";
	else if (-1 != m_Receive.Find(_T("3A73005C")))
		m_Receive = "������־ 8ͨ�� ϥ�ؽ���Ȧ";
	else if (-1 != m_Receive.Find(_T("3A72007C")))
		m_Receive = "������־ 4ͨ�� ��ؽ���Ȧ";
	else if (-1 != m_Receive.Find(_T("3A73007C")))
		m_Receive = "������־ 4ͨ�� ��ؽ���Ȧ";
	else if (-1 != m_Receive.Find(_T("3A72017C")))
		m_Receive = "������־ 8ͨ�� ͷ��Ȧ";
	else if (-1 != m_Receive.Find(_T("3A73004C")))
		m_Receive = "������־ 8ͨ�� ͷ��Ȧ";
	else if (-1 != m_Receive.Find(_T("3A72018C")))
		m_Receive = "������־ 8ͨ�� ������Ȧ";
	else if (-1 != m_Receive.Find(_T("3A72019C")))
		m_Receive = "������־ 8ͨ�� ����������Ȧ";
	else if (-1 != m_Receive.Find(_T("3A72040C")))
		m_Receive = "������־ 6ͨ�� ������Ȧ";
	else if (-1 != m_Receive.Find(_T("3A73009C")))
		m_Receive = "������־ 6ͨ�� ������Ȧ";
	else if (-1 != m_Receive.Find(_T("3A73016C")))
		m_Receive = "������־ 8ͨ�� ������Ȧ";
	

	UpdateData(FALSE);
	return TRUE;
}

//�򿪴���
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
	m_Receive = "�򿪴���" + m_Receive;
	UpdateData(FALSE);
	m_Receive = "";
	//UpdateData(FALSE);
	//110;300;600;1200;2400;4800;9600;14400;19200;28800;38400;56000;57600;115200;128000;256000;


	BOOL IsOpen = m_SerialPort.InitPort(this, portnr, 9600, 8, 1, 0, EV_RXCHAR | EV_RXFLAG, 1024, 1, 1, 1, 1, 1);
	//�жϴ����Ƿ��
	if (IsOpen)
	{
		AfxMessageBox(_T("�ɹ��򿪴���"));
	}
	else
	{
		AfxMessageBox(_T("�򿪴���ʧ�ܣ������´򿪣�"));
	}

	if (m_SerialPort.StartMonitoring())
	{
		//AfxMessageBox(_T("�����߳��ѳɹ�����"));
	}
	else
	{
		AfxMessageBox(_T("�����߳�����ʧ�ܣ�����ԭ��"));
	}
}

//������տ�����
void CMFCSERIALTESTDlg::OnBnClickedButton3()
{
	m_Receive = "";
	UpdateData(false);
}

//�رմ���
void CMFCSERIALTESTDlg::OnBnClicked_ClosePort()
{
	if (m_SerialPort.IsOpen())
	{
		m_SerialPort.ClosePort();
	}
}

//ѡ��ʮ������ģʽ��ʾ���յ�������
//ѡ���ַ�ģʽ��ʾ���յ�������
//ѡ��ʮ�����Ʒ���ģʽ
//ѡ���ַ�����ģʽ
//������Ϳ�����
//void CMFCSERIALTESTDlg::OnBnClickedClrSData()
//{
//	m_Send = "";
//	UpdateData(FALSE);
//}
//��������
void CMFCSERIALTESTDlg::OnBnClickedSendData()
{
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("This is some test data to write to the file.");
		AfxMessageBox("��β���Ȧ�Ի�ȡ��Ȧ��Ϣ��");
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
	}
}

//�ַ���תʮ������
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

//������������


// ������յ�������


void CMFCSERIALTESTDlg::OnBnClickedButton4()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF00000OV");
		AfxMessageBox(_T("�л�Ϊ�������ģʽ"));
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton5()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF11111OV");
		AfxMessageBox(_T("�л�Ϊ����Ȧ����ģʽ"));
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton6()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF00100OV");
		AfxMessageBox(_T("ֻ��ͷ��Ȧ"));
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
	}
}


void CMFCSERIALTESTDlg::OnBnClickedButton8()
{
	// TODO: Add your control notification handler code here
	if (m_SerialPort.IsOpen())
	{
		UpdateData(TRUE);
		m_SerialPort.WriteToPort("BEF0DF01000OV");
		AfxMessageBox(_T("ֻ������Ȧ"));
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
		AfxMessageBox(_T("���óɹ�"));
	}
	else
	{
		AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��1-4ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��5-8ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��9-12ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��13-16ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��1-8ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��1-4��9-12ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��1-4��13-16ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��5-12ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��5-8��13-16ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��9-16ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��1-12ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("ֻ��5-16ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("������ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
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
			AfxMessageBox(_T("�ر�����ͨ��"));
		}
		else
		{
			AfxMessageBox("����δ�򿪣���򿪴��������ԣ�");
		}
	}
	else
	{
		//char DataBuffer[] = " ";
		AfxMessageBox(_T(" ���� "));
	}
}
