#include "diagonalpriority.h"
namespace NAM
{
DiagonalPriority* DiagonalPriority::instance = nullptr;
std::mutex DiagonalPriority::mutex;
DiagonalPriority* DiagonalPriority::getInstance() { 
	if (instance == nullptr) {
		mutex.lock();
		if (instance == nullptr) {
			instance = new DiagonalPriority();
		}
		mutex.unlock();
	}
	return instance;
}

void DiagonalPriority::diagonalPriority(const cv::Mat& img, cv::Mat& dst, cv::Mat& seg, std::wstring& res) {
	diagonalPriority(&img, dst, seg, res);
}

void DiagonalPriority::diagonalPriority(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res) {
	rnamc(img, dst, seg, res, 10, 0);
}

RNAMC::Location DiagonalPriority::findSameBlock(const cv::Mat* img, const cv::Mat* markMatrix, const cv::Mat* r, const int& x1, const int& y1, const double& margin, const double& ratio)
{
	int x2(x1), y2(y1);
	while (x2 < img->cols && y2 < img->rows && (markMatrix->data + y1 * markMatrix->step)[x2] == 0 && (markMatrix->data + y2 * markMatrix->step)[x1] == 0) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin))
			break;
		x2++;
		y2++;
	}
	x2--;
	y2--;
	const int endX = x2;
	const int maxX = ratio == 0. ? INT_MAX : (y2 - y1 + 1) * ratio;
	while (x2 < img->cols && (x2 - x1 < maxX) && (markMatrix->data + y1 * markMatrix->step)[x2] == 0) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		x2++;
	}
	x2--;
	const int tempX = x2;
	const int tempY = y2;
	x2 = endX;
	const int maxY = ratio == 0. ? INT_MAX : (x2 - x1 + 1) * ratio;
	while (y2 < img->rows && (y2 - y1 < maxY)) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		y2 = y2 + 1;
	}
	y2--;
	if (((tempX - x1 + 1) * (tempY - y1 + 1) >= (x2 - x1 + 1) * (y2 - y1 + 1))) {
		x2 = tempX;
		y2 = tempY;
	}
	const Location loc(x1, y1, x2, y2);
	return loc;
}
} //namespace NAM
