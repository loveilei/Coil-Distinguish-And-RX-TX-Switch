using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO.Ports;
using System.Text.RegularExpressions;

namespace coil_test_and_switch
{


    public partial class SerialportSampleForm : Form
    {
        private bool Closin = false;
        private StringBuilder builder = new StringBuilder(); 
        public SerialportSampleForm()
        {
            InitializeComponent();
        }
        private SerialPort comm = new SerialPort();
        private void SerialportSampleForm_Load_1(object sender, EventArgs e)
        {
            string[] ports = SerialPort.GetPortNames();
            if (ports == null)
            {
                MessageBox.Show("本机没有串口！", "Error");
                return;
            }
            Array.Sort(ports);
            comboPortName.Items.AddRange(ports);
            comboPortName.SelectedIndex = comboPortName.Items.Count > 0 ? 0 : -1;
            //comm.DataReceived += comm_DataReceived;
            //
        }
        private void button1_Click(object sender, EventArgs e)
        {

            if (comm.IsOpen)
            {
                Closin = true;
                comm.Close();
                Closin = false;
            }
            else
            {
                try
                {
                    comm.PortName = comboPortName.Text;
                    comm.BaudRate = 9600;
                    comm.StopBits = StopBits.One;//
                    comm.DataBits = 8;//
                    comm.Parity = Parity.None;//设置串口属性
                    comm.Handshake = Handshake.None;
                    comm.ReadTimeout = 1000;
                    comm.WriteTimeout = 1000; 
                    comm.Open();
                    comm.DiscardInBuffer();

                }
                catch (Exception ex)
                {
                    comm = new SerialPort();
                    MessageBox.Show(ex.Message);
                }
            }
            comm.DataReceived += comm_DataReceived;
            buttonOpenClose.Text = comm.IsOpen ? "关闭" : "打开";

        }
        

        void comm_DataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            if (Closin) return;//如果正在关闭，忽略操作，直接返回，尽快的完成串口监听线程的一次循环  
            if (comm.BytesToRead <= 0)
            {
                return;
            }
            System.Threading.Thread.Sleep(20);
            int len = comm.BytesToRead;
            Byte[] data = new Byte[len];
            comm.Read(data, 0, len);
            string para = Encoding.ASCII.GetString(data);
            string para2 = ByteToHexStr(data); //转换16进制
            builder.Clear();
            //String data = comm.ReadExisting();
            /*
            //1.缓存数据
            buffer.AddRange(data);//不断地将接收到的数据加入到buffer链表中
            //2.完整性判断
            while (buffer.Count >= 4) //至少包含帧头（2字节）、长度（1字节）、功能位（1字节）；根据设计不同而不同
            {
                //2.1 查找数据头
                if (buffer[0] == 0x0AA) //传输数据有帧头，用于判断. 找到帧头  AA AA 0A 
                {
                    int len = buffer[2];
                    //int len = 79;
                    if (buffer.Count < len + 4) //数据区尚未接收完整，
                    {
                        break;//跳出接收函数后之后继续接收数据
                    }
                    //得到完整的数据，复制到ReceiveBytes中进行校验
                    buffer.CopyTo(0, ReceiveBytes, 0, len + 4);//
                    byte jiaoyan; //开始校验
                    jiaoyan = 0x01;//jiaoyan = this.JY(ReceiveBytes);

                    if (jiaoyan != ReceiveBytes[3]) //验证功能位失败    if (jiaoyan != ReceiveBytes[len+3])
                    {
                        buffer.RemoveRange(0, len + 4);//从链表中移除接收到的校验失败的数据，
                        //MessageBox.Show("数据包不正确！");//显示数据包不正确,
                        continue;//继续执行while循环程序,
                    }
                    buffer.RemoveRange(0, len + 4);
                    //执行其他代码，对数据进行处理。
                    //解析5 6， 7 8字节的经纬度.
                    DataProgress();
                }
                else //帧头不正确时，记得清除
                {
                    buffer.RemoveAt(0);//清除第一个字节，继续检测下一个。
                }
            }
                //comm.DiscardInBuffer();
                //string dtmStr = System.Text.Encoding.Default.GetString(data);//.TrimEnd('\0');

                //String para2 = Bytes2Hex(data);
                int n = comm.BytesToRead;
                char[] buf = new char[n];
                //received_count += n;
                comm.Read(buf, 0, n);
                builder.Clear();
                //char[] cpara = System.Text.Encoding.Default.GetChars(buf);
                //输出这些信息
                //String para = new String(buf);
                //string txt = ByteToHexStr(buf); //转换16进制
                //byte[] txt = strToToHexByte(para);
                //string txt = ConvertStringToHex(readbuffer);
                //string text = Encoding.ASCII.GetString(buf); //ASCII码
                //string input = comm.ReadLine();
                //char[] values = input.ToCharArray();
                //String parain = new String(values);
                //string s = spara.Substring(12,2); 
                 
             */
            
