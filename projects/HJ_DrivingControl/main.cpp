#include "DrivingControl.h"

const int ENCODER_COM = 10;
const int CONTROLLER_COM = 9;

void main()
{
	//URGのCOMポートを指定
	int URG_COM[] = { 27, 6 };

	//URGの位置を指定
	float urgPOS[][4] = { 20.0, 350.0, -280.0, 0.5236,
		20.0, 350.0, 280.0, -0.5236 };

	DrivingFollowPath DFP("../../data/route/test09.rt", 24.0086517664 / 1.005, 23.751783167, ENCODER_COM, CONTROLLER_COM);
	DFP.setURGParam(URG_COM, urgPOS, sizeof(URG_COM) / sizeof(int));
	DFP.run_FF();

	cout << "complete" << endl;
}
