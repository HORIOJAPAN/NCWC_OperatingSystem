/*
 *	経路情報のテキストファイル(拡張子.rt)を上から順に読み込んで移動距離，回転を計算し，
 *	シリアル通信で駆動指令を送信する．
 */
#include "DrivingControl.h"

#define PI 3.14159265359

/*
*	概要:
*		Arduinoとシリアル通信を行うためのハンドルを取得する
*	引数：
*		HANDLE&	hComm	ハンドル変数への参照
*	返り値:
*		なし
*/
void getArduinoHandle(int arduinoCOM, HANDLE& hComm , int timeoutmillisec )
{
	//シリアルポートを開いてハンドルを取得
	string com = "\\\\.\\COM" + to_string(arduinoCOM);
	hComm = CreateFile(com.c_str(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
	if (hComm == INVALID_HANDLE_VALUE){
		printf("シリアルポートを開くことができませんでした。");
		char z;
		z = getchar();
		return;
	}
	//ポートを開けていれば通信設定を行う
	else
	{
		DCB lpTest;
		GetCommState(hComm, &lpTest);
		lpTest.BaudRate = 9600;
		lpTest.ByteSize = 8;
		lpTest.Parity = NOPARITY;
		lpTest.StopBits = ONESTOPBIT;
		SetCommState(hComm, &lpTest);

		COMMTIMEOUTS lpTimeout;
		GetCommTimeouts(hComm, &lpTimeout);
		lpTimeout.ReadIntervalTimeout = timeoutmillisec;
		lpTimeout.ReadTotalTimeoutMultiplier = 0;
		lpTimeout.ReadTotalTimeoutConstant = timeoutmillisec;
		SetCommTimeouts(hComm, &lpTimeout);

	}
}
void DrivingControl::setControllerCOM(int ctrlerCOM)
{
	this->controllerCOM = ctrlerCOM;
	getArduinoHandle(controllerCOM, hControllerComm, 500);
}

void DrivingControl::sendDrivingCommand(int mode_int, int forward_int, int  crosswise_int, int delay_int)
{
	unsigned char	sendbuf[18];
	unsigned char	receive_data[18];
	unsigned long	len;

	unsigned char	mode;
	unsigned char	sign1, sign2;
	ostringstream	forward_sout, crosswise_sout, delay_sout;
	string			forward_str, crosswise_str, delay_str;

	mode = to_string(mode_int)[0];

	if (forward_int < 0)
	{
		forward_int *= -1;
		sign1 = '1';
	}
	else sign1 = '0';

	forward_sout << setfill('0') << setw(4) << forward_int;
	forward_str = forward_sout.str();

	if (crosswise_int < 0)
	{
		crosswise_int *= -1;
		sign2 = '1';
	}
	else sign2 = '0';

	crosswise_sout << setfill('0') << setw(4) << crosswise_int;
	crosswise_str = crosswise_sout.str();

	delay_sout << setfill('0') << setw(5) << delay_int;
	delay_str = delay_sout.str();

	// バッファクリア
	memset(sendbuf, 0x00, sizeof(sendbuf));

	sendbuf[0] = 'j';
	sendbuf[1] = mode;
	sendbuf[2] = sign1;
	for (int i = 3; i < 7; i++)	sendbuf[i] = forward_str[i - 3];
	sendbuf[7] = sign2;
	for (int i = 8; i < 12; i++) sendbuf[i] = crosswise_str[i - 8];
	for (int i = 12; i < 17; i++) sendbuf[i] = delay_str[i - 12];
	sendbuf[17] = 'x';

	// 通信バッファクリア
	PurgeComm(hControllerComm, PURGE_RXCLEAR);
	// 送信
	retLastSend = WriteFile(hControllerComm, &sendbuf, sizeof(sendbuf), &len, NULL);

	cout << "send:";
	for (int i = 0; i < len; i++)
	{
		cout << sendbuf[i];
	}
	cout << endl;

	// バッファクリア
	memset(receive_data, 0x00, sizeof(receive_data));
	// 通信バッファクリア
	PurgeComm(hControllerComm, PURGE_RXCLEAR);
	len = 0;
	// Arduinoからデータを受信
	retLastRead = ReadFile(hControllerComm, &receive_data, sizeof(receive_data), &len, NULL);

	cout << "receive:";
	for (int i = 0; i < len; i++)
	{
		cout << receive_data[i];
	}
	cout << endl;

	cout << retLastRead << endl;
}


/*
 * コンストラクタ
 * 経路ファイルを読み込んでヘッダをとばす
 */
DrivingFollowPath::DrivingFollowPath(string fname, double coefficientL, double coefficientR, int ecdrCOM , int ctrlrCOM)
	: fileName(fname), leftCoefficient(coefficientL), rightCoefficient(coefficientR), encoderCOM(ecdrCOM)
{
	controllerCOM = ctrlrCOM;

	// 経路データを読み込む
	ifs.open(fileName);
	if (ifs.fail())
	{
		cerr << "False" << endl;
		return;
	}
	// ヘッダ部分をとばす
	getline(ifs, str);

	// 原点を取得しておく
	getNextPoint();

	// 初めの回転角計算用として原点の少し後方に点を追加
	x_now = x_next - 5;
	y_now = y_next;

	getArduinoHandle(encoderCOM, hEncoderComm, 0);
	setControllerCOM(controllerCOM);

}

/*
 * 次の点を読み込む
 */
bool DrivingFollowPath::getNextPoint()
{
	// 古い座標を保存
	x_old = x_now;
	y_old = y_now;
	x_now = x_next;
	y_now = y_next;

	// 次の行が存在しなければfalseを返す
	if (!getline(ifs, str)) return false;

	//先頭から","までの文字列をint型で取得
	x_pos = str.find(searchWord);
	if (x_pos != string::npos){
		x_str = str.substr(0, x_pos);
		x_next = stoi(x_str);
	}

	//xの値の後ろから","までの文字列をint型で取得
	y_pos = str.find(searchWord, x_pos + 1);
	if (y_pos != string::npos){
		y_str = str.substr(x_pos + 1, y_pos);
		y_next = stoi(y_str);
	}
	cout << x_next << "," << y_next << endl;

	return true;
}

void DrivingFollowPath::getEncoderCount()
{
	unsigned char	sendbuf[1];
	unsigned char	receive_data[2];
	unsigned long	len;

	// バッファクリア
	memset(sendbuf, 0x01, sizeof(sendbuf));
	// 通信バッファクリア
	PurgeComm(hEncoderComm, PURGE_RXCLEAR);
	// 送信
	WriteFile(hEncoderComm, &sendbuf, 1, &len, NULL);
	// バッファクリア
	memset(receive_data, 0x00, sizeof(receive_data));
	// 通信バッファクリア
	PurgeComm(hEncoderComm, PURGE_RXCLEAR);
	// Arduinoからデータを受信
	ReadFile(hEncoderComm, &receive_data, 2, &len, NULL);
	

	//初期化されていなければ初期化(初めのデータを捨てる)
	if (!isEncoderInitialized)
	{
		isEncoderInitialized = true;
		return;
	}

	leftCount += (signed char)receive_data[0];
	rightCount += (signed char)receive_data[1];
	//cout << "L:" << leftCount << ",R:" << rightCount << endl;
}

void DrivingFollowPath::sendDrivingCommand_count( Direction direction , int count)
{
	if ( count < 0) count *= -1;

	switch (direction)
	{
	case STOP:
		sendDrivingCommand(STOP);
		break;

	case FORWARD:
		sendDrivingCommand(FORWARD, count / 9.0 * 1000);
		break;

	case BACKWARD:
		sendDrivingCommand(BACKWARD,count / 3.125 * 1000);
		break;

	case RIGHT:
		sendDrivingCommand(RIGHT, count / 10.875 * 1000);
		break;

	case LEFT:
		sendDrivingCommand(LEFT, count / 10.25 * 1000);
		break;

	default:
		break;
	}
}

void DrivingFollowPath::sendDrivingCommand(Direction direction, int delay_int)
{
	int mode = 1;

	preDirection = nowDirection;
	nowDirection = direction;
	if(delay_int != 99999 && delay_int != 0)waittime = delay_int;

	switch (direction)
	{
	case STOP:
		mode = 0;
		DrivingControl::sendDrivingCommand(mode, 0, 0, delay_int);
		break;

	case FORWARD:
		DrivingControl::sendDrivingCommand(mode, -1000, 405, delay_int);
		break;

	case BACKWARD:
		DrivingControl::sendDrivingCommand(mode, 600, 509, delay_int);
		break;

	case RIGHT:
		DrivingControl::sendDrivingCommand(mode, -380, -1500, delay_int);
		break;

	case LEFT:
		DrivingControl::sendDrivingCommand(mode, 0, 1500, delay_int);
		break;

	default:
		break;
	}
}



// 外積で回転角を計算
void	DrivingFollowPath::calcRotationAngle()
{
	// 3点からベクトルを2つ用意
	int vector1_x, vector1_y;
	int vector2_x, vector2_y;

	vector1_x = x_now - x_old;
	vector1_y = y_now - y_old;

	vector2_x = x_next - x_now;
	vector2_y = y_next - y_now;

	// a×bと|a|,|b|を算出してarcsinで回転角を算出
	int det = vector1_x * vector2_y - vector1_y * vector2_x;
	double d1 = pow((double)(vector1_x*vector1_x + vector1_y*vector1_y),0.5);
	double d2 = pow((double)(vector2_x*vector2_x + vector2_y*vector2_y),0.5);
	radian = asin((double)det / (d1*d2));

	int inner = vector1_x * vector1_y + vector2_y * vector2_x;
	//radian = atan2(det, inner);

	orientation += radian;

	cout << "rad:" << radian << ", deg:" << radian / PI * 180 << endl;
	cout << "rad:" << orientation << ", deg:" << orientation / PI * 180 << endl;

	aimCount_L = (wheelDistance * radian) / (dDISTANCE * leftCoefficient); // Left
	aimCount_R = -(wheelDistance * radian) / (dDISTANCE * rightCoefficient); // Right
	if (aimCount_L) aimCount_L += abs(aimCount_L) / aimCount_L;
	if (aimCount_R) aimCount_R += abs(aimCount_R) / aimCount_R;

	//cout << "L:" << aimCount_L << ",R:" << aimCount_R << endl;

}

// 距離を計算
void	DrivingFollowPath::calcMovingDistance()
{
	double	x_disp = x_next - x_now;
	double	y_disp = y_next - y_now;

	distance = sqrt(x_disp*x_disp + y_disp*y_disp);

	cout << "distance[m]:" << distance * 0.05 << endl;

	aimCount_L = 50*distance / (dDISTANCE * leftCoefficient); // Left
	aimCount_R = 50*distance / (dDISTANCE * rightCoefficient); // Right

	//cout << "L:" << aimCount_L << ",R:" << aimCount_R << endl;

}

void DrivingFollowPath::waitDriveComplete()
{
	while (abs(leftCount) < abs(aimCount_L) && abs(rightCount) < abs(aimCount_R))
	{
		getEncoderCount();
	}
	leftCount = 0;
	rightCount = 0;
	sendDrivingCommand(STOP);
}

void DrivingFollowPath::restart(int time , Timer& timer )
{
	if(nowDirection != STOP) sendDrivingCommand(nowDirection, waittime - time);
	else sendDrivingCommand(preDirection, waittime - time);
	timer.getLapTime();
}

void DrivingFollowPath::checkEmergencyStop(Timer& timer)
{
	bool left = false;
	bool right = false;

	int time = timer.getLapTime(1, Timer::millisec, false) - 1000;
	if (time < 0) time = 0;
	/*
	cout << time << "millisec" << endl;
	cout << time * abs(aimCount_L) << "," << abs(leftCount) * waittime << endl;
	cout << leftCount << "," << rightCount << endl;
	cout << aimCount_L << "," << aimCount_R << endl;
	cout << waittime << endl;
    */
	

	if (((float)time + 1000) / (float)waittime * 100 > 98 ) return;

	if (time * abs(aimCount_L) > abs(leftCount) * waittime)     left = true;
	if (time * abs(aimCount_R) > abs(rightCount) * waittime)    right = true;

	if (left && right&& nowDirection != STOP && false)
	{
		cout << "非常停止してるかも" << endl;
		DrivingControl::sendDrivingCommand(1, 0, 0, 0);
		if (retLastRead){
			if (MessageBoxA(NULL, "もしかして非常停止してる？？\n動いてもいい？？", "もしかして！", MB_YESNO | MB_ICONSTOP) == IDYES)
                restart(time, timer);
		}
	}
	if (mUrgd.checkObstacle())
	{
		if(nowDirection != STOP) sendDrivingCommand(STOP);
		//if (MessageBoxA(NULL, "動いてもいい？？", "もしかしてなんか危ない？？", MB_YESNO | MB_ICONSTOP) == IDYES)  restart(time, timer);

		while (mUrgd.checkObstacle());
		restart(time, timer);
}
}

void DrivingFollowPath::waitDriveComplete_FF()
{
	cout << "Wait time [millisec]:" << waittime << endl;

	Timer waitDriveTimer;
	//Sleep(1000);
	waitDriveTimer.Start();
	
	while (waitDriveTimer.getLapTime(1, Timer::millisec, false) < waittime)
	{
		getEncoderCount();
		checkEmergencyStop(waitDriveTimer);
	}

	leftCount = 0;
	rightCount = 0;
}

void DrivingFollowPath::run_FF()
{
	getEncoderCount();

	char z = getchar();

	mUrgd.getAroundImage();

	while (getNextPoint())
	{
		cout << "回転" << endl;
		calcRotationAngle();
		if (aimCount_L > 0) sendDrivingCommand_count(RIGHT , aimCount_L);
		else sendDrivingCommand_count(LEFT, aimCount_L);
		waitDriveComplete_FF();
		Sleep(500);

		cout << "直進" << endl;
		calcMovingDistance();
		if (aimCount_L > 0) sendDrivingCommand_count(FORWARD, aimCount_L);
		else sendDrivingCommand_count(BACKWARD, aimCount_L);
		waitDriveComplete_FF();
		Sleep(500);
	}
}
void DrivingFollowPath::run()
{
	getEncoderCount();

	while (getNextPoint())
	{
		calcRotationAngle();
		if (aimCount_L > 0) sendDrivingCommand(RIGHT);
		else sendDrivingCommand(LEFT);
		cout << "回転" << endl;
		waitDriveComplete();
		Sleep(1000);

		calcMovingDistance();
		if (aimCount_L > 0) sendDrivingCommand(FORWARD);
		else sendDrivingCommand(BACKWARD);
		cout << "直進" << endl;
		waitDriveComplete();
		Sleep(1000);
	}
}

void DrivingFollowPath::setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG)
{
	mUrgd.setURGParam(URG_COM, URGPOS, NumOfURG);
}
void Manage2URG_Drive::setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG)
{
	urgdArray = new urg_driving[NumOfURG];
	for (int i = 0; i < NumOfURG; i++)
	{
		urgdArray[i].init(URG_COM[i], URGPOS[i]);
	}
}
Manage2URG_Drive::~Manage2URG_Drive()
{
	delete[] urgdArray;
}
urg_driving::ObstacleEmergency Manage2URG_Drive::checkObstacle()
{
	
	float* dataL[2] , *dataR[2];
	float adis = 0.0, bdis = 0.0;
	int count = 0;

	urgdArray[0].getObstacleData(dataR[0], dataR[1]);
	urgdArray[1].getObstacleData(dataL[0], dataL[1]);

	cout << "点L："<< dataR[0][0] << endl;
	cout << "点R："<< dataL[0][0] << endl;

    // ここに条件式
	for (int i = 0; i < dataR[0][0]; i++)
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
	}

	for (int i = 0; i < 2; i++) delete[] dataL[i];
	for (int i = 0; i < 2; i++) delete[] dataR[i];

	if (count > 10){
		return urg_driving::ObstacleEmergency::DETECT;
		//printf("点の数　= %d\n", count);
	}

	return urg_driving::ObstacleEmergency::NONE;

}
void Manage2URG_Drive::getAroundImage(int width, int height, int resolution,int measurementTimes)
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

			if (ideal_x < 1000.0 && ideal_y < 200.0 && ideal_y > -500.0)
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

			if (ideal_x < 1000.0 && ideal_y < 500.0 && ideal_y > -200.0)
			{
				data_x[datacount] = ideal_x;
				data_y[datacount] = ideal_y;
				datacount++;
			}
		}
	}

	data_x[0] = datacount-1;
	data_y[0] = datacount-1;
}