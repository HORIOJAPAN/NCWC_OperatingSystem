using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

using System.Diagnostics;
using System.Threading;

namespace HJ_ProcessManager
{
    class ProcessManager
    {
        //メインメソッド
        [STAThread]
        static void Main()
        {
            //ProcessManager pm = new ProcessManager();
            //pm.pmMain();

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Application.Run(new ProcessManagerForm());
        }

        //メモ帳が起動しているか監視
        public void pmMain()
        {
            //ProcessManagerのメインループ
            while (true)
            {
                bool flg = false;

                //全プロセス情報を取得
                Process[] processList = Process.GetProcesses();
                foreach (Process p in processList)
                {
                    //メモ帳のプロセスが存在するかどうか
                    if (p.ProcessName == "notepad")
                    {
                        flg = true;

                        //フリーズしていないか確認
                        if (p.Responding)
                        {
                            Console.WriteLine("OK");
                            break;
                        }
                        else
                        {
                            //フリーズしていたら再起動
                            p.CloseMainWindow();
                            RunApp();
                        }
                    }
                }
                //メモ帳のプロセスが無ければ起動
                if (!flg)
                {
                    RunApp();
                }
                System.Threading.Thread.Sleep(5000);
            }
        }

        //メモ帳を起動する
        private void RunApp()
        {
            Process myProcess = new Process();
            myProcess.StartInfo.FileName = "Notepad";
            myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            myProcess.Start();
        }

    }
}
