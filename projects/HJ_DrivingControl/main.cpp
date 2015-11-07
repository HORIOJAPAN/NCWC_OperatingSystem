#include "DrivingControl.h"

const int ENCODER_COM = 10;
const int CONTROLLER_COM = 9;
const int ANDROID_COM = 29;

void main()
{
	//URGのCOMポートを指定
	int URG_COM[] = { 6, 27 };

	//URGの位置を指定
	float urgPOS[][4] = { 20.0, 350.0, -265.0, 0.5236,
		20.0, 350.0, 260.0, -0.5236 };

	DrivingFollowPath DFP("../../data/route/test08.rt", 24.00865177 , 24.03543307, ENCODER_COM, CONTROLLER_COM);
	//DrivingFollowPath DFP("../../data/route/test09.rt", 24.00865177, 24.03543307, ENCODER_COM, CONTROLLER_COM);
	DFP.setURGParam(URG_COM, urgPOS, sizeof(URG_COM) / sizeof(int));
	DFP.readMapImage("../../data/route/fieldMap4.jpg");
	DFP.setAndroidCOM(ANDROID_COM);
	DFP.run_FF();

	cout << "complete" << endl;
}
