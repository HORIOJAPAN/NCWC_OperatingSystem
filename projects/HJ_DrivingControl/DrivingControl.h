#ifndef _INC_DRIVING_CONTROL_
#define _INC_DRIVING_CONTROL_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>

#include "../Timer/Timer.h"
#include "../cvPCDtest/urg_unko.h"
#include "../HJ_ReceiveAndroidSensors/receiveAndroidSensors.h"

using namespace std;

#define PI 3.14159265359

// 直進中に角度補正する閾値
const int angleThresh = 15;

void getArduinoHandle(int arduinoCOM, HANDLE& hComm, int timeoutmillisec);

// 駆動指令の基本クラス
class DrivingControl
{
protected:
    // コントローラ系
	int		controllerCOM;
	HANDLE	hControllerComm;

    // シリアル送受信の結果
	bool retLastSend;
	bool retLastRead;
	unsigned long lastReadBytes;

public:
    // COMポートを設定してハンドルを取得
	void setControllerCOM(int ctrlerCOM);

	// Arduinoへ駆動指令を送信
	void sendDrivingCommand(int mode_int, int forward_int, int  crosswise_int, int delay_int);
};

// URGで駆動中の障害物検出を行うクラス
class urg_driving
	: public urg_mapping
{
public:
	enum ObstacleEmergency { NONE, DETECT };
	ObstacleEmergency checkObstacle();
	void getObstacleData(float*& data_x , float*& data_y);
};

// 左右のURGをまとめて管理するクラス
class Manage2URG_Drive
{
private:
	urg_driving* urgdArray  = NULL;
	cv::Mat tmMap;
	cv::Mat tmTemplate;
public:
	~Manage2URG_Drive();

	void setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG);
	void readMapImage(string mapName );
	
    urg_driving::ObstacleEmergency checkObstacle();

	void getAroundImage(int width = 300 , int height = 300 , int resolution = 5 ,int measurementTimes = 10);

	void tMatching(int& pos_x , int& pos_y , double& angle);
};

// 経路データを読み込んで駆動指令を行うやつ
class DrivingFollowPath
	: public DrivingControl
{
private:
	// 経路データ読み取り用変数
	const string	fileName;			// 経路ファイル名
	const string	searchWord = ",";	// データの区切り識別用の","
	ifstream	ifs;					// ファイルストリーム
	string	str, x_str, y_str , data_str;		// データ読み取りに使用する変数
	string::size_type	begin, end;

	// ベクトルを2つ使用する為3点保存する
	int	x_old, y_old;					// 1つ前の座標
	int x_now, y_now;					// 現在の座標
	int	x_next = 0, y_next = 0;			// 次の座標

	int doMatching;
    
	// 駆動指令計算用変数
	double	orientation;			// 現在向いている方位角(スタート直後を0として右向きが正)
	//double	radian;					// 計算後の回転角
	//double	distance;				// 計算後の移動距離

	const int wheelDistance = 530 / 2;	// タイヤ間距離の半分[mm]
	//const double dDISTANCE = 24.87094184; // 1カウント当たりの距離[mm](タイヤ径を72分割)
	const double dDISTANCE = 1; // 1カウント当たりの距離[mm](タイヤ径を72分割)

	const double leftCoefficient;
	const double rightCoefficient;

	// エンコーダの値関連
	int		encoderCOM;
	HANDLE	hEncoderComm;
	bool	isEncoderInitialized = false;
	int		leftCount, rightCount;

	// Arduinoへの駆動指令関連
	enum Direction	{ STOP, FORWARD, BACKWARD, RIGHT, LEFT };
	double		aimCount_L, aimCount_R;

	// Android関連
	float defaultOrientation[3];
	float nowOrientation[3];
	float dAzimuth; // 方位角の変位

	// エンコーダからカウント数を取得して積算する
	void getEncoderCount();
	// Arduinoへ駆動指令を送信
	void sendDrivingCommand(Direction direction, int delay_int = 99999);
	void sendDrivingCommand_count(Direction direction, int count);
	// 指令した駆動の完了を待機
	void waitDriveComplete();
	void waitDriveComplete_FF();

	int waittime;
	int overdelayCount;
	Direction preDirection;
	Direction nowDirection;

	void checkEmergencyStop(Timer& timer);
	void restart(int time, Timer& timer,int encoderLRtmp[]);

	Manage2URG_Drive mUrgd;
	rcvAndroidSensors rcvDroid;

public:
	// もろもろの初期化処理
	DrivingFollowPath(string fname, double coefficientL, double coefficientR, int arduioCOM, int ctrlrCOM);

	// Manage2URG_Driveクラス関連
	void setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG);
	void readMapImage(string mapName);

	// rcvAndroidSensorsクラス関連
	void setAndroidCOM(int comport);

	// 次の点を読み込む
	bool getNextPoint();

	// 回転角を計算
	double	calcRotationAngle( int nowCoord_x = -99999 , int nowCoord_y = -99999 );
	void	sendRotation(double radian);
	// 距離を計算
	double	calcMovingDistance(int nowCoord_x = -99999, int nowCoord_y = -99999);
	void	sendStraight(double distance);
	// 現在地を算出
	void	calcNowCoord(int time, int nowCoord[2]);
	void	calcNowCoord(int time);

	void	run();
	void	run_FF();
};


#endif