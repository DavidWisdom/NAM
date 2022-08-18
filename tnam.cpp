#include "tnam.h"
#include <algorithm>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <stack>
namespace NAM
{
int TNAM::n = 8;
int TNAM::size = 256;
size_t TNAM::num_of_total_triangular = 0;
size_t TNAM::num_of_upper_triangular = 0;
size_t TNAM::num_of_lower_triangular = 0;
size_t TNAM::num_of_black_nodes = 0;
size_t TNAM::num_of_lines = 0;
size_t TNAM::num_of_points = 0;
size_t TNAM::num_of_rectangle = 0;
size_t TNAM::num_of_total_rectangle = 0;
size_t TNAM::num_of_total_mix = 0;
double TNAM::triangular_ratio = 0;
void TNAM::encode_square(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n)
{
	num_of_total_triangular = 0;
	num_of_upper_triangular = 0;
	num_of_lower_triangular = 0;
	num_of_black_nodes = 0;
	num_of_lines = 0;
	num_of_points = 0;
	num_of_rectangle = 0;
	num_of_total_rectangle = 0;
	num_of_total_mix = 0;
	triangular_ratio = 0;
	q_tri.clear();
	q_line.clear();
	q_point.clear();
	//q_square.clear();
	q_rect.clear();
	std::ofstream tri("q_tri.txt");
	std::ofstream line("q_line.txt");
	std::ofstream point("q_point.txt");
	std::ofstream square("q_square.txt");
	std::ofstream rect("q_rect.txt");
	std::ofstream ofs("matrix.txt");
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			ofs << matrix[i][j] << " ";
		}
		ofs << '\n';
	}
	assert(size == static_cast<int>(matrix.size()));
	std::vector<std::vector<int>> f(256, std::vector<int>(256, 0));
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			f[j][i] = matrix[i][j];
		}
	}
	bool isCurrentNull0 = true;
	bool isCurrentNull1 = true;
	bool isCurrentNull2 = true;
	bool isCurrentNull3 = true;
	bool isCurrentNull4 = true;
	//srand(time(NULL));
	int cnt = 0;
	for (int x = 1; x <= size - 1; x += 1)
	{
		//int n = rand() % 3;
		for (int y = 1; y <= size - 1; y += 1)
		{
			 for (int step = size - 1; step >= 1; step -= step_n)
			 {
			 	// if (x + step <= size)
			 	// {
			 	// 	bool k1 = false;
			 	// 	bool k2 = false;
			 	// 	bool k3 = false;
			 	// 	// recu(matrix, x - 1, x + step - 1, y - 1, size - 1, isCurrentNull0);
			 	// 	// if (isCurrentNull0)
			 	// 	// {
			 	// 	// 	for (int i = 1; i <= step + 1; ++i) {
			 	// 	// 		for (int j = 1; j <= size - y + 1; ++j) {
			 	// 	// 			matrix[i + x - 2][j + y - 2] = 8;
			 	// 	// 		}
			 	// 	// 	}
			 	// 	// }
			 	// }
			 	if (x + step <= size && y + step <= size) {
			 		bool k1 = false;
			 		bool k2 = false;
			 		bool k3 = false;
			 		bool k4 = false;
			 		triu(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull1);
			 		// if (isCurrentNull1) {
			 		// 	num_of_upper_triangular++;
			 		// 	num_of_total_triangular++;
			 		// 	k1 = true;
			 		// }
			 		tril(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull2);
			 		// triu(f, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull3);
			 		// tril(f, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull4);
			 		// if (isCurrentNull2) {
			 		// 	num_of_lower_triangular++;
			 		// 	num_of_total_triangular++;
			 		// 	k2 = true;
			 		// }
			 		if (isCurrentNull1 && isCurrentNull2) {
			 			//k1 = true;
			 			//k2 = true;
			 			num_of_rectangle++;
			 			num_of_total_rectangle++;
			 			const int x1_abs = x;
			 			const int y1_abs = y;
			 			const int x2_abs = x + step;
			 			const int y2_abs = step + y;
			 			q_rect.push_back({ x1_abs, y1_abs, step, step });
			 			rect << x1_abs << ' ' << y1_abs << ' ' << step << '\n';
			 			for (int i = 1; i <= step + 1; ++i) {
			 				for (int j = 1; j <= step + 1; ++j) {
			 					matrix[i + x - 2][j + y - 2] = 8;
			 				}
			 			}
			 		}
			 		// if (!cnt) {
			 		// 	cnt = 1; continue;
			 		// }
			 		// }
			 		// else
			 		// {
			 		// if (isCurrentNull1) {
			 		// 	num_of_upper_triangular++;
			 		// 	num_of_total_triangular++;
			 		// 	k1 = true;
			 		// }
			 		// if (isCurrentNull2) {
			 		// 	num_of_lower_triangular++;
			 		// 	num_of_total_triangular++;
			 		// 	k2 = true;
			 		// }
			 		// //
			 		// if (k1)
			 		// {
			 		// 	const int x1_abs = x;
			 		// 	const int y1_abs = y;
			 		// 	const int x2_abs = step + x;
			 		// 	const int y2_abs = step + y;
			 		// 	q_tri.push_back({ x1_abs, y1_abs, step });
			 		// 	tri << x1_abs << ' ' << y1_abs << ' ' << step << '\n';
			 		// 	//q_tri.push_back({ x2_abs, y1_abs, -step });
			 		// 	//q_tri.push_back({ 0, x1_abs, y1_abs, x2_abs, y2_abs });
			 		// 	//tri << 0 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
			 		// 	for (int i = 1; i <= step + 1; ++i)
			 		// 	{
			 		// 		for (int j = i; j <= step + 1; ++j)
			 		// 		{
			 		// 			matrix[i + x - 2][j + y - 2] = 8;
			 		// 		}
			 		// 	}
			 		// }
			 		// if (k2)
			 		// {
			 		// 	const int x1_abs = x;
			 		// 	const int y1_abs = y;
			 		// 	const int x2_abs = step + x;
			 		// 	const int y2_abs = step + y;
			 		// 	//std::vector<int> tri = { x1_abs, y2_abs, step };
			 		// 	q_tri.push_back({ x2_abs,y2_abs,-step });
			 		// 	tri << x2_abs << ' ' << y2_abs << ' ' << -step << '\n';
			 		// 	//q_tri.push_back({ 1, x1_abs, y1_abs, x2_abs, y2_abs });
			 		// 	//tri << 1 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
			 		// 	for (int i = 1; i <= step + 1; ++i)
			 		// 	{
			 		// 		for (int j = 1; j <= i; ++j)
			 		// 		{
			 		// 			matrix[i + x - 2][j + y - 2] = 9;
			 		// 		}
			 		// 	}
			 		//}
			 	}
			}
		}
	}
	// num_of_total_rectangle += num_of_rectangle;
	int length0 = 1;
	int width0 = 1;
	for (int x = 1; x <= size; ++x)
	{
		for (int y = 1; y <= size; ++y)
		{
			int sp_x = x;
			int sp_y = y;
			if (matrix[x - 1][y - 1] == 0)
			{
				int length = 1;
				int width = 1;
				int maxLength = 1;
				int maxWidth = 1;
				int maxArea = 0;
				int last = 0;
				for (int j = y; j <= size; ++j)
				{
					length0 = 0;
					for (int k = x; k <= size; ++k)
					{
						if (j != y && (k - sp_x + 1 > last))
						{
							break;
						}
						if (matrix[k - 1][j - 1] != 0)
						{
							break;
						}
						length0++;
					}
					if (j == y || length0 < last)
					{
						last = length0;
					}
					if (matrix[x - 1][j - 1] != 0)
					{
						break;
					}
					width0++;
					int area = last * (j - sp_y + 1);
					length = last;
					width = j - sp_y + 1;
					if (area > maxArea)
					{
						maxArea = area;
						maxLength = last;
						maxWidth = j - sp_y + 1;
					}
				}
				if (maxLength * maxWidth == 1)
				{
					num_of_points++;
					q_point.push_back({ x, y, maxLength, maxWidth });
					point << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				else
				{
					num_of_lines++;
					q_line.push_back({ x, y, maxLength, maxWidth });
					line << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				++num_of_black_nodes;
				for (int a = x; a <= x + maxLength - 1; ++a)
				{
					for (int b = y; b <= y + maxWidth - 1; ++b)
					{
						matrix[a - 1][b - 1] = 7;
					}
				}
			}
		}
	}
	//num_of_total_rectangle += num_of_black_nodes;
	num_of_total_rectangle += num_of_lines;
	num_of_total_mix = num_of_total_rectangle + num_of_total_triangular;
	triangular_ratio = pow(4, n) / static_cast<double>(num_of_points * n + num_of_lines * 2 * n + num_of_total_triangular * static_cast<size_t>(2 * n + 1));
	// std::cout << "upper_triangular:" << num_of_upper_triangular << "\n";
	// std::cout << "lower_triangular:" << num_of_lower_triangular << "\n";
	// std::cout << "total_triangular:" << num_of_total_triangular << "\n"; //三角形子模式数量
	// std::cout << "line_num:" << num_of_lines << "\n"; //单线段子模式数量
	// std::cout << "point_num:" << num_of_points << "\n"; //孤立点子模式数量
	// std::cout << "black_node:" << num_of_black_nodes << "\n";
	// std::cout << "num_of_total_rectangle:" << num_of_total_rectangle << "\n";
	// std::cout << "num_of_total_mix:" << num_of_total_mix << "\n";
	// std::cout << "triangular_ratio:" << triangular_ratio << "\n";
	tri.close();
	// std::cout << "q_tri数组的信息已成功存储到q_tri.txt文件中" << "\n";
	line.close();
	// std::cout << "q_line数组的信息已成功存储到q_line.txt文件中" << "\n";
	point.close();
	// std::cout << "q_point数组的信息已成功存储到q_point.txt文件中" << "\n";
	square.close();
	rect.close();
}
int left[300][300];
int mat[300][300];
void TNAM::encode_tri_and_square(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n)
{
	using std::fstream;
	fstream olog;
	olog.open("olog.txt", std::ios::out);
	num_of_total_triangular = 0;
	num_of_upper_triangular = 0;
	num_of_lower_triangular = 0;
	num_of_black_nodes = 0;
	num_of_lines = 0;
	num_of_points = 0;
	num_of_rectangle = 0;
	num_of_total_rectangle = 0;
	num_of_total_mix = 0;
	triangular_ratio = 0;
	q_tri.clear();
	q_line.clear();
	q_point.clear();
	//q_square.clear();
	q_rect.clear();
	std::ofstream tri("q_tri.txt");
	std::ofstream line("q_line.txt");
	std::ofstream point("q_point.txt");
	std::ofstream square("q_square.txt");
	std::ofstream rect("q_rect.txt");
	std::ofstream ofs("matrix.txt");
	memset(mat, 0, sizeof(mat));
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			ofs << matrix[i][j] << " ";
			mat[i][j] = matrix[i][j];
		}
		ofs << '\n';
	}
	assert(size == static_cast<int>(matrix.size()));
	std::vector<std::vector<int>> f(256, std::vector<int>(256, 0));
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			f[j][i] = matrix[i][j];
		}
	}
	bool isCurrentNull0 = true;
	bool isCurrentNull1 = true;
	bool isCurrentNull2 = true;
	bool isCurrentNull3 = true;
	bool isCurrentNull4 = true;
	//srand(time(NULL));
	int cnt = 0;
	int ret = 0;
	int point1_x = -1;
	int point1_y = -1;
	int point2_x = -1;
	int point2_y = -1;
	int idx = 0;
	while (true) {		
		++idx;
		olog << idx << '\n';
		olog.close();
		olog.open("olog.txt", std::ios::app);
		if (idx > 5) {
			break;
		}
		bool tag = false;
		memset(left, 0, sizeof(left));
		ret = 0;
		for (int i = 1; i < size; ++i) {
			for (int j = 1; j < size; ++j) {
				if (mat[i][j] == 0) {
					if (j == 1) {
						left[i][j] = 1;
					}
					else {
						left[i][j] = left[i][j - 1] + 1;
					}
					tag = true;
				}
			}
		}
		olog.close();
		olog.open("olog.txt", std::ios::app);
		if (tag == false) break;
		for (int j = 1; j < size; ++j) {
			std::vector<int> up(size, 0);
			std::vector<int> down(size, 0);
			std::stack<int> stk;
			for (int i = 1; i < size; i++) {
				while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
					stk.pop();
				}
				up[i] = stk.empty() ? -1 : stk.top();
				stk.push(i);
			}
			stk = std::stack<int>();
			for (int i = size - 1; i >= 1; i--) {
				while (!stk.empty() && left[stk.top()][j] >= left[i][j]) {
					stk.pop();
				}
				down[i] = stk.empty() ? size : stk.top();
				stk.push(i);
			}
			for (int i = 1; i < size; i++) {
				int height = down[i] - up[i] - 1;
				int area = height * left[i][j];
				if (area > ret) {
					ret = area;
					point1_x = i;
					point1_y = j - left[i][j] + 1;
					point2_x = i + height - 1;
					point2_y = j;
				}
			}
		}
		if (ret < 16) {
			break;
		}
		else {
			olog << point1_x << " " << point1_y << " " << point2_x << " " << point2_y << '\n';
			q_rect.push_back({ point1_x + 1, point1_y + 1, point2_x - point1_x, point2_y - point1_y});
			num_of_total_rectangle++;
			for (int i = point1_x; i <= point2_x; ++i) {
				for (int j = point1_y; j <= point2_y; ++j) {
					mat[i][j] = 8;
					matrix[i][j] = 8;
				}
			}
		}
	}
	for (int x = 1; x <= size - 1; x += 1)
	{
		//int n = rand() % 3;
		for (int y = 1; y <= size - 1; y += 1)
		{
			int step1 = 0;
			int step2 = 0;
			isCurrentNull1 = true;
			isCurrentNull2 = true;
			for (int step = size - 1; step >= 1; step -= step_n)
			{
				if (x + step <= size && y + step <= size)
				{
					triu(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull1);
					if (isCurrentNull1)
					{
						step1 = step;
						break;
					}
				}
			}

			for (int step = size - 1; step >= 1; step -= step_n)
			{
				if (x + step <= size && y + step <= size)
				{
					tril(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull2);
					if (isCurrentNull2)
					{
						step2 = step;
						break;
					}
				}
			}

			if (step1 != 0 && step2 != 0)
			{
				if (step1 == step2)
				{
					//num_of_rectangle++;
					//num_of_total_rectangle++;
					const int x1_abs = x;
					const int y1_abs = y;
					const int x2_abs = x + step1;
					const int y2_abs = step1 + y;
					q_rect.push_back({ x1_abs, y1_abs, step1, step1 });
					num_of_total_rectangle++;
					rect << x1_abs << ' ' << y1_abs << ' ' << step1 << '\n';
					for (int i = 1; i <= step1 + 1; ++i) {
						for (int j = 1; j <= step1 + 1; ++j) {
							matrix[i + x - 2][j + y - 2] = 8;
						}
					}
				}
				else
				{
					q_rect.push_back({ x, y, step2, step1 });
					num_of_total_rectangle++;
					const int x1_abs = x;
					const int y1_abs = y;
					const int flag1 = step2;
					const int flag2 = step1;
					for (int i = x1_abs; i <= x1_abs + flag1; ++i)
					{
						for (int j = y1_abs; j <= y1_abs + flag2; ++j)
						{
							//res[i - 1][j - 1] = 0;
							matrix[i - 1][j - 1] = 8;
						}
					}
				}
				//++num_of_total_triangular;
			}
			else if (step1 != 0)
			{
				//++num_of_upper_triangular;
				//++num_of_total_triangular;
				const int x1_abs = x;
				const int y1_abs = y;
				const int x2_abs = step1 + x;
				const int y2_abs = step1 + y;
				q_tri.push_back({ x1_abs, y1_abs, step1 });
				//num_of_total_rectangle++;
				num_of_total_triangular++;
				tri << x1_abs << ' ' << y1_abs << ' ' << step1 << '\n';
				//q_tri.push_back({ x2_abs, y1_abs, -step });
				//q_tri.push_back({ 0, x1_abs, y1_abs, x2_abs, y2_abs });
				//tri << 0 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
				for (int i = 1; i <= step1 + 1; ++i) {
					for (int j = i; j <= step1 + 1; ++j)
					{
						matrix[i + x - 2][j + y - 2] = 8;
					}
				}
			}
			else if (step2 != 0)
			{
				//++num_of_lower_triangular;
				//++num_of_total_triangular;
				const int x1_abs = x;
				const int y1_abs = y;
				const int x2_abs = step2 + x;
				const int y2_abs = step2 + y;
				//std::vector<int> tri = { x1_abs, y2_abs, step };
				q_tri.push_back({ x2_abs,y2_abs,-step2 });
				//num_of_total_rectangle++;
				num_of_total_triangular++;
				tri << x2_abs << ' ' << y2_abs << ' ' << -step2 << '\n';
				//q_tri.push_back({ 1, x1_abs, y1_abs, x2_abs, y2_abs });
				//tri << 1 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
				for (int i = 1; i <= step2 + 1; ++i)
				{
					for (int j = 1; j <= i; ++j)
					{
						matrix[i + x - 2][j + y - 2] = 9;
					}
				}
			}
		}
	}
	// num_of_total_rectangle += num_of_rectangle;
	int length0 = 1;
	int width0 = 1;
	for (int x = 1; x <= size; ++x)
	{
		for (int y = 1; y <= size; ++y)
		{
			int sp_x = x;
			int sp_y = y;
			if (matrix[x - 1][y - 1] == 0)
			{
				int length = 1;
				int width = 1;
				int maxLength = 1;
				int maxWidth = 1;
				int maxArea = 0;
				int last = 0;
				for (int j = y; j <= size; ++j)
				{
					length0 = 0;
					for (int k = x; k <= size; ++k)
					{
						if (j != y && (k - sp_x + 1 > last))
						{
							break;
						}
						if (matrix[k - 1][j - 1] != 0)
						{
							break;
						}
						length0++;
					}
					if (j == y || length0 < last)
					{
						last = length0;
					}
					if (matrix[x - 1][j - 1] != 0)
					{
						break;
					}
					width0++;
					int area = last * (j - sp_y + 1);
					length = last;
					width = j - sp_y + 1;
					if (area > maxArea)
					{
						maxArea = area;
						maxLength = last;
						maxWidth = j - sp_y + 1;
					}
				}
				if (maxLength * maxWidth == 1)
				{
					num_of_points++;
					q_point.push_back({ x, y, maxLength, maxWidth });
					point << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				else
				{
					num_of_lines++;
					q_line.push_back({ x, y, maxLength, maxWidth });
					line << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				++num_of_black_nodes;
				for (int a = x; a <= x + maxLength - 1; ++a)
				{
					for (int b = y; b <= y + maxWidth - 1; ++b)
					{
						matrix[a - 1][b - 1] = 7;
					}
				}
			}
		}
	}
	//num_of_total_rectangle += num_of_black_nodes;
	num_of_total_rectangle += num_of_lines;
	num_of_total_mix = num_of_total_rectangle + num_of_total_triangular;
	triangular_ratio = pow(4, n) / static_cast<double>(num_of_points * n + num_of_lines * 2 * n + num_of_total_triangular * static_cast<size_t>(2 * n + 1));
	// std::cout << "upper_triangular:" << num_of_upper_triangular << "\n";
	// std::cout << "lower_triangular:" << num_of_lower_triangular << "\n";
	// std::cout << "total_triangular:" << num_of_total_triangular << "\n"; //三角形子模式数量
	// std::cout << "line_num:" << num_of_lines << "\n"; //单线段子模式数量
	// std::cout << "point_num:" << num_of_points << "\n"; //孤立点子模式数量
	// std::cout << "black_node:" << num_of_black_nodes << "\n";
	// std::cout << "num_of_total_rectangle:" << num_of_total_rectangle << "\n";
	// std::cout << "num_of_total_mix:" << num_of_total_mix << "\n";
	// std::cout << "triangular_ratio:" << triangular_ratio << "\n";
	tri.close();
	// std::cout << "q_tri数组的信息已成功存储到q_tri.txt文件中" << "\n";
	line.close();
	// std::cout << "q_line数组的信息已成功存储到q_line.txt文件中" << "\n";
	point.close();
	// std::cout << "q_point数组的信息已成功存储到q_point.txt文件中" << "\n";
	square.close();
	rect.close();
	//num_of_total_rectangle = q_rect.size();
	//num_of_total_triangular = q_tri.size() + q_line.size();
	//num_of_points = q_point.size();
}
void TNAM::encode_tri(std::vector<std::vector<int>>& matrix, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, std::vector<std::vector<int>>& q_rect, int step_n)
{
	num_of_total_triangular = 0;
	num_of_upper_triangular = 0;
	num_of_lower_triangular = 0;
	num_of_black_nodes = 0;
	num_of_lines = 0;
	num_of_points = 0;
	num_of_rectangle = 0;
	num_of_total_rectangle = 0;
	num_of_total_mix = 0;
	triangular_ratio = 0;
	q_tri.clear();
	q_line.clear();
	q_point.clear();
	//q_square.clear();
	q_rect.clear();
	std::ofstream tri("q_tri.txt");
	std::ofstream line("q_line.txt");
	std::ofstream point("q_point.txt");
	std::ofstream square("q_square.txt");
	std::ofstream rect("q_rect.txt");
	std::ofstream ofs("matrix.txt");
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			ofs << matrix[i][j] << " ";
		}
		ofs << '\n';
	}
	assert(size == static_cast<int>(matrix.size()));
	std::vector<std::vector<int>> f(256, std::vector<int>(256, 0));
	for (int i = 0; i < 256; ++i)
	{
		for (int j = 0; j < 256; ++j)
		{
			f[j][i] = matrix[i][j];
		}
	}
	bool isCurrentNull0 = true;
	bool isCurrentNull1 = true;
	bool isCurrentNull2 = true;
	bool isCurrentNull3 = true;
	bool isCurrentNull4 = true;
	//srand(time(NULL));
	int cnt = 0;
	std::vector<std::vector<int>> copy = matrix;
	for (int x = 1; x <= size - 1; x += 1)
	{
		//int n = rand() % 3;
		for (int y = 1; y <= size - 1; y += 1)
		{
			for (int step = size - 1; step >= 1; step -= step_n)
			{
				// if (x + step <= size)
				// {
				// 	bool k1 = false;
				// 	bool k2 = false;
				// 	bool k3 = false;
				// 	// recu(matrix, x - 1, x + step - 1, y - 1, size - 1, isCurrentNull0);
				// 	// if (isCurrentNull0)
				// 	// {
				// 	// 	for (int i = 1; i <= step + 1; ++i) {
				// 	// 		for (int j = 1; j <= size - y + 1; ++j) {
				// 	// 			matrix[i + x - 2][j + y - 2] = 8;
				// 	// 		}
				// 	// 	}
				// 	// }
				// }
				if (x + step <= size && y + step <= size) {
					bool k1 = false;
					bool k2 = false;
					bool k3 = false;
					bool k4 = false;
					triu(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull1);
					// if (isCurrentNull1) {
					// 	num_of_upper_triangular++;
					// 	num_of_total_triangular++;
					// 	k1 = true;
					// }
					tril(matrix, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull2);
					// triu(f, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull3);
					// tril(f, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull4);
					// if (isCurrentNull2) {
					// 	num_of_lower_triangular++;
					// 	num_of_total_triangular++;
					// 	k2 = true;
					// }
					// if (isCurrentNull1 && isCurrentNull2) {
					// 	//k1 = true;
					// 	//k2 = true;
					// 	num_of_rectangle++;
					// 	num_of_total_rectangle++;
					// 	const int x1_abs = x;
					// 	const int y1_abs = y;
					// 	const int x2_abs = x + step;
					// 	const int y2_abs = step + y;
					// 	q_rect.push_back({ x1_abs, y1_abs, step });
					// 	rect << x1_abs << ' ' << y1_abs << ' ' << step << '\n';
					// 	for (int i = 1; i <= step + 1; ++i) {
					// 		for (int j = 1; j <= step + 1; ++j) {
					// 			matrix[i + x - 2][j + y - 2] = 8;
					// 		}
					// 	}
					// }
					// if (!cnt) {
					// 	cnt = 1; continue;
					// }
					// }
					// else
					// {
					if (isCurrentNull1) {
						num_of_upper_triangular++;
						num_of_total_triangular++;
						k1 = true;
					}
					if (isCurrentNull2) {
						num_of_lower_triangular++;
						num_of_total_triangular++;
						k2 = true;
					}
					//
					if (k1)
					{
						const int x1_abs = x;
						const int y1_abs = y;
						const int x2_abs = step + x;
						const int y2_abs = step + y;
						q_tri.push_back({ x1_abs, y1_abs, step });
						tri << x1_abs << ' ' << y1_abs << ' ' << step << '\n';
						//q_tri.push_back({ x2_abs, y1_abs, -step });
						//q_tri.push_back({ 0, x1_abs, y1_abs, x2_abs, y2_abs });
						//tri << 0 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
						for (int i = 1; i <= step + 1; ++i) {
							for (int j = i; j <= step + 1; ++j)
							{
								matrix[i + x - 2][j + y - 2] = 8;
							}
						}
						// for (int j = 1; j <= step + 1; ++j)
						// {
						// 	matrix[1 + x - 2][j + y - 2] = 8;
						// }
						// for (int j = 1; j <= step + 1; ++j)
						// {
						// 	copy[1 + x - 2][j + y - 2] = 8;
						// }
					}
					if (k2)
					{
						const int x1_abs = x;
						const int y1_abs = y;
						const int x2_abs = step + x;
						const int y2_abs = step + y;
						//std::vector<int> tri = { x1_abs, y2_abs, step };
						q_tri.push_back({ x2_abs,y2_abs,-step });
						tri << x2_abs << ' ' << y2_abs << ' ' << -step << '\n';
						//q_tri.push_back({ 1, x1_abs, y1_abs, x2_abs, y2_abs });
						//tri << 1 << " " << x1_abs << " " << y1_abs << " " << x2_abs << " " << y2_abs << "\n";
						for (int i = 1; i <= step + 1; ++i)
						{
							for (int j = 1; j <= i; ++j)
							{
								matrix[i + x - 2][j + y - 2] = 9;
							}
						}
					}
				}
			}
		}
	}
	// num_of_total_rectangle += num_of_rectangle;
	int length0 = 1;
	int width0 = 1;
	for (int x = 1; x <= size; ++x)
	{
		for (int y = 1; y <= size; ++y)
		{
			int sp_x = x;
			int sp_y = y;
			if (matrix[x - 1][y - 1] == 0)
			{
				int length = 1;
				int width = 1;
				int maxLength = 1;
				int maxWidth = 1;
				int maxArea = 0;
				int last = 0;
				for (int j = y; j <= size; ++j)
				{
					length0 = 0;
					for (int k = x; k <= size; ++k)
					{
						if (j != y && (k - sp_x + 1 > last))
						{
							break;
						}
						if (matrix[k - 1][j - 1] != 0)
						{
							break;
						}
						length0++;
					}
					if (j == y || length0 < last)
					{
						last = length0;
					}
					if (matrix[x - 1][j - 1] != 0)
					{
						break;
					}
					width0++;
					int area = last * (j - sp_y + 1);
					length = last;
					width = j - sp_y + 1;
					if (area > maxArea)
					{
						maxArea = area;
						maxLength = last;
						maxWidth = j - sp_y + 1;
					}
				}
				if (maxLength * maxWidth == 1)
				{
					num_of_points++;
					q_point.push_back({ x, y, maxLength, maxWidth });
					point << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				else
				{
					num_of_lines++;
					q_line.push_back({ x, y, maxLength, maxWidth });
					line << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
				}
				++num_of_black_nodes;
				for (int a = x; a <= x + maxLength - 1; ++a)
				{
					for (int b = y; b <= y + maxWidth - 1; ++b)
					{
						matrix[a - 1][b - 1] = 7;
					}
				}
			}
		}
	}
	//num_of_total_rectangle += num_of_black_nodes;
	num_of_total_rectangle += num_of_lines;
	num_of_total_mix = num_of_total_rectangle + num_of_total_triangular;
	triangular_ratio = pow(4, n) / static_cast<double>(num_of_points * n + num_of_lines * 2 * n + num_of_total_triangular * static_cast<size_t>(2 * n + 1));
	// std::cout << "upper_triangular:" << num_of_upper_triangular << "\n";
	// std::cout << "lower_triangular:" << num_of_lower_triangular << "\n";
	// std::cout << "total_triangular:" << num_of_total_triangular << "\n"; //三角形子模式数量
	// std::cout << "line_num:" << num_of_lines << "\n"; //单线段子模式数量
	// std::cout << "point_num:" << num_of_points << "\n"; //孤立点子模式数量
	// std::cout << "black_node:" << num_of_black_nodes << "\n";
	// std::cout << "num_of_total_rectangle:" << num_of_total_rectangle << "\n";
	// std::cout << "num_of_total_mix:" << num_of_total_mix << "\n";
	// std::cout << "triangular_ratio:" << triangular_ratio << "\n";
	tri.close();
	// std::cout << "q_tri数组的信息已成功存储到q_tri.txt文件中" << "\n";
	line.close();
	// std::cout << "q_line数组的信息已成功存储到q_line.txt文件中" << "\n";
	point.close();
	// std::cout << "q_point数组的信息已成功存储到q_point.txt文件中" << "\n";
	square.close();
	rect.close();
}

