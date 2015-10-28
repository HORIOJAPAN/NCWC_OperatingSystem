using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;

using System.Diagnostics;
using System.Threading;

namespace HJ_MakeRoute
{
    public partial class MakeRouteForm : Form
    {
        int speed;
        int accuracy;

        Boolean startPoint = true;

        // c#用の共有メモリクラスはちゃんと作ってないのでとりあえず一時使用のクラス
        // 共有メモリ番号に名前を付けて列挙型で管理したかったけどc#では暗黙的キャストでintにしてくれないらしい
        // 共有メモリの内容を静的な列挙型で定義しておき，使用時はintに変換して使用する
        class ShMemManager : SharedMemory
        {
            // 共有メモリで共有する内容
            public enum Content { ISCOODDECISION , COOD_X , COOD_Y , ISCONFIRMED , ISEXIT , ISINSERT };

            // 基底クラスのコンストラクタに引数を渡す
            public ShMemManager( string shMemName ):base(shMemName){}
            // getter，setterのオーバーロード
            public Int32 getShMemData(Content offset) { return base.getShMemData((int)offset); }
            public void setShMemData(Int32 data, Content offset) { base.setShMemData(data, (int)offset); }
            public void setShMemData(bool data, Content offset) { base.setShMemData( (data ? 1 : 0), (int)offset); }
        } ;
        ShMemManager shMem;


        public MakeRouteForm()
        {
            InitializeComponent();

            speed = 1;
            accuracy = 1;

            // 共有メモリクラスの初期化
            shMem = new ShMemManager("CoordinateOfMap");
        }

        // ラジオボタンからデータ取得
        private void speedRB_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton RBtn = (RadioButton)sender;

            speed = Int32.Parse(RBtn.Tag.ToString());

        }

        // ラジオボタンからデータ取得
        private void accuracyRB_CheckedChanged(object sender, EventArgs e)
        {
            RadioButton RBtn = (RadioButton)sender;

            accuracy = Int32.Parse(RBtn.Tag.ToString());
        }

        // Saveボタンの定義
        // 保存用ダイアログを表示して選択されたパスに経路情報を保存
        private async void saveBtn_Click(object sender, EventArgs e)
        {
            saveRouteDlog.FileName = newRouteDlog.FileName + ".rt";
            saveRouteDlog.ShowDialog();
            using (StreamWriter w = new StreamWriter(saveRouteDlog.FileName))
            {
                w.Write(routeTxt.Text);
            }
            shMem.setShMemData( true , ShMemManager.Content.ISEXIT);

            // cppで画像の保存が終わるまで待つ
            do
            {
                await Task.Delay(500);
            } while (shMem.getShMemData(ShMemManager.Content.ISEXIT) != 0 ); 
            // 元画像のディレクトリに保存された経路画像を指定ディレクトリに移動する
            System.IO.File.Copy(newRouteDlog.FileName + ".jpg", saveRouteDlog.FileName.Substring(0, saveRouteDlog.FileName.Length - 3) + ".jpg");
            System.IO.File.Delete(newRouteDlog.FileName + ".jpg");

            MessageBox.Show("Saved ! \n ⊂二二二（ ＾ω＾）二⊃ ﾌﾞｰﾝ");

        }

        // 経路情報を末尾に追加
        private void confirmBtn_Click(object sender, EventArgs e)
        {
            // 原点の設定
            if (startPoint)
            {
                String str = String.Format("{0}, {1}, \r\n", x_val.Text, y_val.Text);
                routeTxt.Text += str;
                startPoint = false;
            }
            // 経路情報をテキストで保存
            else
            {
                String str = String.Format("{0}, {1}, {2}, {3}, \r\n", x_val.Text, y_val.Text, speed, accuracy);
                routeTxt.Text += str;
            }

            shMem.setShMemData( true , ShMemManager.Content.ISCONFIRMED);
        }

        // 経路情報をカーソル位置に挿入
        private void insertBtn_Click(object sender, EventArgs e)
        {
            int pos = routeTxt.SelectionStart;
            String str = String.Format("{0}, {1}, {2}, {3},", x_val.Text, y_val.Text, speed, accuracy);

            routeTxt.Text = routeTxt.Text.Insert(pos, str);

            // いったん保存して挿入した内容をcppに知らせる
            using (StreamWriter w = new StreamWriter(newRouteDlog.FileName + ".tmp"))
            {
                w.Write(routeTxt.Text);
            }
            shMem.setShMemData(true, ShMemManager.Content.ISCONFIRMED);
            shMem.setShMemData(true, ShMemManager.Content.ISINSERT);
        }

        // ウィンドウがアクティブになった時にXY座標の表示を更新
        private void MakeRouteForm_Activated(object sender, System.EventArgs e)
        {
            if (shMem.getShMemData(ShMemManager.Content.ISCOODDECISION) != 0)
            {
                x_val.Text = shMem.getShMemData(ShMemManager.Content.COOD_X).ToString();
                y_val.Text = shMem.getShMemData(ShMemManager.Content.COOD_Y).ToString();

                shMem.setShMemData( false , ShMemManager.Content.ISCOODDECISION );
            }
        }

        // 経路情報を作成する画像を選択させる
        // 選択された画像のパスからc++のプロセスを起動
        private void newRouteDlog_FileOk(object sender, CancelEventArgs e)
        {
            shMem.setShMemData( false, ShMemManager.Content.ISEXIT);
            shMem.setShMemData(false, ShMemManager.Content.ISINSERT);

            routeTxt.Text = String.Format("X, Y, S, A, etc, \r\n");

            Process myProcess = new Process();
            myProcess.StartInfo.FileName = "../../../Debug\\MakeRoutepp.exe";
            myProcess.StartInfo.Arguments = "\"" + newRouteDlog.FileName + "\"";
            myProcess.StartInfo.WindowStyle = ProcessWindowStyle.Normal;
            myProcess.Start();
        }
        
        // 画像選択用のダイアログを表示
        private void NewBtn_Click(object sender, EventArgs e)
        {
            newRouteDlog.ShowDialog();
        }

        private void saveRouteDlog_FileOk(object sender, CancelEventArgs e)
        {

        }

    }
}
