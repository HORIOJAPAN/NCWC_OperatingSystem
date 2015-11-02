namespace csPCIform
{
    partial class MappingForm
    {
        /// <summary>
        /// 必要なデザイナー変数です。
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// 使用中のリソースをすべてクリーンアップします。
        /// </summary>
        /// <param name="disposing">マネージ リソースが破棄される場合 true、破棄されない場合は false です。</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows フォーム デザイナーで生成されたコード

        /// <summary>
        /// デザイナー サポートに必要なメソッドです。このメソッドの内容を
        /// コード エディターで変更しないでください。
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MappingForm));
            this.startBtn = new System.Windows.Forms.Button();
            this.dirListBox = new System.Windows.Forms.ListBox();
            this.imgWidthTxtbox = new System.Windows.Forms.TextBox();
            this.imgHeightTxtbox = new System.Windows.Forms.TextBox();
            this.imgWidthLbl = new System.Windows.Forms.Label();
            this.imgHeightLbl = new System.Windows.Forms.Label();
            this.imgResolutionLbl = new System.Windows.Forms.Label();
            this.imgResolutionTxtbox = new System.Windows.Forms.TextBox();
            this.urgLcomCbbox = new System.Windows.Forms.ComboBox();
            this.urg1Lbl = new System.Windows.Forms.Label();
            this.urg2Lbl = new System.Windows.Forms.Label();
            this.urgRcomCbbox = new System.Windows.Forms.ComboBox();
            this.arduinocomLbl = new System.Windows.Forms.Label();
            this.arduinocomCbbox = new System.Windows.Forms.ComboBox();
            this.urgLheightTxtbox = new System.Windows.Forms.TextBox();
            this.urg1heightLbl = new System.Windows.Forms.Label();
            this.urg1distanceLbl = new System.Windows.Forms.Label();
            this.urgLXdistTxtbox = new System.Windows.Forms.TextBox();
            this.urgRXdistTxtbox = new System.Windows.Forms.TextBox();
            this.urgRheightTxtbox = new System.Windows.Forms.TextBox();
            this.urg2heightLbl = new System.Windows.Forms.Label();
            this.urg2distanceLbl = new System.Windows.Forms.Label();
            this.reloadBtn = new System.Windows.Forms.Button();
            this.replaceBtn = new System.Windows.Forms.Button();
            this.alldirCheckbox = new System.Windows.Forms.CheckBox();
            this.devmngerBtn = new System.Windows.Forms.Button();
            this.savedirpathTxtbox = new System.Windows.Forms.TextBox();
            this.savadirpathBtn = new System.Windows.Forms.Button();
            this.savedirpathDlog = new System.Windows.Forms.FolderBrowserDialog();
            this.intervalLbl = new System.Windows.Forms.Label();
            this.intervalTxtbox = new System.Windows.Forms.TextBox();
            this.label1 = new System.Windows.Forms.Label();
            this.urgRYdistTxtbox = new System.Windows.Forms.TextBox();
            this.label2 = new System.Windows.Forms.Label();
            this.urgLYdistTxtbox = new System.Windows.Forms.TextBox();
            this.label3 = new System.Windows.Forms.Label();
            this.urgRdegTxtbox = new System.Windows.Forms.TextBox();
            this.label4 = new System.Windows.Forms.Label();
            this.urgLdegTxtbox = new System.Windows.Forms.TextBox();
            this.SuspendLayout();
            // 
            // startBtn
            // 
            this.startBtn.Location = new System.Drawing.Point(331, 583);
            this.startBtn.Name = "startBtn";
            this.startBtn.Size = new System.Drawing.Size(190, 60);
            this.startBtn.TabIndex = 0;
            this.startBtn.Text = "Start";
            this.startBtn.UseVisualStyleBackColor = true;
            this.startBtn.Click += new System.EventHandler(this.startBtn_Click);
            // 
            // dirListBox
            // 
            this.dirListBox.FormattingEnabled = true;
            this.dirListBox.ItemHeight = 18;
            this.dirListBox.Location = new System.Drawing.Point(573, 81);
            this.dirListBox.Name = "dirListBox";
            this.dirListBox.Size = new System.Drawing.Size(382, 562);
            this.dirListBox.TabIndex = 2;
            this.dirListBox.SelectedIndexChanged += new System.EventHandler(this.dirListBox_SelectedIndexChanged);
            // 
            // imgWidthTxtbox
            // 
            this.imgWidthTxtbox.Location = new System.Drawing.Point(39, 527);
            this.imgWidthTxtbox.Name = "imgWidthTxtbox";
            this.imgWidthTxtbox.Size = new System.Drawing.Size(101, 25);
            this.imgWidthTxtbox.TabIndex = 3;
            this.imgWidthTxtbox.Text = "1000";
            // 
            // imgHeightTxtbox
            // 
            this.imgHeightTxtbox.Location = new System.Drawing.Point(171, 527);
            this.imgHeightTxtbox.Name = "imgHeightTxtbox";
            this.imgHeightTxtbox.Size = new System.Drawing.Size(101, 25);
            this.imgHeightTxtbox.TabIndex = 4;
            this.imgHeightTxtbox.Text = "1000";
            // 
            // imgWidthLbl
            // 
            this.imgWidthLbl.AutoSize = true;
            this.imgWidthLbl.Location = new System.Drawing.Point(36, 493);
            this.imgWidthLbl.Name = "imgWidthLbl";
            this.imgWidthLbl.Size = new System.Drawing.Size(92, 18);
            this.imgWidthLbl.TabIndex = 5;
            this.imgWidthLbl.Text = "ImageWidth";
            // 
            // imgHeightLbl
            // 
            this.imgHeightLbl.AutoSize = true;
            this.imgHeightLbl.Location = new System.Drawing.Point(167, 493);
            this.imgHeightLbl.Name = "imgHeightLbl";
            this.imgHeightLbl.Size = new System.Drawing.Size(99, 18);
            this.imgHeightLbl.TabIndex = 6;
            this.imgHeightLbl.Text = "ImageHeight";
            // 
            // imgResolutionLbl
            // 
            this.imgResolutionLbl.AutoSize = true;
            this.imgResolutionLbl.Location = new System.Drawing.Point(36, 569);
            this.imgResolutionLbl.Name = "imgResolutionLbl";
            this.imgResolutionLbl.Size = new System.Drawing.Size(129, 18);
            this.imgResolutionLbl.TabIndex = 8;
            this.imgResolutionLbl.Text = "ImageResolution";
            // 
            // imgResolutionTxtbox
            // 
            this.imgResolutionTxtbox.Location = new System.Drawing.Point(39, 601);
            this.imgResolutionTxtbox.Name = "imgResolutionTxtbox";
            this.imgResolutionTxtbox.Size = new System.Drawing.Size(101, 25);
            this.imgResolutionTxtbox.TabIndex = 7;
            this.imgResolutionTxtbox.Text = "5";
            // 
            // urgLcomCbbox
            // 
            this.urgLcomCbbox.FormattingEnabled = true;
            this.urgLcomCbbox.Location = new System.Drawing.Point(39, 92);
            this.urgLcomCbbox.Name = "urgLcomCbbox";
            this.urgLcomCbbox.Size = new System.Drawing.Size(121, 26);
            this.urgLcomCbbox.TabIndex = 9;
            // 
            // urg1Lbl
            // 
            this.urg1Lbl.AutoSize = true;
            this.urg1Lbl.Location = new System.Drawing.Point(36, 71);
            this.urg1Lbl.Name = "urg1Lbl";
            this.urg1Lbl.Size = new System.Drawing.Size(96, 18);
            this.urg1Lbl.TabIndex = 10;
            this.urg1Lbl.Text = "URG <Left>";
            // 
            // urg2Lbl
            // 
            this.urg2Lbl.AutoSize = true;
            this.urg2Lbl.Location = new System.Drawing.Point(222, 71);
            this.urg2Lbl.Name = "urg2Lbl";
            this.urg2Lbl.Size = new System.Drawing.Size(104, 18);
            this.urg2Lbl.TabIndex = 12;
            this.urg2Lbl.Text = "URG <Right>";
            // 
            // urgRcomCbbox
            // 
            this.urgRcomCbbox.FormattingEnabled = true;
            this.urgRcomCbbox.Location = new System.Drawing.Point(226, 92);
            this.urgRcomCbbox.Name = "urgRcomCbbox";
            this.urgRcomCbbox.Size = new System.Drawing.Size(121, 26);
            this.urgRcomCbbox.TabIndex = 11;
            // 
            // arduinocomLbl
            // 
            this.arduinocomLbl.AutoSize = true;
            this.arduinocomLbl.Location = new System.Drawing.Point(396, 71);
            this.arduinocomLbl.Name = "arduinocomLbl";
            this.arduinocomLbl.Size = new System.Drawing.Size(149, 18);
            this.arduinocomLbl.TabIndex = 14;
            this.arduinocomLbl.Text = "Arduino <Encoder>";
            // 
            // arduinocomCbbox
            // 
            this.arduinocomCbbox.FormattingEnabled = true;
            this.arduinocomCbbox.Location = new System.Drawing.Point(399, 92);
            this.arduinocomCbbox.Name = "arduinocomCbbox";
            this.arduinocomCbbox.Size = new System.Drawing.Size(121, 26);
            this.arduinocomCbbox.TabIndex = 13;
            // 
            // urgLheightTxtbox
            // 
            this.urgLheightTxtbox.Location = new System.Drawing.Point(39, 161);
            this.urgLheightTxtbox.Name = "urgLheightTxtbox";
            this.urgLheightTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgLheightTxtbox.TabIndex = 15;
            this.urgLheightTxtbox.Text = "20.0";
            // 
            // urg1heightLbl
            // 
            this.urg1heightLbl.AutoSize = true;
            this.urg1heightLbl.Location = new System.Drawing.Point(36, 139);
            this.urg1heightLbl.Name = "urg1heightLbl";
            this.urg1heightLbl.Size = new System.Drawing.Size(154, 18);
            this.urg1heightLbl.TabIndex = 16;
            this.urg1heightLbl.Text = "地面からの高さ[mm]";
            // 
            // urg1distanceLbl
            // 
            this.urg1distanceLbl.AutoSize = true;
            this.urg1distanceLbl.Location = new System.Drawing.Point(36, 197);
            this.urg1distanceLbl.Name = "urg1distanceLbl";
            this.urg1distanceLbl.Size = new System.Drawing.Size(126, 18);
            this.urg1distanceLbl.TabIndex = 18;
            this.urg1distanceLbl.Text = "x方向距離[mm]";
            // 
            // urgLXdistTxtbox
            // 
            this.urgLXdistTxtbox.Location = new System.Drawing.Point(39, 217);
            this.urgLXdistTxtbox.Name = "urgLXdistTxtbox";
            this.urgLXdistTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgLXdistTxtbox.TabIndex = 17;
            this.urgLXdistTxtbox.Text = "350";
            // 
            // urgRXdistTxtbox
            // 
            this.urgRXdistTxtbox.Location = new System.Drawing.Point(226, 217);
            this.urgRXdistTxtbox.Name = "urgRXdistTxtbox";
            this.urgRXdistTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgRXdistTxtbox.TabIndex = 21;
            this.urgRXdistTxtbox.Text = "350.0";
            // 
            // urgRheightTxtbox
            // 
            this.urgRheightTxtbox.Location = new System.Drawing.Point(226, 161);
            this.urgRheightTxtbox.Name = "urgRheightTxtbox";
            this.urgRheightTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgRheightTxtbox.TabIndex = 19;
            this.urgRheightTxtbox.Text = "20.0";
            // 
            // urg2heightLbl
            // 
            this.urg2heightLbl.AutoSize = true;
            this.urg2heightLbl.Location = new System.Drawing.Point(224, 139);
            this.urg2heightLbl.Name = "urg2heightLbl";
            this.urg2heightLbl.Size = new System.Drawing.Size(154, 18);
            this.urg2heightLbl.TabIndex = 22;
            this.urg2heightLbl.Text = "地面からの高さ[mm]";
            // 
            // urg2distanceLbl
            // 
            this.urg2distanceLbl.AutoSize = true;
            this.urg2distanceLbl.Location = new System.Drawing.Point(222, 197);
            this.urg2distanceLbl.Name = "urg2distanceLbl";
            this.urg2distanceLbl.Size = new System.Drawing.Size(126, 18);
            this.urg2distanceLbl.TabIndex = 23;
            this.urg2distanceLbl.Text = "x方向距離[mm]";
            // 
            // reloadBtn
            // 
            this.reloadBtn.Location = new System.Drawing.Point(408, 148);
            this.reloadBtn.Name = "reloadBtn";
            this.reloadBtn.Size = new System.Drawing.Size(112, 40);
            this.reloadBtn.TabIndex = 24;
            this.reloadBtn.Text = "Reload";
            this.reloadBtn.UseVisualStyleBackColor = true;
            this.reloadBtn.Click += new System.EventHandler(this.reloadBtn_Click);
            // 
            // replaceBtn
            // 
            this.replaceBtn.Location = new System.Drawing.Point(137, 361);
            this.replaceBtn.Name = "replaceBtn";
            this.replaceBtn.Size = new System.Drawing.Size(93, 33);
            this.replaceBtn.TabIndex = 25;
            this.replaceBtn.Text = "<=>";
            this.replaceBtn.UseVisualStyleBackColor = true;
            this.replaceBtn.Click += new System.EventHandler(this.replaceBtn_Click);
            // 
            // alldirCheckbox
            // 
            this.alldirCheckbox.AutoSize = true;
            this.alldirCheckbox.Location = new System.Drawing.Point(807, 50);
            this.alldirCheckbox.Name = "alldirCheckbox";
            this.alldirCheckbox.Size = new System.Drawing.Size(137, 22);
            this.alldirCheckbox.TabIndex = 26;
            this.alldirCheckbox.Text = "All directories";
            this.alldirCheckbox.UseVisualStyleBackColor = true;
            this.alldirCheckbox.CheckedChanged += new System.EventHandler(this.alldirCheckbox_CheckedChanged);
            // 
            // devmngerBtn
            // 
            this.devmngerBtn.Location = new System.Drawing.Point(12, 12);
            this.devmngerBtn.Name = "devmngerBtn";
            this.devmngerBtn.Size = new System.Drawing.Size(157, 34);
            this.devmngerBtn.TabIndex = 27;
            this.devmngerBtn.Text = "DeviceManager";
            this.devmngerBtn.UseVisualStyleBackColor = true;
            this.devmngerBtn.Click += new System.EventHandler(this.devmngerBtn_Click);
            // 
            // savedirpathTxtbox
            // 
            this.savedirpathTxtbox.BackColor = System.Drawing.SystemColors.Control;
            this.savedirpathTxtbox.Location = new System.Drawing.Point(573, 16);
            this.savedirpathTxtbox.Multiline = true;
            this.savedirpathTxtbox.Name = "savedirpathTxtbox";
            this.savedirpathTxtbox.Size = new System.Drawing.Size(332, 26);
            this.savedirpathTxtbox.TabIndex = 28;
            // 
            // savadirpathBtn
            // 
            this.savadirpathBtn.Location = new System.Drawing.Point(913, 15);
            this.savadirpathBtn.Name = "savadirpathBtn";
            this.savadirpathBtn.Size = new System.Drawing.Size(32, 28);
            this.savadirpathBtn.TabIndex = 29;
            this.savadirpathBtn.Text = "...";
            this.savadirpathBtn.UseVisualStyleBackColor = true;
            this.savadirpathBtn.Click += new System.EventHandler(this.savadirpathBtn_Click);
            // 
            // intervalLbl
            // 
            this.intervalLbl.AutoSize = true;
            this.intervalLbl.Location = new System.Drawing.Point(36, 417);
            this.intervalLbl.Name = "intervalLbl";
            this.intervalLbl.Size = new System.Drawing.Size(131, 18);
            this.intervalLbl.TabIndex = 31;
            this.intervalLbl.Text = "Interval[millisec]";
            // 
            // intervalTxtbox
            // 
            this.intervalTxtbox.Location = new System.Drawing.Point(39, 448);
            this.intervalTxtbox.Name = "intervalTxtbox";
            this.intervalTxtbox.Size = new System.Drawing.Size(101, 25);
            this.intervalTxtbox.TabIndex = 30;
            this.intervalTxtbox.Text = "200";
            this.intervalTxtbox.TextChanged += new System.EventHandler(this.intervalTxtbox_TextChanged);
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(222, 254);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(127, 18);
            this.label1.TabIndex = 35;
            this.label1.Text = "y方向距離[mm]";
            // 
            // urgRYdistTxtbox
            // 
            this.urgRYdistTxtbox.Location = new System.Drawing.Point(226, 274);
            this.urgRYdistTxtbox.Name = "urgRYdistTxtbox";
            this.urgRYdistTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgRYdistTxtbox.TabIndex = 34;
            this.urgRYdistTxtbox.Text = "-280.0";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(36, 254);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(127, 18);
            this.label2.TabIndex = 33;
            this.label2.Text = "y方向距離[mm]";
            // 
            // urgLYdistTxtbox
            // 
            this.urgLYdistTxtbox.Location = new System.Drawing.Point(39, 274);
            this.urgLYdistTxtbox.Name = "urgLYdistTxtbox";
            this.urgLYdistTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgLYdistTxtbox.TabIndex = 32;
            this.urgLYdistTxtbox.Text = "280.0";
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(223, 310);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(100, 18);
            this.label3.TabIndex = 39;
            this.label3.Text = "回転角[deg]";
            // 
            // urgRdegTxtbox
            // 
            this.urgRdegTxtbox.Location = new System.Drawing.Point(227, 330);
            this.urgRdegTxtbox.Name = "urgRdegTxtbox";
            this.urgRdegTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgRdegTxtbox.TabIndex = 38;
            this.urgRdegTxtbox.Text = "30.0";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(37, 310);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(100, 18);
            this.label4.TabIndex = 37;
            this.label4.Text = "回転角[deg]";
            // 
            // urgLdegTxtbox
            // 
            this.urgLdegTxtbox.Location = new System.Drawing.Point(40, 330);
            this.urgLdegTxtbox.Name = "urgLdegTxtbox";
            this.urgLdegTxtbox.Size = new System.Drawing.Size(101, 25);
            this.urgLdegTxtbox.TabIndex = 36;
            this.urgLdegTxtbox.Text = "-30.0";
            // 
            // MappingForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(967, 655);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.urgRdegTxtbox);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.urgLdegTxtbox);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.urgRYdistTxtbox);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.urgLYdistTxtbox);
            this.Controls.Add(this.intervalLbl);
            this.Controls.Add(this.intervalTxtbox);
            this.Controls.Add(this.savadirpathBtn);
            this.Controls.Add(this.savedirpathTxtbox);
            this.Controls.Add(this.devmngerBtn);
            this.Controls.Add(this.alldirCheckbox);
            this.Controls.Add(this.replaceBtn);
            this.Controls.Add(this.reloadBtn);
            this.Controls.Add(this.urg2distanceLbl);
            this.Controls.Add(this.urg2heightLbl);
            this.Controls.Add(this.urgRXdistTxtbox);
            this.Controls.Add(this.urgRheightTxtbox);
            this.Controls.Add(this.urg1distanceLbl);
            this.Controls.Add(this.urgLXdistTxtbox);
            this.Controls.Add(this.urg1heightLbl);
            this.Controls.Add(this.urgLheightTxtbox);
            this.Controls.Add(this.arduinocomLbl);
            this.Controls.Add(this.arduinocomCbbox);
            this.Controls.Add(this.urg2Lbl);
            this.Controls.Add(this.urgRcomCbbox);
            this.Controls.Add(this.urg1Lbl);
            this.Controls.Add(this.urgLcomCbbox);
            this.Controls.Add(this.imgResolutionLbl);
            this.Controls.Add(this.imgResolutionTxtbox);
            this.Controls.Add(this.imgHeightLbl);
            this.Controls.Add(this.imgWidthLbl);
            this.Controls.Add(this.imgHeightTxtbox);
            this.Controls.Add(this.imgWidthTxtbox);
            this.Controls.Add(this.dirListBox);
            this.Controls.Add(this.startBtn);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MappingForm";
            this.Text = "MappingForm";
            this.Load += new System.EventHandler(this.MappingForm_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button startBtn;
        private System.Windows.Forms.ListBox dirListBox;
        private System.Windows.Forms.TextBox imgWidthTxtbox;
        private System.Windows.Forms.TextBox imgHeightTxtbox;
        private System.Windows.Forms.Label imgWidthLbl;
        private System.Windows.Forms.Label imgHeightLbl;
        private System.Windows.Forms.Label imgResolutionLbl;
        private System.Windows.Forms.TextBox imgResolutionTxtbox;
        private System.Windows.Forms.ComboBox urgLcomCbbox;
        private System.Windows.Forms.Label urg1Lbl;
        private System.Windows.Forms.Label urg2Lbl;
        private System.Windows.Forms.ComboBox urgRcomCbbox;
        private System.Windows.Forms.Label arduinocomLbl;
        private System.Windows.Forms.ComboBox arduinocomCbbox;
        private System.Windows.Forms.TextBox urgLheightTxtbox;
        private System.Windows.Forms.Label urg1heightLbl;
        private System.Windows.Forms.Label urg1distanceLbl;
        private System.Windows.Forms.TextBox urgLXdistTxtbox;
        private System.Windows.Forms.TextBox urgRXdistTxtbox;
        private System.Windows.Forms.TextBox urgRheightTxtbox;
        private System.Windows.Forms.Label urg2heightLbl;
        private System.Windows.Forms.Label urg2distanceLbl;
        private System.Windows.Forms.Button reloadBtn;
        private System.Windows.Forms.Button replaceBtn;
        private System.Windows.Forms.CheckBox alldirCheckbox;
        private System.Windows.Forms.Button devmngerBtn;
        private System.Windows.Forms.TextBox savedirpathTxtbox;
        private System.Windows.Forms.Button savadirpathBtn;
        private System.Windows.Forms.FolderBrowserDialog savedirpathDlog;
        private System.Windows.Forms.Label intervalLbl;
        private System.Windows.Forms.TextBox intervalTxtbox;
        private System.Windows.Forms.Label label1;
        private System.Windows.Forms.TextBox urgRYdistTxtbox;
        private System.Windows.Forms.Label label2;
        private System.Windows.Forms.TextBox urgLYdistTxtbox;
        private System.Windows.Forms.Label label3;
        private System.Windows.Forms.TextBox urgRdegTxtbox;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.TextBox urgLdegTxtbox;
    }
}

