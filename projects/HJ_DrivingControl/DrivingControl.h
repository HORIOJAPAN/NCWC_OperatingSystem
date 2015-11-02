#ifndef _INC_DRIVING_CONTROL_
#define _INC_DRIVING_CONTROL_

#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <Windows.h>

#include "../Timer/Timer.h"
#include "../SharedMemoryTESTpp/SharedMemory.h"
#include "../cvPCDtest/urg_unko.h"

using namespace std;

void getArduinoHandle(int arduinoCOM, HANDLE& hComm, int timeoutmillisec);

class DrivingControl
{
protected:
    // コントローラ系
	int		controllerCOM;
	HANDLE	hControllerComm;

    // シリアル送受信の結果
	bool retLastSend;
	bool retLastRead;

public:
    // COMポートを設定してハンドルを取得
	void setControllerCOM(int ctrlerCOM);

	// Arduinoへ駆動指令を送信
	void sendDrivingCommand(int mode_int, int forward_int, int  crosswise_int, int delay_int);
};

class urg_driving
	: public urg_mapping
{
public:
	enum ObstacleEmergency { NONE, DETECT };
	ObstacleEmergency checkObstacle();
	void getObstacleData(float* data_x , float* data_y);
};
class Manage2URG_Drive
{
private:
	urg_driving* urgdArray;
	cv::Mat tmTemplate;
public:
	~Manage2URG_Drive();

	void setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG);
	
    urg_driving::ObstacleEmergency checkObstacle();

	void getAroundImage(int width = 100 , int height = 100 , int resolution = 5 ,int measurementTimes = 10);

	/********************************************
    // ここで自己位置推定の処理を行うかな？
    *********************************************/
	void tMatching();
};

class DrivingFollowPath
	: public DrivingControl
{
private:
	// 経路データ読み取り用変数
	const string	fileName;			// 経路ファイル名
	const string	searchWord = ",";	// データの区切り識別用の","
	ifstream	ifs;					// ファイルストリーム
	string	str, x_str, y_str;		// データ読み取りに使用する変数
	string::size_type	x_pos, y_pos;

	// ベクトルを2つ使用する為3点保存する
	int	x_old, y_old;					// 1つ前の座標
	int x_now, y_now;					// 現在の座標
	int	x_next = 0, y_next = 0;			// 次の座標
    
	// 駆動指令計算用変数
	double	orientation;			// 現在向いている方位角(スタート直後を0として右向きが正)
	double	radian;					// 計算後の回転角
	double	distance;				// 計算後の移動距離

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
	int		aimCount_L, aimCount_R;

	// エンコーダからカウント数を取得して積算する
	void getEncoderCount();
	// Arduinoへ駆動指令を送信
	void sendDrivingCommand(Direction direction, int delay_int = 99999);
	void sendDrivingCommand_count(Direction direction, int count);
	// 指令した駆動の完了を待機
	void waitDriveComplete();
	void waitDriveComplete_FF();

	int waittime;
	Direction preDirection;
	Direction nowDirection;

	void checkEmergencyStop(Timer& timer);
	void restart(int time, Timer& timer);

	Manage2URG_Drive mUrgd;

public:
	// もろもろの初期化処理
	DrivingFollowPath(string fname, double coefficientL, double coefficientR, int arduioCOM, int ctrlrCOM);

	void setURGParam(int URG_COM[], float URGPOS[][4], int NumOfURG);

	// 次の点を読み込む
	bool getNextPoint();

	// 回転角を計算
	void	calcRotationAngle();
	// 距離を計算
	void	calcMovingDistance();

	void	run();
	void	run_FF();
};


#endif