using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace HJ_NCWC_OperatingSystem
{
    static class Program
    {
        /// <summary>
        /// アプリケーションのメイン エントリ ポイントです。
        /// </summary>
        [STAThread]
        static void Main()
        {
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new NCWCOSform());
        }
    }

    public class Sayakachandeista : Form
    {
        private System.Windows.Forms.PictureBox picSayaka;

        public Sayakachandeista()
        {
            this.picSayaka = new System.Windows.Forms.PictureBox();
            this.picSayaka.Dock = DockStyle.Fill;
            //this.picSayaka.SizeMode = PictureBoxSizeMode.AutoSize;
            System.IO.FileStream fs;
            fs = new System.IO.FileStream("C:\\Users\\user\\Documents\\Visual Studio 2013\\Projects\\HJ_NCWC_OperatingSystem\\res\\img\\144356b2-s.jpg"
                                 , System.IO.FileMode.Open
                                 , System.IO.FileAccess.Read);
            picSayaka.Image = System.Drawing.Image.FromStream(fs);
            fs.Close();

            int width = picSayaka.Image.Width;
            int height = picSayaka.Image.Height;

            this.ClientSize = new System.Drawing.Size(width, height);
            this.MaximizeBox = false;
            this.MinimizeBox = false;
            this.ShowInTaskbar = false;
            this.FormBorderStyle = FormBorderStyle.FixedSingle;

            this.Controls.Add(this.picSayaka);
        }
    }
}
