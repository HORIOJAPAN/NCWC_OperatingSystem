#include "DrivingControl.h"

const int ENCODER_COM = 10;
const int CONTROLLER_COM = 9;

void main()
{
	DrivingFollowPath DFP("../../data/route/test09.rt", 24.0086517664 / 1.005, 23.751783167, ENCODER_COM, CONTROLLER_COM);
	DFP.run_FF();

	cout << "complete" << endl;
}
