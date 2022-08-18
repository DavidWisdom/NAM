#ifndef CV_H
#define CV_H
#include <opencv2/opencv.hpp>
#include <string>
namespace CV {
class CV {
public:
	static void binaryConvertToMatrix(const cv::Mat& src, int**& matrix, int r, int c, std::string& log);
	static void binaryConvertToMatrix(const cv::Mat& src, std::vector<std::vector<int>>& matrix, int r, int c, std::string& log);
};
} //namespace CV
#endif //CV_H

