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
	urgdArray = NULL;
}

// 左右のURGで障害物(仮)を検出した結果を総合して障害物の判断をする
urg_driving::ObstacleEmergency Manage2URG_Drive::checkObstacle()
{

	float* dataL[2], *dataR[2];
	float adis = 0.0, bdis = 0.0;
	int count[5] = {0, 0, 0, 0, 0};

	urgdArray[0].getObstacleData(dataR[0], dataR[1]);
	urgdArray[1].getObstacleData(dataL[0], dataL[1]);

	//cout << "点L：" << dataR[0][0] << endl;
	//cout << "点R：" << dataL[0][0] << endl;

	// ここに条件式1
	/*for (int i = 0; i < dataR[0][0]; i++)
	{
		for (int j = 0; j < dataL[0][0]; j++)
		{
			adis = pow((dataR[0][i] - dataL[0][j]), 2) + pow((dataR[1][i] - (dataL[1][j] + 280)), 2);
			if (adis < bdis)
			{
				bdis = adis;
			}
		}
		if (bdis < 2500){
			count += 1;
		}
	}*/


	//条件式2
	for (int i = 0; i < dataR[0][0]; i++){
		if (dataR[0][i] < 0 && dataR[1][i] < 0){
			//count[3] += 1;
		}
		else if (dataR[0][i] > 0){
			for (int j = 0; j < dataL[0][0]; j++){
				if (dataL[0][j] < 0 && dataL[1][j] > 0){
					//count[4] += 1;
				}
				else if ((dataL[0][j] > 0)){
					adis = pow((dataR[0][i] - dataL[0][j]), 2) + pow((dataR[1][i] - (dataL[1][j] + 280)), 2);
					if (adis < bdis){
						bdis = adis;
						}
					if (bdis < 2500 && 600 < dataR[0][i]){
						count[1] += 1;
						break;
					}
					else if (bdis < 2500 && 500 < dataR[0][i] && dataR[0][i] < 600){
						count[2] += 1;
						break;
					}
					else if (bdis < 2500 && dataR[0][i] < 500){
						count[0] += 1;
						break;
					}
				}
			}
		}
	}

	for (int i = 0; i < 2; i++) delete[] dataL[i];
	for (int i = 0; i < 2; i++) delete[] dataR[i];

	if (count[0] > 20 || count[3] > 10 || count[4] > 10){
		//停止する指令を送る
		return urg_driving::ObstacleEmergency::DETECT;

		//printf("点の数　= %d\n", count);
	}
	else if (count[1] > 10){
		//速度を1段階下げる指令を送る
		return urg_driving::ObstacleEmergency::SLOW1;
	}
	else if (count[2] > 10){
		//速度を2段階下げる指令を送る
		return urg_driving::ObstacleEmergency::SLOW2;
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

void Manage2URG_Drive::readMapImage(string mapName)
{
	tmMap = cv::imread(mapName);
	if (tmMap.empty())
	{
		cout << "False read Map image" << endl;
		int z = getchar();
	}
}