namespace HJ_MakeRoute
{
    partial class MakeRouteForm
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(MakeRouteForm));
            this.coord_x = new System.Windows.Forms.Label();
            this.x_val = new System.Windows.Forms.Label();
            this.y_val = new System.Windows.Forms.Label();
            this.coord_y = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.saveBtn = new System.Windows.Forms.Button();
            this.routeTxt = new System.Windows.Forms.TextBox();
            this.speed1 = new System.Windows.Forms.RadioButton();
            this.speed2 = new System.Windows.Forms.RadioButton();
            this.speedGB = new System.Windows.Forms.GroupBox();
            this.speed6 = new System.Windows.Forms.RadioButton();
            this.speed5 = new System.Windows.Forms.RadioButton();
            this.speed3 = new System.Windows.Forms.RadioButton();
            this.speed4 = new System.Windows.Forms.RadioButton();
            this.accuracyGB = new System.Windows.Forms.GroupBox();
            this.accuracy6 = new System.Windows.Forms.RadioButton();
            this.accuracy5 = new System.Windows.Forms.RadioButton();
            this.accuracy3 = new System.Windows.Forms.RadioButton();
            this.accuracy4 = new System.Windows.Forms.RadioButton();
            this.accuracy1 = new System.Windows.Forms.RadioButton();
            this.accuracy2 = new System.Windows.Forms.RadioButton();
            this.confirmBtn = new System.Windows.Forms.Button();
            this.insertBtn = new System.Windows.Forms.Button();
            this.NewBtn = new System.Windows.Forms.Button();
            this.newRouteDlog = new System.Windows.Forms.OpenFileDialog();
            this.saveRouteDlog = new System.Windows.Forms.SaveFileDialog();
            this.speedGB.SuspendLayout();
            this.accuracyGB.SuspendLayout();
            this.SuspendLayout();
            // 
            // coord_x
            // 
            this.coord_x.AutoSize = true;
            this.coord_x.Font = new System.Drawing.Font("ＭＳ ゴシック", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.coord_x.Location = new System.Drawing.Point(46, 24);
            this.coord_x.Name = "coord_x";
            this.coord_x.Size = new System.Drawing.Size(63, 33);
            this.coord_x.TabIndex = 0;
            this.coord_x.Text = "X :";
            // 
            // x_val
            // 
            this.x_val.AutoSize = true;
            this.x_val.Font = new System.Drawing.Font("ＭＳ ゴシック", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.x_val.Location = new System.Drawing.Point(115, 24);
            this.x_val.Name = "x_val";
            this.x_val.Size = new System.Drawing.Size(31, 33);
            this.x_val.TabIndex = 1;
            this.x_val.Text = "0";
            // 
            // y_val
            // 
            this.y_val.AutoSize = true;
            this.y_val.Font = new System.Drawing.Font("ＭＳ ゴシック", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.y_val.Location = new System.Drawing.Point(298, 24);
            this.y_val.Name = "y_val";
            this.y_val.Size = new System.Drawing.Size(31, 33);
            this.y_val.TabIndex = 3;
            this.y_val.Text = "0";
            // 
            // coord_y
            // 
            this.coord_y.AutoSize = true;
            this.coord_y.Font = new System.Drawing.Font("ＭＳ ゴシック", 16F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.coord_y.Location = new System.Drawing.Point(229, 24);
            this.coord_y.Name = "coord_y";
            this.coord_y.Size = new System.Drawing.Size(63, 33);
            this.coord_y.TabIndex = 2;
            this.coord_y.Text = "Y :";
            // 
            // label4
            // 
            this.label4.BackColor = System.Drawing.SystemColors.ButtonFace;
            this.label4.BorderStyle = System.Windows.Forms.BorderStyle.FixedSingle;
            this.label4.Location = new System.Drawing.Point(19, 12);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(389, 58);
            this.label4.TabIndex = 4;
            // 
            // saveBtn
            // 
            this.saveBtn.Location = new System.Drawing.Point(485, 589);
            this.saveBtn.Name = "saveBtn";
            this.saveBtn.Size = new System.Drawing.Size(108, 43);
            this.saveBtn.TabIndex = 11;
            this.saveBtn.Text = "Save";
            this.saveBtn.UseVisualStyleBackColor = true;
            this.saveBtn.Click += new System.EventHandler(this.saveBtn_Click);
            // 
            // routeTxt
            // 
            this.routeTxt.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.routeTxt.BackColor = System.Drawing.SystemColors.InfoText;
            this.routeTxt.Font = new System.Drawing.Font("MS UI Gothic", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.routeTxt.ForeColor = System.Drawing.Color.Lime;
            this.routeTxt.Location = new System.Drawing.Point(599, 40);
            this.routeTxt.Multiline = true;
            this.routeTxt.Name = "routeTxt";
            this.routeTxt.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.routeTxt.Size = new System.Drawing.Size(405, 592);
            this.routeTxt.TabIndex = 12;
            this.routeTxt.Text = "X, Y, S, A, etc,\r\n";
            // 
            // speed1
            // 
            this.speed1.AutoSize = true;
            this.speed1.Checked = true;
            this.speed1.Location = new System.Drawing.Point(27, 45);
            this.speed1.Name = "speed1";
            this.speed1.Size = new System.Drawing.Size(133, 30);
            this.speed1.TabIndex = 13;
            this.speed1.TabStop = true;
            this.speed1.Tag = "1";
            this.speed1.Text = "2.5 km/h";
            this.speed1.UseVisualStyleBackColor = true;
            this.speed1.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // speed2
            // 
            this.speed2.AutoSize = true;
            this.speed2.Location = new System.Drawing.Point(27, 81);
            this.speed2.Name = "speed2";
            this.speed2.Size = new System.Drawing.Size(133, 30);
            this.speed2.TabIndex = 14;
            this.speed2.TabStop = true;
            this.speed2.Tag = "2";
            this.speed2.Text = "2.0 km/h";
            this.speed2.UseVisualStyleBackColor = true;
            this.speed2.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // speedGB
            // 
            this.speedGB.Controls.Add(this.speed6);
            this.speedGB.Controls.Add(this.speed5);
            this.speedGB.Controls.Add(this.speed3);
            this.speedGB.Controls.Add(this.speed4);
            this.speedGB.Controls.Add(this.speed1);
            this.speedGB.Controls.Add(this.speed2);
            this.speedGB.Font = new System.Drawing.Font("MS UI Gothic", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.speedGB.Location = new System.Drawing.Point(19, 108);
            this.speedGB.Name = "speedGB";
            this.speedGB.Size = new System.Drawing.Size(215, 270);
            this.speedGB.TabIndex = 15;
            this.speedGB.TabStop = false;
            this.speedGB.Text = "Speed";
            // 
            // speed6
            // 
            this.speed6.AutoSize = true;
            this.speed6.Location = new System.Drawing.Point(27, 225);
            this.speed6.Name = "speed6";
            this.speed6.Size = new System.Drawing.Size(133, 30);
            this.speed6.TabIndex = 18;
            this.speed6.TabStop = true;
            this.speed6.Tag = "6";
            this.speed6.Text = "0.0 km/h";
            this.speed6.UseVisualStyleBackColor = true;
            this.speed6.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // speed5
            // 
            this.speed5.AutoSize = true;
            this.speed5.Location = new System.Drawing.Point(27, 189);
            this.speed5.Name = "speed5";
            this.speed5.Size = new System.Drawing.Size(133, 30);
            this.speed5.TabIndex = 17;
            this.speed5.TabStop = true;
            this.speed5.Tag = "5";
            this.speed5.Text = "0.5 km/h";
            this.speed5.UseVisualStyleBackColor = true;
            this.speed5.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // speed3
            // 
            this.speed3.AutoSize = true;
            this.speed3.Location = new System.Drawing.Point(27, 117);
            this.speed3.Name = "speed3";
            this.speed3.Size = new System.Drawing.Size(133, 30);
            this.speed3.TabIndex = 15;
            this.speed3.TabStop = true;
            this.speed3.Tag = "3";
            this.speed3.Text = "1.5 km/h";
            this.speed3.UseVisualStyleBackColor = true;
            this.speed3.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // speed4
            // 
            this.speed4.AutoSize = true;
            this.speed4.Location = new System.Drawing.Point(27, 153);
            this.speed4.Name = "speed4";
            this.speed4.Size = new System.Drawing.Size(133, 30);
            this.speed4.TabIndex = 16;
            this.speed4.TabStop = true;
            this.speed4.Tag = "4";
            this.speed4.Text = "1.0 km/h";
            this.speed4.UseVisualStyleBackColor = true;
            this.speed4.CheckedChanged += new System.EventHandler(this.speedRB_CheckedChanged);
            // 
            // accuracyGB
            // 
            this.accuracyGB.Controls.Add(this.accuracy6);
            this.accuracyGB.Controls.Add(this.accuracy5);
            this.accuracyGB.Controls.Add(this.accuracy3);
            this.accuracyGB.Controls.Add(this.accuracy4);
            this.accuracyGB.Controls.Add(this.accuracy1);
            this.accuracyGB.Controls.Add(this.accuracy2);
            this.accuracyGB.Font = new System.Drawing.Font("MS UI Gothic", 13F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.accuracyGB.Location = new System.Drawing.Point(286, 108);
            this.accuracyGB.Name = "accuracyGB";
            this.accuracyGB.Size = new System.Drawing.Size(215, 270);
            this.accuracyGB.TabIndex = 18;
            this.accuracyGB.TabStop = false;
            this.accuracyGB.Text = "Accuracy";
            // 
            // accuracy6
            // 
            this.accuracy6.AutoSize = true;
            this.accuracy6.Location = new System.Drawing.Point(27, 225);
            this.accuracy6.Name = "accuracy6";
            this.accuracy6.Size = new System.Drawing.Size(122, 30);
            this.accuracy6.TabIndex = 18;
            this.accuracy6.TabStop = true;
            this.accuracy6.Tag = "6";
            this.accuracy6.Text = "100 mm";
            this.accuracy6.UseVisualStyleBackColor = true;
            this.accuracy6.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // accuracy5
            // 
            this.accuracy5.AutoSize = true;
            this.accuracy5.Location = new System.Drawing.Point(27, 189);
            this.accuracy5.Name = "accuracy5";
            this.accuracy5.Size = new System.Drawing.Size(122, 30);
            this.accuracy5.TabIndex = 17;
            this.accuracy5.TabStop = true;
            this.accuracy5.Tag = "5";
            this.accuracy5.Text = "200 mm";
            this.accuracy5.UseVisualStyleBackColor = true;
            this.accuracy5.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // accuracy3
            // 
            this.accuracy3.AutoSize = true;
            this.accuracy3.Location = new System.Drawing.Point(27, 117);
            this.accuracy3.Name = "accuracy3";
            this.accuracy3.Size = new System.Drawing.Size(122, 30);
            this.accuracy3.TabIndex = 15;
            this.accuracy3.TabStop = true;
            this.accuracy3.Tag = "3";
            this.accuracy3.Text = "600 mm";
            this.accuracy3.UseVisualStyleBackColor = true;
            this.accuracy3.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // accuracy4
            // 
            this.accuracy4.AutoSize = true;
            this.accuracy4.Location = new System.Drawing.Point(27, 153);
            this.accuracy4.Name = "accuracy4";
            this.accuracy4.Size = new System.Drawing.Size(122, 30);
            this.accuracy4.TabIndex = 16;
            this.accuracy4.TabStop = true;
            this.accuracy4.Tag = "4";
            this.accuracy4.Text = "400 mm";
            this.accuracy4.UseVisualStyleBackColor = true;
            this.accuracy4.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // accuracy1
            // 
            this.accuracy1.AutoSize = true;
            this.accuracy1.Checked = true;
            this.accuracy1.Location = new System.Drawing.Point(27, 45);
            this.accuracy1.Name = "accuracy1";
            this.accuracy1.Size = new System.Drawing.Size(135, 30);
            this.accuracy1.TabIndex = 13;
            this.accuracy1.TabStop = true;
            this.accuracy1.Tag = "1";
            this.accuracy1.Text = "1000 mm";
            this.accuracy1.UseVisualStyleBackColor = true;
            this.accuracy1.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // accuracy2
            // 
            this.accuracy2.AutoSize = true;
            this.accuracy2.Location = new System.Drawing.Point(27, 81);
            this.accuracy2.Name = "accuracy2";
            this.accuracy2.Size = new System.Drawing.Size(122, 30);
            this.accuracy2.TabIndex = 14;
            this.accuracy2.TabStop = true;
            this.accuracy2.Tag = "2";
            this.accuracy2.Text = "800 mm";
            this.accuracy2.UseVisualStyleBackColor = true;
            this.accuracy2.CheckedChanged += new System.EventHandler(this.accuracyRB_CheckedChanged);
            // 
            // confirmBtn
            // 
            this.confirmBtn.Location = new System.Drawing.Point(235, 589);
            this.confirmBtn.Name = "confirmBtn";
            this.confirmBtn.Size = new System.Drawing.Size(108, 43);
            this.confirmBtn.TabIndex = 20;
            this.confirmBtn.Text = "Confirm";
            this.confirmBtn.UseVisualStyleBackColor = true;
            this.confirmBtn.Click += new System.EventHandler(this.confirmBtn_Click);
            // 
            // insertBtn
            // 
            this.insertBtn.Location = new System.Drawing.Point(355, 589);
            this.insertBtn.Name = "insertBtn";
            this.insertBtn.Size = new System.Drawing.Size(108, 43);
            this.insertBtn.TabIndex = 21;
            this.insertBtn.Text = "Insert";
            this.insertBtn.UseVisualStyleBackColor = true;
            this.insertBtn.Click += new System.EventHandler(this.insertBtn_Click);
            // 
            // NewBtn
            // 
            this.NewBtn.Location = new System.Drawing.Point(19, 589);
            this.NewBtn.Name = "NewBtn";
            this.NewBtn.Size = new System.Drawing.Size(108, 43);
            this.NewBtn.TabIndex = 22;
            this.NewBtn.Text = "New";
            this.NewBtn.UseVisualStyleBackColor = true;
            this.NewBtn.Click += new System.EventHandler(this.NewBtn_Click);
            // 
            // newRouteDlog
            // 
            this.newRouteDlog.FileOk += new System.ComponentModel.CancelEventHandler(this.newRouteDlog_FileOk);
            // 
            // saveRouteDlog
            // 
            this.saveRouteDlog.FileOk += new System.ComponentModel.CancelEventHandler(this.saveRouteDlog_FileOk);
            // 
            // MakeRouteForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1016, 644);
            this.Controls.Add(this.NewBtn);
            this.Controls.Add(this.insertBtn);
            this.Controls.Add(this.confirmBtn);
            this.Controls.Add(this.accuracyGB);
            this.Controls.Add(this.speedGB);
            this.Controls.Add(this.routeTxt);
            this.Controls.Add(this.saveBtn);
            this.Controls.Add(this.y_val);
            this.Controls.Add(this.coord_y);
            this.Controls.Add(this.x_val);
            this.Controls.Add(this.coord_x);
            this.Controls.Add(this.label4);
            this.FormBorderStyle = System.Windows.Forms.FormBorderStyle.FixedSingle;
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "MakeRouteForm";
            this.Text = "MakeRouteForm";
            this.Activated += new System.EventHandler(this.MakeRouteForm_Activated);
            this.speedGB.ResumeLayout(false);
            this.speedGB.PerformLayout();
            this.accuracyGB.ResumeLayout(false);
            this.accuracyGB.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Label coord_x;
        private System.Windows.Forms.Label x_val;
        private System.Windows.Forms.Label y_val;
        private System.Windows.Forms.Label coord_y;
        private System.Windows.Forms.Label label4;
        private System.Windows.Forms.Button saveBtn;
        private System.Windows.Forms.TextBox routeTxt;
        private System.Windows.Forms.RadioButton speed1;
        private System.Windows.Forms.RadioButton speed2;
        private System.Windows.Forms.GroupBox speedGB;
        private System.Windows.Forms.RadioButton speed5;
        private System.Windows.Forms.RadioButton speed3;
        private System.Windows.Forms.RadioButton speed4;
        private System.Windows.Forms.GroupBox accuracyGB;
        private System.Windows.Forms.RadioButton accuracy6;
        private System.Windows.Forms.RadioButton accuracy5;
        private System.Windows.Forms.RadioButton accuracy3;
        private System.Windows.Forms.RadioButton accuracy4;
        private System.Windows.Forms.RadioButton accuracy1;
        private System.Windows.Forms.RadioButton accuracy2;
        private System.Windows.Forms.Button confirmBtn;
        private System.Windows.Forms.RadioButton speed6;
        private System.Windows.Forms.Button insertBtn;
        private System.Windows.Forms.Button NewBtn;
        private System.Windows.Forms.OpenFileDialog newRouteDlog;
        private System.Windows.Forms.SaveFileDialog saveRouteDlog;
    }
}

