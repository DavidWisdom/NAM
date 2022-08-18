#include "cv.h"
#include "tnam.h"
namespace CV
{
void CV::binaryConvertToMatrix(const cv::Mat& src, int**& matrix, int r, int c, std::string& log)
{
	std::stringstream output;
	if (src.empty())
	{
		output << "图片路径有误或者找不到图片" << "\n";
		output >> log;
		//assert(false);
		return;
	}
	assert(src.rows == src.cols);
	assert(src.rows == NAM::TNAM::size);
	assert(src.rows == r);
	//确保读取的图片符合格式要求
	assert(r == c); //确保矩阵行数和列数相同
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			if (src.at<uchar>(i, j) != 0 && src.at<uchar>(i, j) != 255)
			{
				assert(false);
			}
			matrix[i][j] = src.at<uchar>(i, j) / 255;
		}
	}
}

void CV::binaryConvertToMatrix(const cv::Mat& src, std::vector<std::vector<int>>& matrix, int r, int c, std::string& log)
{
	log.clear();
	std::stringstream output;
	if (src.empty())
	{
		output << "图片路径有误或者找不到图片" << "\n";
		output >> log;
		//assert(false);
		return;
	}
	if (src.rows != src.cols || src.rows != NAM::TNAM::size || src.rows != r)
	{
		output << "读取的图片不符合格式要求" << '\n';
		output >> log;
		return;
	}
	if (src.rows != r)
	{
		output << "读取的图片行数和列数不一致" << '\n';
		output >> log;
		return;
	}
	//assert(src.rows == src.cols);
	//assert(src.rows == NAM::TNAM::size);
	//assert(src.rows == r);

	////确保读取的图片符合格式要求
	//assert(r == c); //确保矩阵行数和列数相同
	for (int i = 0; i < src.rows; ++i)
	{
		for (int j = 0; j < src.cols; ++j)
		{
			if (src.at<uchar>(i, j) != 0 && src.at<uchar>(i, j) != 255)
			{
				assert(false);
			}
			matrix[i][j] = src.at<uchar>(i, j) / 255;
		}
	}
}
} //namespace CV
