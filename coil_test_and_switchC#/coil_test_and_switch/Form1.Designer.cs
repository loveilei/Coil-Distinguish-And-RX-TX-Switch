namespace coil_test_and_switch
{
    partial class SerialportSampleForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(SerialportSampleForm));
            this.comboPortName = new System.Windows.Forms.ComboBox();
            this.buttonOpenClose = new System.Windows.Forms.Button();
            this.buttonRxReceive = new System.Windows.Forms.Button();
            this.buttonTxReceive = new System.Windows.Forms.Button();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.cleanScreen = new System.Windows.Forms.Button();
            this.groupBox3 = new System.Windows.Forms.GroupBox();
            this.textBox4 = new System.Windows.Forms.TextBox();
            this.textBox5 = new System.Windows.Forms.TextBox();
            this.label5 = new System.Windows.Forms.Label();
            this.label6 = new System.Windows.Forms.Label();
            this.label7 = new System.Windows.Forms.Label();
            this.textBox6 = new System.Windows.Forms.TextBox();
            this.textBoxReceive = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.groupBox2 = new System.Windows.Forms.GroupBox();
            this.groupBox4 = new System.Windows.Forms.GroupBox();
            this.button3 = new System.Windows.Forms.Button();
            this.button2 = new System.Windows.Forms.Button();
            this.button1 = new System.Windows.Forms.Button();
            this.buttonAcqCoilInfo = new System.Windows.Forms.Button();
            this.groupBox5 = new System.Windows.Forms.GroupBox();
            this.groupBox6 = new System.Windows.Forms.GroupBox();
            this.textBox1 = new System.Windows.Forms.TextBox();
            this.textBox2 = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.label3 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.textBox7 = new System.Windows.Forms.TextBox();
            this.checkBoxCh1_4 = new System.Windows.Forms.CheckBox();
            this.checkBoxCh5_8 = new System.Windows.Forms.CheckBox();
            this.checkBoxCh9_12 = new System.Windows.Forms.CheckBox();
            this.checkBoxCh13_16 = new System.Windows.Forms.CheckBox();
            this.buttonApply = new System.Windows.Forms.Button();
            this.groupBox7 = new System.Windows.Forms.GroupBox();
            this.groupBox1.SuspendLayout();
            this.groupBox3.SuspendLayout();
            this.groupBox2.SuspendLayout();
            this.groupBox4.SuspendLayout();
            this.groupBox5.SuspendLayout();
            this.groupBox6.SuspendLayout();
            this.groupBox7.SuspendLayout();
            this.SuspendLayout();
            // 
            // comboPortName
            // 
            this.comboPortName.FormattingEnabled = true;
            this.comboPortName.Location = new System.Drawing.Point(100, 27);
            this.comboPortName.Name = "comboPortName";
            this.comboPortName.Size = new System.Drawing.Size(121, 26);
            this.comboPortName.TabIndex = 0;
            this.comboPortName.UseWaitCursor = true;
            this.comboPortName.SelectedIndexChanged += new System.EventHandler(this.comboPortName_SelectedIndexChanged);
            // 
            // buttonOpenClose
            // 
            this.buttonOpenClose.BackColor = System.Drawing.Color.White;
            this.buttonOpenClose.Location = new System.Drawing.Point(288, 22);
            this.buttonOpenClose.Name = "buttonOpenClose";
            this.buttonOpenClose.Size = new System.Drawing.Size(126, 34);
            this.buttonOpenClose.TabIndex = 2;
            this.buttonOpenClose.Text = "打开端口";
            this.buttonOpenClose.UseVisualStyleBackColor = true;
            this.buttonOpenClose.UseWaitCursor = true;
            this.buttonOpenClose.Click += new System.EventHandler(this.button1_Click);
            // 
            // buttonRxReceive
            // 
            this.buttonRxReceive.AutoSize = true;
            this.buttonRxReceive.BackColor = System.Drawing.SystemColors.Window;
            this.buttonRxReceive.Location = new System.Drawing.Point(267, 32);
            this.buttonRxReceive.Name = "buttonRxReceive";
            this.buttonRxReceive.Size = new System.Drawing.Size(171, 49);
            this.buttonRxReceive.TabIndex = 6;
            this.buttonRxReceive.Text = "常规接收模式";
            this.buttonRxReceive.UseVisualStyleBackColor = true;
            this.buttonRxReceive.UseWaitCursor = true;
            this.buttonRxReceive.Click += new System.EventHandler(this.button5_Click);
            // 
            // buttonTxReceive
            // 
            this.buttonTxReceive.AutoSize = true;
            this.buttonTxReceive.BackColor = System.Drawing.SystemColors.Window;
            this.buttonTxReceive.Location = new System.Drawing.Point(32, 32);
            this.buttonTxReceive.Name = "buttonTxReceive";
            this.buttonTxReceive.Size = new System.Drawing.Size(171, 49);
            this.buttonTxReceive.TabIndex = 7;
            this.buttonTxReceive.Text = "体线圈接收模式";
            this.buttonTxReceive.UseVisualStyleBackColor = true;
            this.buttonTxReceive.UseWaitCursor = true;
            this.buttonTxReceive.Click += new System.EventHandler(this.button6_Click);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.cleanScreen);
            this.groupBox1.Controls.Add(this.groupBox3);
            this.groupBox1.Controls.Add(this.textBoxReceive);
            this.groupBox1.Location = new System.Drawing.Point(49, 134);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(492, 102);
            this.groupBox1.TabIndex = 8;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "当前线圈信息";
            this.groupBox1.UseWaitCursor = true;
            // 
            // cleanScreen
            // 
            this.cleanScreen.BackColor = System.Drawing.Color.White;
            this.cleanScreen.ForeColor = System.Drawing.SystemColors.ControlText;
            this.cleanScreen.Location = new System.Drawing.Point(404, -3);
            this.cleanScreen.Name = "cleanScreen";
            this.cleanScreen.Size = new System.Drawing.Size(83, 34);
            this.cleanScreen.TabIndex = 16;
            this.cleanScreen.Text = "清空";
            this.cleanScreen.UseVisualStyleBackColor = true;
            this.cleanScreen.UseWaitCursor = true;
            this.cleanScreen.Click += new System.EventHandler(this.清空_Click);
            // 
            // groupBox3
            // 
            this.groupBox3.Controls.Add(this.textBox4);
            this.groupBox3.Controls.Add(this.textBox5);
            this.groupBox3.Controls.Add(this.label5);
            this.groupBox3.Controls.Add(this.label6);
            this.groupBox3.Controls.Add(this.label7);
            this.groupBox3.Controls.Add(this.textBox6);
            this.groupBox3.Location = new System.Drawing.Point(1, 192);
            this.groupBox3.Name = "groupBox3";
            this.groupBox3.Size = new System.Drawing.Size(492, 175);
            this.groupBox3.TabIndex = 15;
            this.groupBox3.TabStop = false;
            this.groupBox3.Text = "线圈信息";
            this.groupBox3.UseWaitCursor = true;
            // 
            // textBox4
            // 
            this.textBox4.Location = new System.Drawing.Point(130, 126);
            this.textBox4.Name = "textBox4";
            this.textBox4.Size = new System.Drawing.Size(157, 28);
            this.textBox4.TabIndex = 14;
            this.textBox4.UseWaitCursor = true;
            // 
            // textBox5
            // 
            this.textBox5.Location = new System.Drawing.Point(130, 76);
            this.textBox5.Name = "textBox5";
            this.textBox5.Size = new System.Drawing.Size(157, 28);
            this.textBox5.TabIndex = 13;
            this.textBox5.UseWaitCursor = true;
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(27, 129);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(98, 18);
            this.label5.TabIndex = 12;
            this.label5.Text = "通道数量：";
            this.label5.UseWaitCursor = true;
            // 
            // label6
            // 
            this.label6.AutoSize = true;
            this.label6.Location = new System.Drawing.Point(27, 34);
            this.label6.Name = "label6";
            this.label6.Size = new System.Drawing.Size(98, 18);
            this.label6.TabIndex = 11;
            this.label6.Text = "线圈厂家：";
            this.label6.UseWaitCursor = true;
            // 
            // label7
            // 
            this.label7.AutoSize = true;
            this.label7.Location = new System.Drawing.Point(27, 79);
            this.label7.Name = "label7";
            this.label7.Size = new System.Drawing.Size(98, 18);
            this.label7.TabIndex = 10;
            this.label7.Text = "线圈名称：";
            this.label7.UseWaitCursor = true;
            // 
            // textBox6
            // 
            this.textBox6.Location = new System.Drawing.Point(130, 27);
            this.textBox6.Name = "textBox6";
            this.textBox6.Size = new System.Drawing.Size(157, 28);
            this.textBox6.TabIndex = 1;
            this.textBox6.UseWaitCursor = true;
            // 
            // textBoxReceive
            // 
            this.textBoxReceive.Location = new System.Drawing.Point(7, 27);
            this.textBoxReceive.Multiline = true;
            this.textBoxReceive.Name = "textBoxReceive";
            this.textBoxReceive.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.textBoxReceive.Size = new System.Drawing.Size(478, 62);
            this.textBoxReceive.TabIndex = 1;
            this.textBoxReceive.UseWaitCursor = true;
            this.textBoxReceive.TextChanged += new System.EventHandler(this.textBox3_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(7, 31);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(98, 18);
            this.label1.TabIndex = 9;
            this.label1.Text = "选择端口：";
            this.label1.UseWaitCursor = true;
            // 
            // groupBox2
            // 
            this.groupBox2.AutoSize = true;
            this.groupBox2.Controls.Add(this.buttonRxReceive);
            this.groupBox2.Controls.Add(this.buttonTxReceive);
            this.groupBox2.Location = new System.Drawing.Point(49, 242);
            this.groupBox2.Name = "groupBox2";
            this.groupBox2.Size = new System.Drawing.Size(492, 108);
            this.groupBox2.TabIndex = 9;
            this.groupBox2.TabStop = false;
            this.groupBox2.Text = "接收线圈切换";
            this.groupBox2.UseWaitCursor = true;
            // 
            // groupBox4
            // 
            this.groupBox4.Controls.Add(this.button3);
            this.groupBox4.Controls.Add(this.button2);
            this.groupBox4.Controls.Add(this.button1);
            this.groupBox4.Location = new System.Drawing.Point(49, 356);
            this.groupBox4.Name = "groupBox4";
            this.groupBox4.Size = new System.Drawing.Size(494, 124);
            this.groupBox4.TabIndex = 16;
            this.groupBox4.TabStop = false;
            this.groupBox4.Text = "头颈线圈失谐设定";
            this.groupBox4.UseWaitCursor = true;
            // 
            // button3
            // 
            this.button3.BackColor = System.Drawing.SystemColors.Window;
            this.button3.Location = new System.Drawing.Point(400, 12);
            this.button3.Name = "button3";
            this.button3.Size = new System.Drawing.Size(88, 34);
            this.button3.TabIndex = 2;
            this.button3.Text = "重置";
            this.button3.UseVisualStyleBackColor = true;
            this.button3.UseWaitCursor = true;
            this.button3.Click += new System.EventHandler(this.button3_Click);
            // 
            // button2
            // 
            this.button2.BackColor = System.Drawing.SystemColors.Window;
            this.button2.Location = new System.Drawing.Point(267, 63);
            this.button2.Name = "button2";
            this.button2.Size = new System.Drawing.Size(171, 43);
            this.button2.TabIndex = 1;
            this.button2.Text = "只开颈线圈部分";
            this.button2.UseVisualStyleBackColor = true;
            this.button2.UseWaitCursor = true;
            this.button2.Click += new System.EventHandler(this.button2_Click_1);
            // 
            // button1
            // 
            this.button1.BackColor = System.Drawing.SystemColors.Window;
            this.button1.Location = new System.Drawing.Point(32, 63);
            this.button1.Name = "button1";
            this.button1.Size = new System.Drawing.Size(171, 43);
            this.button1.TabIndex = 0;
            this.button1.Text = "只开头线圈部分";
            this.button1.UseVisualStyleBackColor = true;
            this.button1.UseWaitCursor = true;
            this.button1.Click += new System.EventHandler(this.button1_Click_1);
            // 
            // buttonAcqCoilInfo
            // 
            this.buttonAcqCoilInfo.BackColor = System.Drawing.Color.White;
            this.buttonAcqCoilInfo.Location = new System.Drawing.Point(287, 62);
            this.buttonAcqCoilInfo.Name = "buttonAcqCoilInfo";
            this.buttonAcqCoilInfo.Size = new System.Drawing.Size(175, 34);
            this.buttonAcqCoilInfo.TabIndex = 17;
            this.buttonAcqCoilInfo.Text = "获取当前线圈信息";
            this.buttonAcqCoilInfo.UseVisualStyleBackColor = true;
            this.buttonAcqCoilInfo.UseWaitCursor = true;
            this.buttonAcqCoilInfo.Click += new System.EventHandler(this.button2_Click);
            // 
            // groupBox5
            // 
            this.groupBox5.Controls.Add(this.buttonAcqCoilInfo);
            this.groupBox5.Controls.Add(this.groupBox6);
            this.groupBox5.Controls.Add(this.comboPortName);
            this.groupBox5.Controls.Add(this.label1);
            this.groupBox5.Controls.Add(this.buttonOpenClose);
            this.groupBox5.Location = new System.Drawing.Point(50, 27);
            this.groupBox5.Name = "groupBox5";
            this.groupBox5.Size = new System.Drawing.Size(492, 102);
            this.groupBox5.TabIndex = 16;
            this.groupBox5.TabStop = false;
            this.groupBox5.Text = "端口信息";
            this.groupBox5.UseWaitCursor = true;
            // 
            // groupBox6
            // 
            this.groupBox6.Controls.Add(this.textBox1);
            this.groupBox6.Controls.Add(this.textBox2);
            this.groupBox6.Controls.Add(this.label2);
            this.groupBox6.Controls.Add(this.label3);
            this.groupBox6.Controls.Add(this.label4);
            this.groupBox6.Controls.Add(this.textBox7);
            this.groupBox6.Location = new System.Drawing.Point(1, 192);
            this.groupBox6.Name = "groupBox6";
            this.groupBox6.Size = new System.Drawing.Size(492, 175);
            this.groupBox6.TabIndex = 15;
            this.groupBox6.TabStop = false;
            this.groupBox6.Text = "线圈信息";
            this.groupBox6.UseWaitCursor = true;
            // 
            // textBox1
            // 
            this.textBox1.Location = new System.Drawing.Point(130, 126);
            this.textBox1.Name = "textBox1";
            this.textBox1.Size = new System.Drawing.Size(157, 28);
            this.textBox1.TabIndex = 14;
            this.textBox1.UseWaitCursor = true;
            // 
            // textBox2
            // 
            this.textBox2.Location = new System.Drawing.Point(130, 76);
            this.textBox2.Name = "textBox2";
            this.textBox2.Size = new System.Drawing.Size(157, 28);
            this.textBox2.TabIndex = 13;
            this.textBox2.UseWaitCursor = true;
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(27, 129);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(98, 18);
            this.label2.TabIndex = 12;
            this.label2.Text = "通道数量：";
            this.label2.UseWaitCursor = true;
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(27, 34);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(98, 18);
            this.label3.TabIndex = 11;
            this.label3.Text = "线圈厂家：";
            this.label3.UseWaitCursor = true;
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(27, 79);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(98, 18);
            this.label4.TabIndex = 10;
            this.label4.Text = "线圈名称：";
            this.label4.UseWaitCursor = true;
            // 
            // textBox7
            // 
            this.textBox7.Location = new System.Drawing.Point(130, 27);
            this.textBox7.Name = "textBox7";
            this.textBox7.Size = new System.Drawing.Size(157, 28);
            this.textBox7.TabIndex = 1;
            this.textBox7.UseWaitCursor = true;
            // 
            // checkBoxCh1_4
            // 
            this.checkBoxCh1_4.AutoSize = true;
            this.checkBoxCh1_4.Location = new System.Drawing.Point(64, 533);
            this.checkBoxCh1_4.Name = "checkBoxCh1_4";
            this.checkBoxCh1_4.Size = new System.Drawing.Size(97, 22);
            this.checkBoxCh1_4.TabIndex = 17;
            this.checkBoxCh1_4.Text = "通道1-4";
            this.checkBoxCh1_4.UseVisualStyleBackColor = true;
            this.checkBoxCh1_4.UseWaitCursor = true;
            // 
            // checkBoxCh5_8
            // 
            this.checkBoxCh5_8.AutoSize = true;
            this.checkBoxCh5_8.Location = new System.Drawing.Point(160, 533);
            this.checkBoxCh5_8.Name = "checkBoxCh5_8";
            this.checkBoxCh5_8.Size = new System.Drawing.Size(97, 22);
            this.checkBoxCh5_8.TabIndex = 18;
            this.checkBoxCh5_8.Text = "通道5-8";
            this.checkBoxCh5_8.UseVisualStyleBackColor = true;
            this.checkBoxCh5_8.UseWaitCursor = true;
            // 
            // checkBoxCh9_12
            // 
            this.checkBoxCh9_12.AutoSize = true;
            this.checkBoxCh9_12.Location = new System.Drawing.Point(259, 533);
            this.checkBoxCh9_12.Name = "checkBoxCh9_12";
            this.checkBoxCh9_12.Size = new System.Drawing.Size(106, 22);
            this.checkBoxCh9_12.TabIndex = 19;
            this.checkBoxCh9_12.Text = "通道9-12";
            this.checkBoxCh9_12.UseVisualStyleBackColor = true;
            this.checkBoxCh9_12.UseWaitCursor = true;
            // 
            // checkBoxCh13_16
            // 
            this.checkBoxCh13_16.AutoSize = true;
            this.checkBoxCh13_16.Location = new System.Drawing.Point(363, 533);
            this.checkBoxCh13_16.Name = "checkBoxCh13_16";
            this.checkBoxCh13_16.Size = new System.Drawing.Size(115, 22);
            this.checkBoxCh13_16.TabIndex = 20;
            this.checkBoxCh13_16.Text = "通道13-16";
            this.checkBoxCh13_16.UseVisualStyleBackColor = true;
            this.checkBoxCh13_16.UseWaitCursor = true;
            // 
            // buttonApply
            // 
            this.buttonApply.Location = new System.Drawing.Point(429, 28);
            this.buttonApply.Name = "buttonApply";
            this.buttonApply.Size = new System.Drawing.Size(62, 38);
            this.buttonApply.TabIndex = 21;
            this.buttonApply.Text = "应用";
            this.buttonApply.UseVisualStyleBackColor = true;
            this.buttonApply.UseWaitCursor = true;
            this.buttonApply.Click += new System.EventHandler(this.buttonApply_Click);
            // 
            // groupBox7
            // 
            this.groupBox7.Controls.Add(this.buttonApply);
            this.groupBox7.Location = new System.Drawing.Point(50, 495);
            this.groupBox7.Name = "groupBox7";
            this.groupBox7.Size = new System.Drawing.Size(496, 91);
            this.groupBox7.TabIndex = 22;
            this.groupBox7.TabStop = false;
            this.groupBox7.Text = "接收线圈失谐";
            this.groupBox7.UseWaitCursor = true;
            // 
            // SerialportSampleForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(9F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.BackColor = System.Drawing.SystemColors.Window;
            this.ClientSize = new System.Drawing.Size(623, 644);
            this.Controls.Add(this.checkBoxCh13_16);
            this.Controls.Add(this.checkBoxCh9_12);
            this.Controls.Add(this.checkBoxCh5_8);
            this.Controls.Add(this.checkBoxCh1_4);
            this.Controls.Add(this.groupBox7);
            this.Controls.Add(this.groupBox4);
            this.Controls.Add(this.groupBox2);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.groupBox5);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.Fixed3D;
            this.HelpButton = true;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "SerialportSampleForm";
            this.Text = "线圈助手";
            this.UseWaitCursor = true;
            this.Load += new System.EventHandler(this.SerialportSampleForm_Load_1);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.groupBox3.ResumeLayout(false);
            this.groupBox3.PerformLayout();
            this.groupBox2.ResumeLayout(false);
            this.groupBox2.PerformLayout();
            this.groupBox4.ResumeLayout(false);
            this.groupBox5.ResumeLayout(false);
            this.groupBox5.PerformLayout();
            this.groupBox6.ResumeLayout(false);
            this.groupBox6.PerformLayout();
            this.groupBox7.ResumeLayout(false);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.ComboBox comboPortName;
        private System.Windows.Forms.Button buttonOpenClose;
        private System.Windows.Forms.Button buttonRxReceive;
        private System.Windows.Forms.Button buttonTxReceive;
        private System.Windows.Forms.GroupBox groupBox1;
        private System.Windows.Forms.TextBox textBoxReceive;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.GroupBox groupBox2;
        private System.Windows.Forms.GroupBox groupBox3;
        private System.Windows.Forms.TextBox textBox4;
        private System.Windows.Forms.TextBox textBox5;
        private System.Windows.Forms.Label label5;
        private System.Windows.Forms.Label label6;
        private System.Windows.Forms.Label label7;
        private System.Windows.Forms.TextBox textBox6;
        private System.Windows.Forms.GroupBox groupBox4;
        private System.Windows.Forms.Button buttonAcqCoilInfo;
        private System.Windows.Forms.GroupBox groupBox5;
        private System.Windows.Forms.GroupBox groupBox6;
        private System.Windows.Forms.TextBox textBox1;
        private System.Windows.Forms.TextBox textBox2;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox textBox7;
        private System.Windows.Forms.Button button2;
        private System.Windows.Forms.Button button1;
        private System.Windows.Forms.Button button3;
        private System.Windows.Forms.Button cleanScreen;
        private System.Windows.Forms.CheckBox checkBoxCh1_4;
        private System.Windows.Forms.CheckBox checkBoxCh5_8;
        private System.Windows.Forms.CheckBox checkBoxCh9_12;
        private System.Windows.Forms.CheckBox checkBoxCh13_16;
        private System.Windows.Forms.Button buttonApply;
        private System.Windows.Forms.GroupBox groupBox7;
    }
}

