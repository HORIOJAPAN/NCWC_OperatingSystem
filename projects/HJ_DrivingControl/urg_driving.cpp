#include "DrivingControl.h"

// 障害物を検出してその有無を返す(過去の遺産)
urg_driving::ObstacleEmergency urg_driving::checkObstacle()
{
	this->urg_unko::getData4URG(0, 0, 0);

	int count = 0;
	for (int i = 0; i < data_n; ++i) {
		long l = data[i];	//取得した点までの距離
		double radian;
		float x, y, z;
		float ideal_x, ideal_y;

		//異常値ならとばす
		if (!this->pointpos[0][i] && !this->pointpos[1][i])	continue;

		//点までの角度を取得してxyに変換
		//(極座標で取得されるデータをデカルト座標に変換)
		radian = urg_index2rad(&urg, i);
		x = (float)(l * cos(radian));
		y = (float)(l * sin(radian));
		z = urgpos[0];

		ideal_x = (float)(l * cos(radian + (double)urgpos[3]));
		ideal_y = (float)(l * sin(radian + (double)urgpos[3]));

		// 右センサの領域判別
		if (urgpos[2] > 0)
		{
			if (ideal_x < 1000.0 && ideal_y < 200.0 && ideal_y > -500.0)
				//if (ideal_x < 500.0)
			{
				count += 1;
			}
		}
		// 左センサの領域判別
		else if (urgpos[2] < 0)
		{
			if (ideal_x < 1000.0 && ideal_y < 500.0 && ideal_y > -200.0)
			{
				count += 1;
			}
		}
	}
	if (count > 8){
		return DETECT;
		//printf("点の数　= %d\n", count);
	}
	return NONE;
}


// 障害物を検出してその結果を配列で返す
void urg_driving::getObstacleData(float*& data_x, float*& data_y)
{
	this->urg_unko::getData4URG(0, 0, 0);

	data_x = new float[data_n];
	data_y = new float[data_n];
	int datacount = 1;

	for (int i = 0; i < data_n; ++i) {
		long l = data[i];	//取得した点までの距離
		double radian;
		float x, y, z;
		float ideal_x, ideal_y;

		//異常値ならとばす
		if (!this->pointpos[0][i] && !this->pointpos[1][i])	continue;

		//点までの角度を取得してxyに変換
		//(極座標で取得されるデータをデカルト座標に変換)
		radian = urg_index2rad(&urg, i);
		x = (float)(l * cos(radian));
		y = (float)(l * sin(radian));
		z = urgpos[0];

		// 右センサの領域判別
		if (urgpos[2] > 0)
		{
			ideal_x = (float)(l * cos(radian - (double)urgpos[3]));
			ideal_y = (float)(l * sin(radian - (double)urgpos[3]));

			if (ideal_x < 1000.0 && ideal_y < 250.0 && ideal_y > -770.0)
				//if (ideal_x < 500.0)
			{
				data_x[datacount] = ideal_x;
				data_y[datacount] = ideal_y;
				datacount++;
			}
		}
		// 左センサの領域判別
		else if (urgpos[2] < 0)
		{
			ideal_x = (float)(l * cos(radian - (double)urgpos[3]));
			ideal_y = (float)(l * sin(radian - (double)urgpos[3]));

			if (ideal_x < 1000.0 && ideal_y < 770.0 && ideal_y > -250.0)
			{
				data_x[datacount] = ideal_x;
				data_y[datacount] = ideal_y;
				datacount++;
			}
		}
	}

	data_x[0] = datacount - 1;
	data_y[0] = datacount - 1;
}