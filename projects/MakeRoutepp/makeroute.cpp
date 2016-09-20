#include <opencv2/opencv.hpp>
#include <opencv2/opencv_lib.hpp>
#include <cstdlib>
#include <fstream>

#include "SharedMemory.h"
#include "../cvPCDtest/pcimage.h"

using namespace cv;
using namespace std;

// 画像
Mat pic;
Mat pic_col;
Mat pic_tmp;
Mat pic_zoom;

// サイズや点など
Size zoomSize(800,600);
Size reductionRate;
Point zoomPoint;
Point prePoint(-1,-1);
Point originXY;

// 共有メモリ系
SharedMemory<int> shMem("CoordinateOfMap");
enum { ISCOODDECISION , COOD_X , COOD_Y , ISCONFIRMED , ISEXIT , ISINSERT};

// コールバックで取得された座標
int xy[2] = { 0, 0 };

// 画像をリサイズして描画
void imshowResize(string& name, Mat& mat, Size size)
{
	Mat showmat;
	resize(mat, showmat, size);

	imshow(name, showmat);
}

// 経路情報を読み込み直して画像に反映する
void reloadRoute(string path)
{
	cvtColor(pic, pic_tmp, CV_GRAY2BGR);
	Point prePoint(-1, -1);

	int	x_val, y_val;

	string str, x_str, y_str;
	string searchWord(",");
	string::size_type x_pos, y_pos;

	// csで保存した経路情報の一時ファイルを読み込む
	ifstream ifs(path + ".tmp");
	if (ifs.fail())
	{
		cerr << "False" << endl;
		shMem.setShMemData(false, ISINSERT);
		return;
	}
	//ヘッダ部分をとばす
	getline(ifs, str);

	while (getline(ifs, str))
	{
		//先頭から,までの文字列をint型で取得
		x_pos = str.find(searchWord);
		if (x_pos != string::npos){
			x_str = str.substr(0, x_pos);
			x_val = stoi(x_str);
		}

		//xの値の後ろから,までの文字列をint型で取得
		y_pos = str.find(searchWord, x_pos + 1);
		if (y_pos != string::npos){
			y_str = str.substr(x_pos + 1, y_pos);
			y_val = stoi(y_str);
		}

		//取得した[x,y]を画像に反映
		pic_tmp.at<Vec3b>(y_val, x_val ) = Vec3b(0, 255, 0);
		circle(pic_tmp, cv::Point(x_val, y_val), 10, cv::Scalar(0, 255, 0), 3);
		if (prePoint.x > 0 && prePoint.y > 0) line(pic_tmp, prePoint, Point(x_val, y_val), cv::Scalar(0, 0, 200), 3, 4);

		prePoint = Point(x_val, y_val);
	}
	pic_col = pic_tmp.clone();
	rectangle(pic_tmp, zoomPoint, Point(zoomPoint.x + zoomSize.width, zoomPoint.y + zoomSize.height), cv::Scalar(0, 0, 200), 5, 4);

	imshowResize(string("Origin"), pic_tmp, Size(pic_tmp.cols / reductionRate.width, pic_tmp.rows / reductionRate.height));

	// zoom画像に点を描画
	pic_zoom = Mat(pic_col, Rect(zoomPoint, zoomSize));
	imshow("zoom", pic_zoom);

	::prePoint = prePoint;

	shMem.setShMemData(false, ISCONFIRMED);
	shMem.setShMemData(false, ISINSERT);
}

// 左クリックで経路座標を選択
void coodClick(int event, int x, int y, int flag, void* )
{

	// マウスイベントを取得
	switch (event) {
	case cv::EVENT_MOUSEMOVE:
		break;
	case cv::EVENT_LBUTTONDOWN:
		// クリックされた座標をグローバル変数に保存
		xy[0] = x;
		xy[1] = y;

		// 座標を共有メモリに保存
		shMem.setShMemData(true, ISCOODDECISION);
		shMem.setShMemData(x + zoomPoint.x, COOD_X);
		shMem.setShMemData(y + zoomPoint.y, COOD_Y);

		// 座標に点を打つ(確定ではないので一時画像に挿入して表示)
		pic_tmp = pic_zoom.clone();
		pic_tmp.at<Vec3b>(xy[1], xy[0]) = Vec3b(150, 50, 200);
		circle(pic_tmp, Point(xy[0], xy[1]), 4, Scalar(150, 50, 200), 2);
		imshow("zoom", pic_tmp);

		break;
	case cv::EVENT_RBUTTONDOWN:
		break;
	case cv::EVENT_MBUTTONDOWN:
		break;
	case cv::EVENT_LBUTTONUP:
		break;
	case cv::EVENT_RBUTTONUP:
		break;
	case cv::EVENT_MBUTTONUP:
		break;
	case cv::EVENT_LBUTTONDBLCLK:
		break;
	case cv::EVENT_RBUTTONDBLCLK:
		break;
	case cv::EVENT_MBUTTONDBLCLK:
		break;
	}

}

