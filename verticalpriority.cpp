#include "verticalpriority.h"
namespace NAM
{
VerticalPriority* VerticalPriority::instance = nullptr;
std::mutex VerticalPriority::mutex;
VerticalPriority* VerticalPriority::getInstance() {
	if (instance == nullptr) {
		mutex.lock();
		if (instance == nullptr) {
			instance = new VerticalPriority();
		}
		mutex.unlock();
	}
	return instance;
}

void VerticalPriority::verticalPriority(const cv::Mat& img, cv::Mat& dst, cv::Mat& seg, std::wstring& res)
{
	verticalPriority(&img, dst, seg, res);
}

void VerticalPriority::verticalPriority(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res)
{
	rnamc(img, dst, seg, res, 20, 0);
}

RNAMC::Location VerticalPriority::findSameBlock(const cv::Mat* img, const cv::Mat* markMatrix, const cv::Mat* r, const int& x1, const int& y1, const double& margin, const double& ratio)
{
	int x2(x1), y2(y1);
	while (x2 < img->cols && (markMatrix->data + y1 * markMatrix->step)[x2] == 0) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		x2++;
	}
	x2--;
	const int maxY = ratio == 0. ? INT_MAX : (x2 - x1 + 1) * ratio;
	while (y2 < img->rows && ((y2 - y1) < maxY)) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		y2 = y2 + 1;
	}
	y2--;
	if (ratio != 0.) {
		if ((x2 - x1 + 1) > (y2 - y1 + 1) * ratio) {
			x2 = (y2 - y1 + 1) * ratio + x1 - 1;
		}
	}
	const int tempX2 = x2;
	const int tempY2 = y2;
	x2 = x1;
	y2 = y1;
	while (y2 < img->rows && (markMatrix->data + y2 * markMatrix->step)[x1] == 0) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		y2++;
	}
	y2--;
	int maxX = ratio == 0. ? INT_MAX : (y2 - y1 + 1) * ratio;
	while (x2 < img->cols && (markMatrix->data + y1 * markMatrix->step)[x2] == 0 && ((x2 - x1) < maxX)) {
		if (!isSameBlock(img, x1, y1, x2, y2, margin)) {
			break;
		}
		x2++;
	}
	x2--;
	if (ratio != 0.) {
		if ((y2 - y1 + 1) > (x2 - x1 + 1) * ratio) {
			y2 = (x2 - x1 + 1) * ratio + y1 - 1;
		}
	}
	if ((tempX2 - x1 + 1) * (tempY2 - y1 + 1) > (x2 - x1 + 1) * (y2 - y1 + 1))
	{
		x2 = tempX2;
		y2 = tempY2;
	}
	const Location loc(x1, y1, x2, y2);
	return loc;
}
} //namespace NAM
