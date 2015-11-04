/*
 *	経路情報のテキストファイル(拡張子.rt)を上から順に読み込んで移動距離，回転を計算し，
 *	シリアル通信で駆動指令を送信する．
 */
#include "DrivingControl.h"

/*
*	概要:
*		Arduinoとシリアル通信を行うためのハンドルを取得する
*	引数：
*		int arduinoCOM	COMポート番号
*		HANDLE&	hComm	ハンドル変数への参照
*		int timeoutmillisec	通信のタイムアウトまでの時間
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
// コントローラへのシリアルポートのハンドルを取得
void DrivingControl::setControllerCOM(int ctrlerCOM)
{
	this->controllerCOM = ctrlerCOM;
	getArduinoHandle(controllerCOM, hControllerComm, 500);
}
// 規定のフォーマットに従ってコントローラにコマンドを送信
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

