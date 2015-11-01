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
