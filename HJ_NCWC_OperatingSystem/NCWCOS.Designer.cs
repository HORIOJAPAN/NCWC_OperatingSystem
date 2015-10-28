namespace HJ_NCWC_OperatingSystem
{
    partial class NCWCOSform
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
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(NCWCOSform));
            this.btnMapping = new System.Windows.Forms.Button();
            this.btnRoute = new System.Windows.Forms.Button();
            this.btnDrive = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btnMapping
            // 
            this.btnMapping.Font = new System.Drawing.Font("MS UI Gothic", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnMapping.Location = new System.Drawing.Point(12, 12);
            this.btnMapping.Name = "btnMapping";
            this.btnMapping.Size = new System.Drawing.Size(408, 99);
            this.btnMapping.TabIndex = 0;
            this.btnMapping.Text = "マップ作製";
            this.btnMapping.UseVisualStyleBackColor = true;
            this.btnMapping.Click += new System.EventHandler(this.btnMapping_Click);
            // 
            // btnRoute
            // 
            this.btnRoute.Font = new System.Drawing.Font("MS UI Gothic", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnRoute.Location = new System.Drawing.Point(12, 117);
            this.btnRoute.Name = "btnRoute";
            this.btnRoute.Size = new System.Drawing.Size(408, 99);
            this.btnRoute.TabIndex = 1;
            this.btnRoute.Text = "経路作製";
            this.btnRoute.UseVisualStyleBackColor = true;
            this.btnRoute.Click += new System.EventHandler(this.btnRoute_Click);
            // 
            // btnDrive
            // 
            this.btnDrive.Font = new System.Drawing.Font("MS UI Gothic", 15F, System.Drawing.FontStyle.Regular, System.Drawing.GraphicsUnit.Point, ((byte)(128)));
            this.btnDrive.Location = new System.Drawing.Point(12, 270);
            this.btnDrive.Name = "btnDrive";
            this.btnDrive.Size = new System.Drawing.Size(408, 99);
            this.btnDrive.TabIndex = 2;
            this.btnDrive.Text = "自律走行！";
            this.btnDrive.UseVisualStyleBackColor = true;
            this.btnDrive.Click += new System.EventHandler(this.btnDrive_Click);
            // 
            // NCWCOSform
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(10F, 18F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(430, 379);
            this.Controls.Add(this.btnDrive);
            this.Controls.Add(this.btnRoute);
            this.Controls.Add(this.btnMapping);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "NCWCOSform";
            this.Text = "N.C.W.C.";
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button btnMapping;
        private System.Windows.Forms.Button btnRoute;
        private System.Windows.Forms.Button btnDrive;
    }
}

