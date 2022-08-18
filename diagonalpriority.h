#ifndef DIAGONAL_PRIORITY_H
#define DIAGONAL_PRIORITY_H
#include "rnamc.h"
#include <mutex>
namespace NAM
{
class DiagonalPriority : public RNAMC {
public:
	static DiagonalPriority* getInstance();
	void diagonalPriority(const cv::Mat& img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
	void diagonalPriority(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
private:
	DiagonalPriority() = default;
	static DiagonalPriority* instance;
	static std::mutex mutex;
	Location findSameBlock(const cv::Mat*, const cv::Mat*, const cv::Mat*, const int&, const int&, const double&, const double&) override;
};
} //namespace NAM

#endif //DIAGONAL_PRIORITY_H
