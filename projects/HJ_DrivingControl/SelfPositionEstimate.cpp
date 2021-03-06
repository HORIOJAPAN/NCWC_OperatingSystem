#include "DrivingControl.h"

using namespace cv;

int sp_x;
int sp_y;
int sp_angle;
int sp_score;


void Hyoka1(float tilt, float dist, float matchRatio, float& score){
	// score = matchRatio * 100;
	// score = (matchRatio * 100 - dist / 5 * (cos(tilt * 3.1415926 / 180) + 1));
	// score = 100 * (cos(tilt * 3.1415926 / 180) + 1) / 2 - (pow(dist, 0.7) + 5) / matchRatio;
	score = 100 * powf((cos(tilt * 3.1415926 / 180) + 1) / 2, 3) - (pow(dist, 0.75) + 5) / matchRatio;
	// 100*POWER((COS($B8*PI()/180)+1)/2,$D$2)-(POWER(D$5,$D$1)+5)/($C8/100)
}

void MatchingEvaluation(
	const cv::Mat img1,			// グローバル環境イメージ（大）
	const cv::Mat img2,			// ローカル環境イメージ（小）
	float angle_base,			// 評価基準角度
	float &angle_center,		// 評価中心角度
	float angleHalfRange,		// 範囲半角
	float angleDelta,			// 刻み角度
	float ideal_x,
	float ideal_y
	)
{
	// テンプレートマッチングと評価値の算出・最適値の出力

	Mat match;		// マッチング率の配列
	Mat kaitenImg;	// 回転させた地図を格納
	Point Pt;		// 画像内での最高マッチング率の座標を格納
	float distance;		// 理想座標とマッチング座標の相対距離
	float Evaluation1;	// 評価値

	double maxEvaluation0 = 0;
	float maxAngle = 0;
	float maxEvaluation = -10000;
	float maxDistance = 0;

	std::cout << "　■　中央角度：" << (int)angle_center << "[deg]　ピッチ：" << (int)angleDelta << "[deg]　　マッチング開始\n" << "回転角\t相関値   \tx,y\t距離\t評価値" << std::endl;

	for (float angle = (angle_center - angleHalfRange); angle < (angle_center + angleHalfRange + 1); angle += angleDelta)
	{	// 中央角‐範囲半角　から　中央角＋範囲半角　まで　1[deg]刻み

		// 画像の中心を求める
		// 回転行列の定義
		// 画像を回転
		Point2f center(img2.cols / 2.0, img2.rows / 2.0);
		Mat matrix = cv::getRotationMatrix2D(center, angle, 1);
		warpAffine(img2, kaitenImg, matrix, img2.size());

		// テンプレートマッチング
		matchTemplate(img1, kaitenImg, match, CV_TM_CCOEFF_NORMED);

		for (float k = 0; k < match.cols; k++)
		{
			for (float j = 0; j < match.rows; j++)
			{
				distance = sqrt((k - ideal_x)*(k - ideal_x) + (j - ideal_y)*(j - ideal_y));
				if (match.at<float>(j, k) > 0.1){
					Hyoka1((angle - angle_base), distance, match.at<float>(j, k), Evaluation1);

					if (Evaluation1 > maxEvaluation){
						maxEvaluation0 = match.at<float>(j, k);
						maxAngle = angle;
						Pt = Point(k, j);
						maxDistance = distance;
						maxEvaluation = Evaluation1;
						sp_score = Evaluation1;
					}
				}
			}
		}
		std::cout << (int)angle << "\t" << maxEvaluation0 << "   \t" << Pt.x << "," << Pt.y << "\t" << maxDistance << "\t" << maxEvaluation << std::endl;
	}
	std::cout << std::endl;

	sp_x = Pt.x;
	sp_y = Pt.y;
	sp_angle = maxAngle;
	angle_center = sp_angle;
}

# define fieldSquareSize 500		// トリミング後、フィールド画像の縦横フル長さ
# define matchSquareSize 200		// トリミング後、マッチ画像の縦横フル長さ

# define kakudoHaba1 36		// 1回目角度幅（片方向）
# define kakudoHaba2 5		// 2回目

# define kizamiKakudo1 3	// 1回目刻み角度
# define kizamiKakudo2 1	// 2回目

