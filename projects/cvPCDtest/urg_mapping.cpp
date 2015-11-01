#include "urg_unko.h"

using namespace std;

PCImage urg_mapping::pcimage;


void urg_mapping::setWriteLine(bool isLine)
{
	pcimage.isWriteLine = isLine;
}

std::string	urg_mapping::getDirName()
{
	return pcimage.getDirname();
}
void urg_mapping::setPCDDir(std::string dirname)
{
	if (dirname == "") setDirName(getDirName());
	else setDirName(dirname);
}

void urg_mapping::initPCImage(PCImage& pci)
{
	pcimage = pci;
}
void urg_mapping::initPCImage(int width, int height, int resolution)
{
	pcimage.initPCImage(width, height, resolution);
}

void urg_mapping::setPCImageColor(PCImage::BGR bgr)
{
	pcimage.setColor(bgr);
}
void urg_mapping::writeMap(float& dist, float& old, float& rad)
{
	getData4URG(dist, old, rad);
	for (int i = 0; i < data_n; i++){
		if (pointpos[0][i] && pointpos[1][i])
			pcimage.writePoint(pointpos[0][i] / 1000, pointpos[1][i] / 1000, currentCoord_x / 1000, currentCoord_y / 1000);
	}
}