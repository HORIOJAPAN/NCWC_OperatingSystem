#include "DrivingControl.h"

const int ENCODER_COM = 9;
const int CONTROLLER_COM = 4;
const int ANDROID_COM = 1;

void main()
{
	//URG��COM�|�[�g���w��
	int URG_COM[] = { 23, 24 };
	

	//URG�̈ʒu���w��
	float urgPOS[][4] = { 20.0, 350.0, -265.0, 0.5236,
		20.0, 350.0, 260.0, -0.5236 };

	DrivingFollowPath DFP("../../data/route/unko.rt", 24.00865177 , 24.03543307, ENCODER_COM);
	//DrivingFollowPath DFP("../../data/route/test09.rt", 24.00865177, 24.03543307, ENCODER_COM, CONTROLLER_COM);
	DFP.setURGParam(URG_COM, urgPOS, sizeof(URG_COM) / sizeof(int));
	DFP.readMapImage("../../data/route/trial_5.jpg");
	//DFP.setAndroidCOM(ANDROID_COM);
	DFP.run_FF();

	Sleep(5000);

	Spur_free();

	cout << "complete" << endl;
}