// 左クリックでzoomの位置を変更
void zoomCoodClick(int event, int x, int y, int flag, void*)
{

	// マウスイベントを取得
	switch (event) {
	case cv::EVENT_LBUTTONDOWN:
		// zoom画像の左上の座標
		zoomPoint = Point(x * reductionRate.width - zoomSize.width / 2, y * reductionRate.height - zoomSize.height / 2);

		// zoom画像の座標が元画像を超えないようにチェック
		zoomPoint.x < 0 ? zoomPoint.x = 0 : 0;
		zoomPoint.x + zoomSize.width > pic.cols ? zoomPoint.x = pic.cols - zoomSize.width : 0;
		zoomPoint.y < 0 ? zoomPoint.y = 0 : 0;
		zoomPoint.y + zoomSize.height > pic.rows ? zoomPoint.y = pic.rows - zoomSize.height : 0;


		// zoomした位置を赤で囲む
		pic_tmp = pic_col.clone();
		rectangle(pic_tmp, zoomPoint, Point(zoomPoint.x + zoomSize.width, zoomPoint.y + zoomSize.height), cv::Scalar(0, 0, 200), 5, 4);
		imshowResize(string("Origin"), pic_tmp, Size(pic_tmp.cols / reductionRate.width, pic_tmp.rows / reductionRate.height));

		// zoom画像を作成して表示
		pic_zoom = Mat(pic_col, Rect(zoomPoint, zoomSize));
		imshow("zoom", pic_zoom);

		break;
	}

}

void main(int argc, char* argv[])
{
	// コマンドライン引数からパスを取得して画像を読み込む
	pic = imread(argv[1] , 0);
	//pic = imread("C:\\Users\\NCWC\\Source\\Repos\\NCWC_OperatingSystem\\projects\\cvPCDtest\\20160527144523\\0_0.jpg", 0);
	//
	ifstream ifs("origin.txt");
	if (ifs.fail())
	{
		originXY = Point(0, 0);
		cout << "Origin:" << originXY.x << "," << originXY.y << endl;
	}
	else
	{
		string str;
		getline(ifs, str);
		originXY.x = stoi(str);
		getline(ifs, str);
		originXY.y = stoi(str);
		cout << "Origin:" << originXY.x << "," << originXY.y << endl;
	}

	//uniteImage(argv[1], originXY, pic, 1000);

	// 複製
	pic_col = Mat(pic.rows, pic.cols, CV_8UC3);
	cvtColor(pic, pic_col, CV_GRAY2BGR);
	pic_tmp = pic_col.clone();
	pic_zoom = Mat(pic_col, Rect((pic_col.cols - zoomSize.width) / 2, (pic_col.rows - zoomSize.height) / 2,  zoomSize.width, zoomSize.height));

	// 全体画像の縮小率．縦横比固定のためzoomSizeの大きいほうのみで決める
	int largerSize = zoomSize.width > zoomSize.height ? zoomSize.width : zoomSize.height;
	reductionRate = Size(pic.cols / largerSize, pic.rows / largerSize);

	// 全体画像を縮小して表示
	namedWindow("Origin", 1);
	cv::setMouseCallback("Origin", zoomCoodClick, 0);
	imshowResize(string("Origin"), pic_col,Size(pic.cols/reductionRate.width,pic.rows/reductionRate.height));

	// ズーム画像を表示
	namedWindow("zoom", 1 );
	cv::setMouseCallback("zoom", coodClick, 0);
	imshow("zoom", pic_zoom);

	int key;
	bool startingPoint = true;
	while (true){
		key = waitKey(5);
		if (key == 's'){//保存
			string str;
			cout << "s" << endl;
			cout << "保存名=>";
			getline(cin, str);
			imwrite(str, pic_col);
			cout << "Saved" << endl;
		}
		else if (key == 'q' || shMem.getShMemData(ISEXIT))
		{
			string imgname = argv[1];
			imgname += ".jpg";
			imwrite(imgname, pic_col);
			cout << "Saved" << endl;
			shMem.setShMemData(false ,ISEXIT);
			break;
		}
		//点が確定したとき
		if (shMem.getShMemData( ISCONFIRMED ) != 0 )
		{
			// 確定画像にも点を描画
			if (startingPoint)
			{
				pic_col.at<Vec3b>(xy[1] + zoomPoint.y, xy[0] + zoomPoint.x) = Vec3b(255, 255, 0);
				circle(pic_col, cv::Point(xy[0] + zoomPoint.x, xy[1] + zoomPoint.y), 10, cv::Scalar(255, 255, 0), 3);
				startingPoint = false;
			}
			else
			{
				pic_col.at<Vec3b>(xy[1] + zoomPoint.y, xy[0] + zoomPoint.x) = Vec3b(0, 255, 0);
				circle(pic_col, cv::Point(xy[0] + zoomPoint.x, xy[1] + zoomPoint.y), 10, cv::Scalar(0, 255, 0), 3);
				if (prePoint.x > 0 && prePoint.y > 0) line(pic_col, prePoint, Point(xy[0] + zoomPoint.x, xy[1] + zoomPoint.y), cv::Scalar(0, 0, 200), 3, 4);
			}

			pic_tmp = pic_col.clone();
			rectangle(pic_tmp, zoomPoint, Point(zoomPoint.x + zoomSize.width, zoomPoint.y + zoomSize.height), cv::Scalar(0, 0, 200), 5, 4);

			imshowResize(string("Origin"), pic_tmp, Size(pic_tmp.cols / reductionRate.width, pic_tmp.rows / reductionRate.height));

			prePoint = Point(xy[0] + zoomPoint.x, xy[1] + zoomPoint.y);

			// zoom画像に点を描画
			pic_zoom = Mat(pic_col, Rect(zoomPoint, zoomSize));
			imshow("zoom", pic_zoom);

			shMem.setShMemData( false , ISCONFIRMED );
		}

		// cs側で経路を挿入したら反映のために経路情報を読みこみ直す
		if (shMem.getShMemData(ISINSERT))
		{
			reloadRoute(argv[1]);
		}

	}
}