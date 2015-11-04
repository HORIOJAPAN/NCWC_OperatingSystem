#include "DrivingControl.h"

// URGのパラメータをセットする
void Manage2URG_Drive::setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG)
{
	urgdArray = new urg_driving[NumOfURG];
	for (int i = 0; i < NumOfURG; i++)
	{
		urgdArray[i].init(URG_COM[i], URGPOS[i]);
	}
}
// デストラクタで配列の解放
Manage2URG_Drive::~Manage2URG_Drive()
{
	delete[] urgdArray;
}

// 左右のURGで障害物(仮)を検出した結果を総合して障害物の判断をする
urg_driving::ObstacleEmergency Manage2URG_Drive::checkObstacle()
{

	float* data0[2], *data1[2];
	float adis = 0.0, bdis = 0.0;
	int count = 0;

	urgdArray[0].getObstacleData(data0[0], data0[1]);
	urgdArray[1].getObstacleData(data1[0], data1[1]);

	cout << "点：" << data0[0][0] << endl;

	// ここに条件式
	for (int i = 0; i < data0[0][0]; i++)
	{
		for (int j = 0; j < data1[0][0]; j++)
		{
			adis = pow((data0[0][i] - (data1[0][j] + 280)), 2) + pow((data0[1][i] - (data1[1][j] + 280)), 2);
			if (adis < bdis)
			{
				bdis = adis;
			}
		}
		if (bdis < 2500){
			count += 1;
		}
	}

	for (int i = 0; i < 2; i++) delete[] data0[i];
	for (int i = 0; i < 2; i++) delete[] data1[i];

	if (count > 10){
		return urg_driving::ObstacleEmergency::DETECT;
		//printf("点の数　= %d\n", count);
	}

	return urg_driving::ObstacleEmergency::NONE;

}

// 停止した状態で周辺の画像を作成するやつ(TM用)
void Manage2URG_Drive::getAroundImage(int width, int height, int resolution, int measurementTimes)
{
	PCImage::isColor = true;
	urg_driving::initPCImage(width, height, resolution);
	urg_driving::setPCImageOrigin(width / 2, height / 2);

	PCImage::BGR color[2] = { PCImage::B, PCImage::G };
	for (int times = 0; times < measurementTimes; times++)
	{
		for (int i = 0; i < 2; i++)
		{
			urgdArray[i].setWriteLine(false);
			urgdArray[i].setPCImageColor(color[i]);
			urgdArray[i].writeMap(0, 0, 0);
		}
	}
	urg_driving::getPCImage(tmTemplate);
	cv::imshow("show", tmTemplate);
	cv::waitKey(0);
}