void TNAM::encode(int**& matrix, const int& rows, const int& cols, std::vector<std::vector<int>>& q_tri, std::vector<std::vector<int>>& q_line, std::vector<std::vector<int>>& q_point, int step_n)
{
	// std::ofstream tri("q_tri.txt");
	// std::ofstream line("q_line.txt");
	// std::ofstream point("q_point.txt");
	// assert(size == rows);
	// assert(size == cols);
	// bool isCurrentNull = true;
	// for (int x = 1; x <= size - 1; ++x)
	// {
	// 	for (int y = size - 1; y >= 1; --y)
	// 	{
	// 		for (int step = size - 1; step >= 1; step -= step_n)
	// 		{
	// 			if (x + step <= size && y + step <= size)
	// 			{
	// 				bool k1 = false;
	// 				bool k2 = false;
	// 				triu(matrix, rows, cols, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull);
	// 				if (isCurrentNull)
	// 				{
	// 					num_of_upper_triangular++;
	// 					num_of_total_triangular++;
	// 					k1 = true;
	// 				}
	// 				tril(matrix, rows, cols, x - 1, x + step - 1, y - 1, y + step - 1, 0, isCurrentNull);
	// 				if (isCurrentNull)
	// 				{
	// 					num_of_lower_triangular++;
	// 					num_of_total_triangular++;
	// 					k2 = true;
	// 				}
	// 				if (k1)
	// 				{
	// 					const int x1_abs = x;
	// 					const int y1_abs = y;
	// 					const int x2_abs = step + x;
	// 					const int y2_abs = step + y;
	// 					q_tri.push_back({ x1_abs, y1_abs, step });
	// 					tri << x1_abs << ' ' << y1_abs << ' ' << step << '\n';
	// 					//q_tri.push_back({ x1_abs, y1_abs, 0, step });
	// 					//tri << x1_abs << ' ' << y1_abs << ' ' << 0 << ' ' << step << '\n';
	// 					//q_tri.push_back({ x2_abs, y1_abs, -step });
	// 					//q_tri.push_back({ 0, x1_abs, y1_abs, x2_abs, y2_abs });
	// 				//	tri << 0 << ' ' << x1_abs << ' ' << y1_abs << ' ' << x2_abs << ' ' << y2_abs << '\n';
	// 					//tri << " " << x2_abs << " " << y1_abs << " " << -step << "\n";
	// 					for (int i = 1; i <= step + 1; ++i)
	// 					{
	// 						for (int j = i; j <= step + 1; ++j)
	// 						{
	// 							matrix[i + x - 2][j + y - 2] = 8;
	// 						}
	// 					}
	// 				}
	// 				if (k2)
	// 				{
	// 					const int x1_abs = x;
	// 					const int y1_abs = y;
	// 					const int x2_abs = step + x;
	// 					const int y2_abs = step + y;
	// 					q_tri.push_back({ x2_abs, y2_abs, -step });
	// 					tri << x2_abs << ' ' << y2_abs << ' ' << step << '\n';
	// 					//q_tri.push_back({ x2_abs, y1_abs, -step, 0 });
	// 					//tri << x2_abs << ' ' << y1_abs << ' ' << -step << ' ' << 0 << '\n';
	// 					//q_tri.push_back({ x1_abs, y2_abs, step });
	// 					//q_tri.push_back({ 1, x1_abs, y1_abs, x2_abs, y2_abs });
	// 					//tri << " " << x1_abs << " " << y2_abs << " " << step << "\n";
	// 					//tri << 1 << ' ' << x1_abs << ' ' << y1_abs << ' ' << x2_abs << ' ' << y2_abs << '\n';
	// 					for (int i = 1; i <= step + 1; ++i)
	// 					{
	// 						for (int j = 1; j <= i; ++j)
	// 						{
	// 							matrix[i + x - 2][j + y - 2] = 9;
	// 						}
	// 					}
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// int length0 = 1;
	// int width0 = 1;
	// for (int x = 1; x <= size; ++x)
	// {
	// 	for (int y = 1; y <= size; ++y)
	// 	{
	// 		int sp_x = x;
	// 		int sp_y = y;
	// 		if (matrix[x - 1][y - 1] == 0)
	// 		{
	// 			int length = 1;
	// 			int width = 1;
	// 			int maxLength = 1;
	// 			int maxWidth = 1;
	// 			int maxArea = 0;
	// 			int last = 0;
	// 			for (int j = y; j <= size; ++j)
	// 			{
	// 				length0 = 0;
	// 				for (int k = x; k <= size; ++k)
	// 				{
	// 					if (j != y && (k - sp_x + 1 > last))
	// 					{
	// 						break;
	// 					}
	// 					if (matrix[k - 1][j - 1] != 0)
	// 					{
	// 						break;
	// 					}
	// 					length0++;
	// 				}
	// 				if (j == y || length0 < last)
	// 				{
	// 					last = length0;
	// 				}
	// 				if (matrix[x - 1][j - 1] != 0)
	// 				{
	// 					break;
	// 				}
	// 				width0++;
	// 				int area = last * (j - sp_y + 1);
	// 				length = last;
	// 				width = j - sp_y + 1;
	// 				if (area > maxArea)
	// 				{
	// 					maxArea = area;
	// 					maxLength = last;
	// 					maxWidth = j - sp_y + 1;
	// 				}
	// 			}
	// 			if (maxLength * maxWidth == 1)
	// 			{
	// 				num_of_points++;
	// 				q_point.push_back({ x, y, maxLength, maxWidth });
	// 				point << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
	// 			}
	// 			else
	// 			{
	// 				num_of_lines++;
	// 				q_line.push_back({ x, y, maxLength, maxWidth });
	// 				line << x << " " << y << " " << maxLength << " " << maxWidth << "\n";
	// 			}
	// 			++num_of_black_nodes;
	// 			for (int a = x; a <= x + maxLength - 1; ++a)
	// 			{
	// 				for (int b = y; b <= y + maxWidth - 1; ++b)
	// 				{
	// 					matrix[a - 1][b - 1] = 7;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// num_of_total_rectangle = num_of_black_nodes;
	// num_of_total_mix = num_of_total_rectangle + num_of_total_triangular;
	// triangular_ratio = pow(4, n) / static_cast<double>(num_of_points * n + num_of_lines * 2 * n + num_of_total_triangular * static_cast<size_t>(2 * n + 1));
	// // std::cout << "upper_triangular:" << num_of_upper_triangular << "\n";
	// // std::cout << "lower_triangular:" << num_of_lower_triangular << "\n";
	// // std::cout << "total_triangular:" << num_of_total_triangular << "\n"; //三角形子模式数量
	// // std::cout << "line_num:" << num_of_lines << "\n"; //单线段子模式数量
	// // std::cout << "point_num:" << num_of_points << "\n"; //孤立点子模式数量
	// // std::cout << "black_node:" << num_of_black_nodes << "\n";
	// // std::cout << "num_of_total_rectangle:" << num_of_total_rectangle << "\n";
	// // std::cout << "num_of_total_mix:" << num_of_total_mix << "\n";
	// // std::cout << "triangular_ratio:" << triangular_ratio << "\n";
	// tri.close();
	// // std::cout << "q_tri数组的信息已成功存储到q_tri.txt文件中" << "\n";
	// line.close();
	// // std::cout << "q_line数组的信息已成功存储到q_line.txt文件中" << "\n";
	// point.close();
	// // std::cout << "q_point数组的信息已成功存储到q_point.txt文件中" << "\n";
}
void TNAM::decode(cv::Mat& dst, cv::Mat& seg, const std::vector<std::vector<int>>& q_tri, const std::vector<std::vector<int>>& q_line, const std::vector<std::vector<int>>& q_point, const std::vector<std::vector<int>>& q_rect, std::vector<std::vector<int>>& res)
{
	res = std::vector<std::vector<int>>(256, std::vector<int>(256, 1));
	seg = cv::Mat(NAM::TNAM::size, NAM::TNAM::size, CV_8UC1, cv::Scalar(255));
	std::ofstream ofs2("canshu.txt");
	ofs2 << q_tri.size() << '\n';
	ofs2 << q_rect.size() << '\n';
	ofs2 << q_line.size() << '\n';
	ofs2 << q_point.size() << '\n';
	for (size_t k = 0; k < q_rect.size(); ++k)
	{
		const int x1_abs = q_rect[k][0];
		const int y1_abs = q_rect[k][1];
		const int flag1 = q_rect[k][2];
		const int flag2 = q_rect[k][3];
		const int x2_abs = x1_abs + flag1;
		const int y2_abs = y1_abs + flag2;
		for (int i = x1_abs; i <= x1_abs + flag1; ++i)
		{
			for (int j = y1_abs; j <= y1_abs + flag2; ++j)
			{
				res[i - 1][j - 1] = 0;
			}
		}
		// if (k % 4 == 1)
		// {
			cv::Point2d p0(y1_abs, x1_abs);
			cv::Point2d p1(y2_abs, x1_abs);
			cv::Point2d p2(y2_abs, x2_abs);
			cv::Point2d p3(y1_abs, x2_abs);
			cv::Point2d p4(y1_abs, static_cast<double>(x1_abs + x2_abs) / 2);
			cv::Point2d p5(y2_abs, static_cast<double>(x1_abs + x2_abs) / 2);
			// cv::line(seg, p0, p1, cv::Scalar(0));
			// cv::line(seg, p0, p4, cv::Scalar(0));
			// cv::line(seg, p4, p5, cv::Scalar(0));
			// cv::line(seg, p5, p2, cv::Scalar(0));
			// cv::line(seg, p2, p3, cv::Scalar(0));

			// cv::line(seg, p0, p3, cv::Scalar(0));
			// cv::line(seg, p0, p4, cv::Scalar(0));
			// cv::line(seg, p4, p5, cv::Scalar(0));
			// cv::line(seg, p5, p2, cv::Scalar(0));
			// cv::line(seg, p2, p3, cv::Scalar(0));



			cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
			cv::line(seg, p1, p2, cv::Scalar(0, 0, 0));
			cv::line(seg, p2, p3, cv::Scalar(0, 0, 0));
			cv::line(seg, p3, p0, cv::Scalar(0, 0, 0));
			// cv::Point2d center(static_cast<double>(y1_abs + y2_abs) / 2, static_cast<double>(x1_abs + x2_abs) / 2);
			// double radius = std::fabs(static_cast<double>(x2_abs - x1_abs) / 2);
			// cv::circle(seg, center, radius, cv::Scalar(0));
		// }
		// else if (k % 4 == 3)
		// {
		// 	cv::Point2d p0(y1_abs, x1_abs);
		// 	cv::Point2d p1(y2_abs, x1_abs);
		// 	cv::Point2d p2(y2_abs, x2_abs);
		// 	cv::Point2d p3(y1_abs, x2_abs);
		// 	cv::Point2d p4(y1_abs, static_cast<double>(x1_abs + x2_abs) / 2);
		// 	cv::Point2d p5(y2_abs, static_cast<double>(x1_abs + x2_abs) / 2);
		// 	cv::line(seg, p0, p1, cv::Scalar(0));
		// 	cv::line(seg, p0, p4, cv::Scalar(0));
		// 	cv::line(seg, p4, p5, cv::Scalar(0));
		// 	cv::line(seg, p5, p2, cv::Scalar(0));
		// 	cv::line(seg, p2, p3, cv::Scalar(0));
		// }
		
	}
	for (size_t k = 0; k < q_tri.size(); ++k)
	{
		const int val1 = q_tri[k][0];
		const int val2 = q_tri[k][1];
		const int flag = q_tri[k][2];
		if (flag > 0) {
			const int x1_abs = q_tri[k][0];
			const int y1_abs = q_tri[k][1];
			const int x2_abs = q_tri[k][0] + flag;
			const int y2_abs = q_tri[k][1] + flag;
			int step = 0;
			for (int i = x1_abs; i <= x2_abs; ++i) {
				for (int j = y1_abs + step; j <= y2_abs; ++j) {
					res[i - 1][j - 1] = 0;
				}
				step++;
			}
			cv::Point2d p0(y1_abs, x1_abs);
			cv::Point2d p1(y2_abs, x1_abs);
			cv::Point2d p2(y2_abs, x2_abs);
			cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
			cv::line(seg, p0, p2, cv::Scalar(0, 0, 0));
			cv::line(seg, p1, p2, cv::Scalar(0, 0, 0));
		}
		else {
			const int x1_abs = q_tri[k][0] + flag;
			const int y1_abs = q_tri[k][1] + flag;
			const int x2_abs = q_tri[k][0];
			const int y2_abs = q_tri[k][1];
			int step = 0;
			for (int i = x1_abs; i <= x2_abs; ++i) {
				for (int j = y1_abs; j <= y1_abs + step; ++j) {
					res[i - 1][j - 1] = 0;
				}
				step++;
			}
			cv::Point2d p0(y1_abs, x1_abs);
			cv::Point2d p1(y1_abs, x2_abs);
			cv::Point2d p2(y1_abs + step, x2_abs);
			cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
			cv::line(seg, p0, p2, cv::Scalar(0, 0, 0));
			cv::line(seg, p1, p2, cv::Scalar(0, 0, 0));
		}
		// int step = 0;
		// const int flag = q_tri[k][0];
		// const int x1_abs = q_tri[k][1];
		// const int y1_abs = q_tri[k][2];
		// const int x2_abs = q_tri[k][3];
		// const int y2_abs = q_tri[k][4];
		// switch (flag)
		// {
		// case 0:
		// {
		// 	int step = 0;
		// 	for (int i = x1_abs; i <= x2_abs; ++i)
		// 	{
		// 		for (int j = y1_abs + step; j <= y2_abs; ++j)
		// 		{
		// 			res[i - 1][j - 1] = 0;
		// 		}
		// 		step++;
		// 	}
		// 	cv::Point2d p0(y1_abs, x1_abs);
		// 	cv::Point2d p1(y2_abs, x1_abs);
		// 	cv::Point2d p2(y2_abs, x2_abs);
		// 	cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
		// 	cv::line(seg, p0, p2, cv::Scalar(0, 0, 0));
		// 	cv::line(seg, p1, p2, cv::Scalar(0, 0, 0));
		//
		// }
		// break;
		// case 1:
		// {
		// 	int step = 0;
		// 	for (int i = x1_abs; i <= x2_abs; ++i)
		// 	{
		// 		for (int j = y1_abs; j <= y1_abs + step; ++j)
		// 		{
		// 			res[i - 1][j - 1] = 0;
		// 		}
		// 		step++;
		// 	}
		// 	cv::Point2d p0(y1_abs, x1_abs);
		// 	cv::Point2d p1(y1_abs, x2_abs);
		// 	cv::Point2d p2(y1_abs + step, x2_abs);
		// 	cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
		// 	cv::line(seg, p0, p2, cv::Scalar(0, 0, 0));
		// 	cv::line(seg, p1, p2, cv::Scalar(0, 0, 0));
		//
		// }
		// break;
		// default:
		// 	assert(false);
		// }
	}
	for (size_t j = 0; j < q_line.size(); ++j)
	{
		const int x = q_line[j][0];
		const int y = q_line[j][1];
		const int maxLength = q_line[j][2];
		const int maxWidth = q_line[j][3];
		for (int a = x; a <= x + maxLength - 1; ++a)
		{
			for (int b = y; b <= y + maxWidth - 1; ++b)
			{
				res[a - 1][b - 1] = 0;
			}
		}
		cv::Point2d p0(y, x);
		cv::Point2d p1(y + maxWidth - 1, x + maxLength - 1);
		cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
	}
	for (size_t j = 0; j < q_point.size(); ++j)
	{
		const int x = q_point[j][0];
		const int y = q_point[j][1];
		const int maxLength = q_point[j][2];
		const int maxWidth = q_point[j][3];
		for (int a = x; a <= x + maxLength - 1; ++a)
		{
			for (int b = y; b <= y + maxWidth - 1; ++b)
			{
				res[a - 1][b - 1] = 0;
			}
		}
		cv::Point2d p0(y, x);
		cv::Point2d p1(y + maxWidth - 1, x + maxLength - 1);
		cv::line(seg, p0, p1, cv::Scalar(0, 0, 0));
	}
	std::ofstream ofs;
	ofs.open("matrix.txt", std::ios::out);
	for (auto& tri : res)
	{
		for (auto& it : tri)
		{
			ofs << it << " ";
		}
		ofs << "\n";
	}
	//std::cout << "解码后的图像信息已经存储到matrix.txt文件中" << "\n";
	for (int i = 0; i < dst.rows; ++i)
	{
		for (int j = 0; j < dst.cols; ++j)
		{
			dst.at<uchar>(i, j) = res[i][j] * 255;
		}
	}
	ofs.close();
}
}//namespace NAM
