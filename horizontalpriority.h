#ifndef HORIZONTAL_PRIORITY_H
#define HORIZONTAL_PRIORITY_H
#include "rnamc.h"
#include <mutex>
namespace NAM
{
class HorizontalPriority final : public RNAMC {
public:
	static HorizontalPriority* getInstance();
	void horizontalPriority(const cv::Mat& img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
	void horizontalPriority(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
private:
	HorizontalPriority() = default;
	static HorizontalPriority* instance;
	static std::mutex mutex;
	RNAMC::Location findSameBlock(const cv::Mat*, const cv::Mat*, const cv::Mat*, const int&, const int&, const double&, const double&) override;
};
} //namespace NAM
#endif //HORIZONTAL_PRIORITY_H

