#include "DrivingControl.h"

const int ENCODER_COM = 3;
const int CONTROLLER_COM = 12;
const int ANDROID_COM = 0;

void main()
{
	//URGのCOMポートを指定
	int URG_COM[] = { 4 };

	//URGの位置を指定
	float urgPOS[][4] = { 430.0, 0.0, 265.0, 0.0 };
	time_t work_time=time(NULL);
	struct tm *t_st;
	char scan_time[40];
	const string FMNAME_scan_t = "testmap_scan_t";	//共有ファイル名

	SharedMemory<char> shMem_scan_t(FMNAME_scan_t);
	
	strftime(scan_time, sizeof(scan_time), "%Y_%m%d_%H%M", localtime(&work_time));
	printf("%s\n",scan_time);
	shMem_scan_t.setShMemData(sizeof(scan_time) / sizeof(char), 0);
	for (int i = 0; i < sizeof(scan_time)/sizeof(char);i++)
	shMem_scan_t.setShMemData(scan_time[i],i+1);

	
	DrivingFollowPath DFP("../../data/守田実験ROUTE/20160830/0_0.jpg.rt", 24.00865177 , 24.03543307, ENCODER_COM, CONTROLLER_COM);
	//DrivingFollowPath DFP("../../data/route/test09.rt", 24.00865177, 24.03543307, ENCODER_COM, CONTROLLER_COM);
	DFP.setURGParam(URG_COM, urgPOS, sizeof(URG_COM) / sizeof(int));
	DFP.readMapImage("../../data/守田実験ROUTE/20160830/0_0.jpg.jpg");
	DFP.setAndroidCOM(ANDROID_COM);
	DFP.run_FF();

	cout << "complete" << endl;
}