            if (para2.Length >= 29 && para2.Substring(0, 5) == "43 43" && para2.Substring(27, 2) == "41")
            {

                if (para2.Length < 15)
                { MessageBox.Show("LengthError"); return; }

                String s = para2.Substring(12, 2);
                

                String spara = "";
                if (s == "01")
                    spara = "当前线圈为：苏州众志 16通道 头颈上部分线圈";
                else if (s == "02")
                    spara = "当前线圈为：苏州众志 16通道 头颈下部分线圈";
                else if (s == "03")
                    spara = "当前线圈为：苏州众志 18通道 脊柱线圈接头1线圈";
                else if (s == "04")
                    spara = "当前线圈为：苏州众志 18通道 脊柱线圈接头2线圈";
                else if (s == "05")
                    spara = "当前线圈为：苏州众志 6通道 腹部线圈";
                else if (s == "06")
                    spara = "当前线圈为：苏州众志 8通道 膝关节线圈";
                else if (s == "07")
                    spara = "当前线圈为：苏州众志 4通道 肩关节线圈";
                else if (s == "08")
                    spara = "当前线圈为：苏州众志 8通道 手腕线圈";
                else if (s == "09")
                    spara = "当前线圈为：苏州众志 8通道 脚踝线圈";
                else if (s == "10")
                    spara = "当前线圈为：苏州众志 8通道 颈动脉线圈";
                else if (s == "11")
                    spara = "当前线圈为：苏州众志 8通道 乳腺线圈";
                else if (s == "17")
                    spara = "当前线圈为：苏州众志 8通道 头线圈";
                else if (s == "18")
                    spara = "当前线圈为：苏州众志 8通道 躯干线圈";
                else if (s == "19")
                    spara = "当前线圈为：苏州众志 8通道 颈椎胸椎线圈";
                else if (s == "21")
                    spara = "当前线圈为：苏州众志 6通道 脊柱线圈";
                else if (s == "22")
                    spara = "当前线圈为：苏州众志 6通道 脊柱线圈";
                else if (s == "23")
                    spara = "当前线圈为：苏州众志 8通道 乳腺线圈";
                else if (s == "")
                    spara = "当前线圈为：苏州众志 8通道 颈椎线圈";
                else
                    spara = "未识别当前线圈";

                MessageBox.Show(spara);
                this.Invoke((EventHandler)(delegate
                {
                    this.textBoxReceive.Clear();
                    builder.Append("ByteToHexStr:" + para2 + "\r\n");
                    builder.Append(spara + "\r\n");
                    builder.Append("comm.Read:" + para + "\r\n");
                    this.textBoxReceive.AppendText(builder.ToString());
                }));
            }
            else
            {
                this.Invoke((EventHandler)(delegate
                {
                    this.textBoxReceive.Clear();
                    builder.Append("ByteToHexStr:" + para2 + "\r\n");
                    builder.Append("comm.Read:" + para + "\r\n");
                    this.textBoxReceive.AppendText(builder.ToString());
                }));
            }

        }

        private static string extractData(string data)
        {
            //const byte stx = 0x41;
            const byte etx = 0x43;

            return data.TrimEnd(new char[] { (char)etx });
        }


        public static String Bytes2Hex(Byte[] bytes)
        {
            return BitConverter.ToString(bytes);
        }
        public static string ByteToHexStr(byte[] bytes) //函数,字节数组转16进制字符串
        {
            //return BitConverter.ToString(bytes);/*
            string returnStr = "";
            if (bytes != null)
            {
                for (int i = 0; i < bytes.Length; i++)
                {
                    returnStr += bytes[i].ToString("X2") + (" ");
                }
            }
            return returnStr;
        }
        public static byte[] strToToHexByte(string hexString)
        {
            hexString = hexString.Replace(" ", "");
            if ((hexString.Length % 2) != 0)
                hexString += " ";
            byte[] returnBytes = new byte[hexString.Length / 2];
            for (int i = 0; i < returnBytes.Length; i++)
                returnBytes[i] = Convert.ToByte(hexString.Substring(i * 2, 2), 16);
            return returnBytes;
        }
        public string ConvertStringToHex(string strASCII, string separator = null)
        {
            StringBuilder sbHex = new StringBuilder();
            foreach (char chr in strASCII)
            {
                sbHex.Append(String.Format("{0:X2}", Convert.ToInt32(chr)));
                sbHex.Append(separator ?? string.Empty);
            }
            return sbHex.ToString();
        }
        public string ConvertHexToString(string HexValue, string separator = null)
        {
            HexValue = string.IsNullOrEmpty(separator) ? HexValue : HexValue.Replace(string.Empty, separator);
            StringBuilder sbStrValue = new StringBuilder();
            while (HexValue.Length > 0)
            {
                sbStrValue.Append(Convert.ToChar(Convert.ToUInt32(HexValue.Substring(0, 2), 16)).ToString());
                HexValue = HexValue.Substring(2);
            }
            return sbStrValue.ToString();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("NULL");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            MessageBox.Show("请拔插线圈以获取线圈数据");

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

            textBoxReceive.SelectionStart = textBoxReceive.Text.Length;
            textBoxReceive.ScrollToCaret();

        }

        private void button1_Click_1(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("BE0DF200100OV");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            if (comm.IsOpen)
            {
                MessageBox.Show("只开头线圈");
            }
        }

        private void button2_Click_1(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("BE0DF201000OV");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            if (comm.IsOpen)
            {
                MessageBox.Show("只开颈线圈");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("BE0DF200000OV");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            if (comm.IsOpen)
            {
                MessageBox.Show("打开所有通道");
            }
        }
        private void button5_Click(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("BE0DF200000OV");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            if (comm.IsOpen)
            {
                MessageBox.Show("切换为常规接收模式");
            }
        }

        private void button6_Click(object sender, EventArgs e)
        {
            try
            {
                comm.WriteLine("BE0DF211111OV");//往串口写数据
            }
            catch (Exception ex)
            {
                comm = new SerialPort();
                MessageBox.Show(ex.Message);
            }
            if (comm.IsOpen)
            {
                MessageBox.Show("切换为体线圈接收模式");
            }
        }



        private void comboPortName_SelectedIndexChanged(object sender, EventArgs e)
        {

        }

        private void 清空_Click(object sender, EventArgs e)
        {
            textBoxReceive.Text = "";
        }
    }
}
