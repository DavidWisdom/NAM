#include "cv.h"
#include "tnam.h"
namespace CV
{
void CV::binaryConvertToMatrix(const cv::Mat& src, int**& matrix, int r, int c, std::string& log)
{
	std::stringstream output;
	if (src.empty())
	{
		output << "ͼƬ·����������Ҳ���ͼƬ" << "\n";
		output >> log;
		//assert(false);
		return;
	}
	assert(src.rows == src.cols);
	assert(src.rows == NAM::TNAM::size);
	assert(src.rows == r);
	//ȷ����ȡ��ͼƬ���ϸ�ʽҪ��
	assert(r == c); //ȷ������������������ͬ
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
		output << "ͼƬ·����������Ҳ���ͼƬ" << "\n";
		output >> log;
		//assert(false);
		return;
	}
	if (src.rows != src.cols || src.rows != NAM::TNAM::size || src.rows != r)
	{
		output << "��ȡ��ͼƬ�����ϸ�ʽҪ��" << '\n';
		output >> log;
		return;
	}
	if (src.rows != r)
	{
		output << "��ȡ��ͼƬ������������һ��" << '\n';
		output >> log;
		return;
	}
	//assert(src.rows == src.cols);
	//assert(src.rows == NAM::TNAM::size);
	//assert(src.rows == r);

	////ȷ����ȡ��ͼƬ���ϸ�ʽҪ��
	//assert(r == c); //ȷ������������������ͬ
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
