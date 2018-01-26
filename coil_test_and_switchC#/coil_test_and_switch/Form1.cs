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
            private bool Closing = false;
            private bool Listening = false;
            //private long received_count = 0;//接收计数  
            private StringBuilder builder = new StringBuilder();//避免在事件处理方法中反复的创建，定义到外面。  
            public SerialportSampleForm()
            {
                InitializeComponent();
            }
            private SerialPort comm  = new SerialPort();
        
                private void button1_Click(object sender, EventArgs e)
            {
                if (comm.IsOpen)
                {
                    Closing = true;
                    comm.Close();
                    Closing = false;
                }
                else
                {
                    //关闭时点击，则设置好端口参数后打开  
                    comm.PortName = comboPortName.Text;
                    comm.BaudRate = 9600;
                    comm.StopBits = StopBits.One;//
                    comm.DataBits = 8;//
                    comm.Parity = Parity.Even;//设置串口属性
                    comm.Handshake = Handshake.None;
                
                    try
                    {
                        comm.Open();
                    }
                    catch (Exception ex)
                    {  
                        comm = new SerialPort();
                        MessageBox.Show(ex.Message);
                    }
                }
                buttonOpenClose.Text = comm.IsOpen ? "关闭" : "打开";
           
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
                comm.DataReceived += comm_DataReceived;
            }
            void comm_DataReceived(object sender, SerialDataReceivedEventArgs e)
            {
                if (Closing) return;//如果正在关闭，忽略操作，直接返回，尽快的完成串口监听线程的一次循环  
                               
                try
                {
                    Listening = true;  
                    int n = comm.BytesToRead;
                    char[] buf = new char[n];
                    //received_count += n;
                    comm.Read(buf, 0, n);
                    builder.Clear();

                    //char[] cpara = System.Text.Encoding.Default.GetChars(buf);
                    
                    //输出这些信息
                    String para = new String(buf);
                    //string txt = ByteToHexStr(buf); //转换16进制
                    //byte[] txt = strToToHexByte(para);
                    string txt = ConvertStringToHex(para);
                    //string text = Encoding.ASCII.GetString(buf); //ASCII码

                    //string input = comm.ReadLine();
                    //char[] values = input.ToCharArray();
                    //String parain = new String(values);
                    
                        //string s = spara.Substring(12,2); 
                    if (txt.Length < 19)
                        { MessageBox.Show("LengthError"); return; }

                    String s = txt.Substring(11, 2);
                    String spara = "";// new String(cpara); 
                    if(s == "01")
                        spara = "当前线圈为：苏州众志 16通道 头颈上部分线圈";
                    else if(s == "02")
                        spara = "当前线圈为：苏州众志 16通道 头颈下部分线圈";
                    else if(s == "03")
                        spara = "当前线圈为：苏州众志 18通道 脊柱线圈接头1线圈";
                    else if(s == "04")
                        spara = "当前线圈为：苏州众志 18通道 脊柱线圈接头2线圈";
                    else if(s == "05")
                        spara = "当前线圈为：苏州众志 6通道 腹部线圈";
                    else if(s == "06")
                        spara = "当前线圈为：苏州众志 8通道 膝关节线圈";
                    else if(s == "07")
                        spara = "当前线圈为：苏州众志 4通道 肩关节线圈";
                    else if(s == "08")
                        spara = "当前线圈为：苏州众志 8通道 手腕线圈";
                    else if(s == "09")
                        spara = "当前线圈为：苏州众志 8通道 脚踝线圈";
                    else if(s == "10")
                        spara = "当前线圈为：苏州众志 8通道 颈动脉线圈";
                    else if(s == "11")
                        spara = "当前线圈为：苏州众志 8通道 乳腺线圈";
                    else if(s == "17")
                        spara = "当前线圈为：苏州众志 8通道 头线圈";
                    else if(s == "18")
                        spara = "当前线圈为：苏州众志 8通道 躯干线圈";
                    else if(s == "19")
                        spara = "当前线圈为：苏州众志 8通道 颈椎胸椎线圈";
                    else if(s == "21")
                        spara = "当前线圈为：苏州众志 6通道 脊柱线圈";
                    else if(s == "22")
                        spara = "当前线圈为：苏州众志 6通道 脊柱线圈";
                    else if(s == "23")
                        spara = "当前线圈为：苏州众志 8通道 乳腺线圈";
                    else if (s == "23")
                        spara = "当前线圈为：苏州众志 8通道 颈椎线圈";
                    else 
                        spara = "未识别当前线圈";



                    MessageBox.Show(spara);
                    this.Invoke((EventHandler)(delegate
                    {
                        this.textBoxReceive.Clear();
                        //builder.Append("comm.ReadLine:" + parain + "\r\n");
                        builder.Append("String(buf):" + para + "\r\n");
                        builder.Append("MSG:" + spara + "\r\n");
                        builder.Append("HEX:" + txt + "\r\n");
                        this.textBoxReceive.AppendText(builder.ToString());
                    }));
                }
                finally
                {
                    Listening = false;//我用完了，ui可以关闭串口了。  
                }
            }
             /// 字符串转16进制字节数组
            /// </summary>
           /// <param name=”hexString”></param>
            /// <returns></returns>
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
            public static string ByteToHexStr(byte[] bytes) //函数,字节数组转16进制字符串
            {
                string returnStr = "";
                if (bytes != null)
                {
                    for (int i = 0; i < bytes.Length; i++)
                    {
                        returnStr += bytes[i].ToString("x") + (" ");
                    }
                }
                return returnStr;
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
                
            }

            private void textBox3_TextChanged(object sender, EventArgs e)
            {
                

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
        }
}
