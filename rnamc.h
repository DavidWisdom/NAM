#ifndef RNAMC_H
#define RNAMC_H
#include <vector>
#include <opencv2/opencv.hpp>
#include <sstream>
#include <string>
namespace NAM
{
class RNAMC {
protected:
	RNAMC() {}
	virtual ~RNAMC() {}
	struct Location
	{
		int x1;
		int y1;
		int x2;
		int y2;
		Location(int xa, int ya, int xb, int yb): x1(xa), y1(ya), x2(xb), y2(yb) {}
	};
	struct ColorNode
	{
		int kind;
		int g1;
		int g2;
		int g3;
		int g4;
		ColorNode(int k, int gg1, int gg2 = -1, int gg3 = -1, int gg4 = -1) : kind(k), g1(gg1), g2(gg2), g3(gg3), g4(gg4) {}
	};
	void rnamc(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res, const int& margin, const int& ratio);
	double bpp(const std::vector<ColorNode>&, const int&, const int&, const std::vector<char>&) const;
	void encode(const cv::Mat*, const int&, const int&, std::vector<char>&) const;
	void decode(const cv::Mat*, const int&, const int&, const std::vector<char>&) const;
	bool isSameBlock(const cv::Mat*, const int&, const int&, const int&, const int&, const int&) const;
	virtual Location findSameBlock(const cv::Mat*, const cv::Mat*, const cv::Mat*, const int&, const int&, const double&, const double&) = 0;
	double psnr(const cv::Mat*, const cv::Mat*) const;
	void restoreImage(cv::Mat*, cv::Mat*, cv::Mat*, const std::vector<ColorNode>&, const int&, const int&);
	void restoreImageValue(cv::Mat*, ColorNode, const int&, const int&, const int&, const int&);
	void setMarkMatrix(const cv::Mat*, const int&, const int&, const int&, const int&, const int&) const;
	void startNamCut(const cv::Mat*, const cv::Mat*, const cv::Mat*, std::vector<ColorNode>&, std::vector<Location>&, const int&, const int&, const double&, int&, const double&);
};	
} //namespace NAM
#endif //RNAMC_H