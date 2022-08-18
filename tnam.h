#ifndef TNAM_H
#define TNAM_H
#include "tnammath.h"
#include "cv.h"
#include <opencv2/opencv.hpp>
namespace NAM {
class TNAM : protected TNAMMath {
public:
	static int n;
	static int size;
	static size_t num_of_total_triangular;
	static size_t num_of_upper_triangular;
	static size_t num_of_lower_triangular;
	static size_t num_of_black_nodes;
	static size_t num_of_lines;
	static size_t num_of_points;
	static size_t num_of_rectangle;
	static size_t num_of_total_rectangle;
	static size_t num_of_total_mix;
	static double triangular_ratio;
	static void encode_tri_and_square(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n = 1);
	static void encode_square(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n = 1);
	static void encode_tri(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n = 1);
	static void encode(int**& matrix, const int& rows, const int& cols, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, int step_n = 1);
	static void decode(cv::Mat& dst, cv::Mat& seg, const std::vector<std::vector<int>>& q_tri, const std::vector<std::vector<int>>& q_line, const std::vector<std::vector<int>>& q_point, const std::vector<std::vector<int>>& q_rect, std::vector<std::vector<int>>& res);
};
} //namespace NAM

#endif //TNAM_H
