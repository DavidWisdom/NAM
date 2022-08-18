#ifndef VERTICAL_PRIORITY_H
#define VERTICAL_PRIORITY_H
#include "rnamc.h"
#include <mutex>
namespace NAM
{
class VerticalPriority final : public RNAMC {
public:
	static VerticalPriority* getInstance();
	void verticalPriority(const cv::Mat& img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
	void verticalPriority(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res);
private:
	VerticalPriority() = default;
	static VerticalPriority* instance;
	static std::mutex mutex;
	RNAMC::Location findSameBlock(const cv::Mat*, const cv::Mat*, const cv::Mat*, const int&, const int&, const double&, const double&) override;
};
} //namespace NAM

#endif //VERTICAL_PRIORITY_H