void spEstimate(int ideal_x, int ideal_y, float ideal_angle, Mat img1, Mat img2)
{ // Self Position Estimate		//(x, y, angle, fieldMap, matchMap)

	// 画像の配列を宣言
	// Mat img1 = imread(imageName);
	// Mat img2 = imread("./img/a001.jpg");

	const int leftBorder = ideal_x - (fieldSquareSize) / 2;
	const int upBorder = ideal_y - (fieldSquareSize) / 2;
	const int rightBorder = ideal_x + (fieldSquareSize) / 2;
	const int downBorder = ideal_y + (fieldSquareSize) / 2;
	/*
	const int leftBorder = ideal_x - (fieldSquareSize - matchSquareSize) / 2;
	const int upBorder = ideal_y - (fieldSquareSize - matchSquareSize) / 2;
	const int rightBorder = ideal_x + (fieldSquareSize + matchSquareSize) / 2;
	const int downBorder = ideal_y + (fieldSquareSize + matchSquareSize) / 2;
	*/
	const int leftBorder2 = (img2.cols - matchSquareSize) / 2;
	const int upBorder2 = (img2.rows - matchSquareSize) / 2;
	const int rightBorder2 = (img2.cols + matchSquareSize) / 2;
	const int downBorder2 = (img2.rows + matchSquareSize) / 2;

	// 画像img1からマッチング対象領域を指定して再定義
	Mat fieldMap = img1(Rect(leftBorder, upBorder, rightBorder - leftBorder, downBorder - upBorder));
	Mat matchMap = img2(Rect(leftBorder2, upBorder2, rightBorder2 - leftBorder2, downBorder2 - upBorder2));
	// Mat matchMap = img2(Rect(leftBorder, upBorder, rightBorder - leftBorder, downBorder - upBorder));

	std::cout << "元マッチ画像サイズ\t" << img2.rows << "\t" << img2.cols << "\t" << "新マッチ画像サイズ\t" << matchMap.cols << "\t" << matchMap.rows << "\t" << "\n" << std::endl;

	Point ideal_Pt;
	ideal_Pt = Point(ideal_x, ideal_y);
	float tempAngle = ideal_angle;	// 評価の中心角の初期化

	// 理想座標の指定（エンコーダやサーボの指定値による）
	ideal_Pt.x -= leftBorder + matchSquareSize / 2;
	ideal_Pt.y -= upBorder + matchSquareSize / 2;


	MatchingEvaluation(fieldMap, matchMap, ideal_angle, tempAngle, kakudoHaba1, kizamiKakudo1, ideal_Pt.x, ideal_Pt.y);
	// この辺でマッチング失敗を返す？

	MatchingEvaluation(fieldMap, matchMap, ideal_angle, tempAngle, kakudoHaba2, kizamiKakudo2, ideal_Pt.x, ideal_Pt.y);

	Point2f center(matchMap.cols / 2.0, matchMap.rows / 2.0);
	Mat kaitenImg;
	Mat matrix = cv::getRotationMatrix2D(center, tempAngle, 1);
	warpAffine(matchMap, kaitenImg, matrix, matchMap.size());
	// rectangle(fieldMap, Point(sp_x + kaitenImg.cols / 2, sp_y + kaitenImg.rows / 2), Point(sp_x + kaitenImg.cols / 2, sp_y + kaitenImg.rows / 2), Scalar(0, 0, 255), 2, 8, 0);
	circle(fieldMap, Point(sp_x + kaitenImg.cols / 2, sp_y + kaitenImg.rows / 2), 6, Scalar(0, 0, 255), 1, CV_AA, 0);
	circle(kaitenImg, Point(kaitenImg.cols / 2, kaitenImg.rows / 2), 6, Scalar(0, 0, 255), 1, CV_AA, 0);


	//imshow("Image", fieldMap);
	//imshow("kaitenImg", kaitenImg);
}

int ideal_angle = 0;

int	ideal_x;
int	ideal_y;


void Manage2URG_Drive::tMatching(int& pos_x, int& pos_y, double& angle,int mapNum){
	clock_t start = clock();

	sp_x = ideal_x = pos_x;
	sp_y = ideal_y = pos_y;
	sp_angle = ideal_angle = -angle * 180 / PI;
	sp_score = 0;

	this->getAroundImage();

	spEstimate(sp_x, sp_y, sp_angle, tmMap[mapNum], tmTemplate);

	// ↓これの結果とsp_angleがマッチング結果の座標と角度の絶対値(フィールド画像の座標系)
	
	sp_x += ideal_x - (fieldSquareSize - matchSquareSize) / 2;
	sp_y += ideal_y - (fieldSquareSize - matchSquareSize) / 2;
	/*
	sp_x += ideal_x - (fieldSquareSize) / 2;
	sp_y += ideal_y - (fieldSquareSize) / 2;
	*/
	std::cout << "入力：\n相対度\tx,y\n" << ideal_angle << "   \t" << ideal_x << "," << ideal_y << std::endl;
	std::cout << "出力：\n相対度\tx,y\tscore\n" << sp_angle << "   \t" << sp_x << "," << sp_y << "\t" << sp_score << std::endl;
	std::cout << "処理時間：" << clock() - start << "[ms]" << std::endl;

	if (sp_score > 1){
		pos_x = sp_x;
		pos_y = sp_y;
		angle = -sp_angle * PI / 180;
	}
	//waitKey(10000);
	//destroyAllWindows();
}
