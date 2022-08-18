#include "rnamc.h"
namespace NAM {
void RNAMC::rnamc(const cv::Mat* img, cv::Mat& dst, cv::Mat& seg, std::wstring& res, const int& margin, const int& ratio)
{
	res.clear();
	const int height = img->rows;
	const int width = img->cols;
	const auto markMatrix = new cv::Mat(height, width, CV_8UC1, cv::Scalar(0));
	const auto R = new cv::Mat(height, width, CV_8UC1, cv::Scalar(0));
	int num = 0;
	std::vector<ColorNode> colorList;
	std::vector<Location> locList;
	time_t begin = clock();
	/*·Ö¿é*/
	startNamCut(img, markMatrix, R, colorList, locList, height, width, margin, num, ratio);
	/*¾ØÕó±àÂë*/
	std::vector<char> Q;
	encode(R, height, width, Q);
	time_t end = clock();
	std::wstringstream output;
	output << L"±àÂëÑ¹Ëõ»¨·Ñ:" << end - begin << L"ms" << '\n';
	std::wstring tmp;
	output >> tmp;
	res += tmp;
	output << L"±àÂë¹²£º" << Q.size() << L"Î»" << '\n';
	output >> tmp;
	res += tmp;
	const auto T = new cv::Mat(height, width, CV_8UC1, cv::Scalar(0));
	begin = clock();
	decode(T, height, width, Q);
	//TODO: ×¢ÊÍµô
	const auto newImg = new cv::Mat(height, width, CV_8UC1, cv::Scalar(0));
	restoreImage(newImg, markMatrix, T, colorList, height, width);
	//TODO: ×¢ÊÍµô
	end = clock();
	output << L"»¹Ô­Í¼ÏñºÄÊ±:" << end - begin << L"ms" << '\n';
	output >> tmp;
	res += tmp;
	output << L"¿éÊý:" << num << std::endl;
	output >> tmp;
	res += tmp;
	output << L"PSNRÖµ:" << psnr(img, newImg) << '\n';
	output >> tmp;
	res += tmp;
	const double BPPValue = bpp(colorList, width, height, Q);
	output << L"BPPÖµ:" << BPPValue << '\n';
	output >> tmp;
	res += tmp;
	output << L"CRÖµ:" << 8.0 / BPPValue << '\n';
	output >> tmp;
	res += tmp;
	//cv::imshow("compress", *newImg);
	//cvNamedWindow("Ñ¹ËõÍ¼»Ò¶ÈÍ¼Ïñ", 1);
	//cvShowImage("Ñ¹ËõÍ¼»Ò¶ÈÍ¼Ïñ", newImg);
	dst = *newImg;
	//cvSaveImage("D:\\user\\projects\\VS\\horizontal\\horizontal\\gray.bmp", newImg, 0);
	//cvSaveImage(argv[2],img,0);
	//cvSaveImage(argv[3],newImg,0);
	cv::Mat* sketch;
	int xr, yr;
	int sketchXn, sketchYn;
	if (height >= 256 || width >= 256) {
		xr = 1, yr = 1, sketchXn = height, sketchYn = width;
		sketch = new cv::Mat(img->rows, img->cols, CV_8UC1, cv::Scalar(0));
	}
	else {
		xr = 511 / (height - 1);
		yr = 511 / (width - 1);
		sketchXn = 512, sketchYn = 512;
		sketch = new cv::Mat(512, 512, CV_8UC1, cv::Scalar(0));
	}
	for (int i = 0; i < sketchYn; i++) {
		uchar* ptrsketch = sketch->data + i * sketch->step;
		for (int j = 0; j < sketchXn; j++) {
			ptrsketch[j] = 255;
		}
	}
	for (size_t i = 0; i < locList.size(); i++) {
		if (locList[i].x1 == 0 && locList[i].y1 == 0) {
			cv::rectangle(*sketch, cv::Point(locList[i].x1, locList[i].y1), cv::Point(locList[i].x2, locList[i].y2), cv::Scalar(0));
		}
		else if (locList[i].x1 == 0 && locList[i].y1 != 0) {
			cv::rectangle(*sketch, cv::Point(locList[i].x1, locList[i].y1 - 1), cv::Point(locList[i].x2, locList[i].y2), cv::Scalar(0));
		}
		else if (locList[i].x1 != 0 && locList[i].y1 == 0) {
			cv::rectangle(*sketch, cv::Point(locList[i].x1 - 1, locList[i].y1), cv::Point(locList[i].x2, locList[i].y2), cv::Scalar(0));
		}
		else if (locList[i].x1 != 0 && locList[i].y1 != 0) {
			cv::rectangle(*sketch, cv::Point(locList[i].x1 - 1, locList[i].y1 - 1), cv::Point(locList[i].x2, locList[i].y2), cv::Scalar(0));
		}
	}
	seg = *sketch;
	//output >> res;
	//cv::imwrite("Segmentation.bmp", *sketch);
	//cv::imshow("Segmentation", *sketch);
	//cv::waitKey();
	//cv::destroyAllWindows();
}

double RNAMC::bpp(const std::vector<ColorNode>& cn, const int& xn, const int& yn, const std::vector<char>& q) const
{
	int a1 = 0;
	int a2 = 0;
	int a3 = 0;
	for (size_t i = 0; i < cn.size(); ++i) {
		if (cn[i].g1 != -1 && cn[i].g4 != -1) {
			++a1;
		}
		else if (cn[i].g2 == -1 && cn[i].g3 == -1) {
			++a3;
		}
		else {
			++a2;
		}
	}
	return (q.size() + 16. * a1 + 8. * a2 + 4. * a3) / (xn * yn);
}

void RNAMC::encode(const cv::Mat* r, const int& height, const int& width, std::vector<char>& q) const
{
	int c = 0;
	int offsetValue = 0;
	int count = 0;
	for (int i = 0; i < height; ++i) {
		c = 0;
		offsetValue = 0;
		count = 0;
		for (int j = 0; j < width; ++j) {
			int val = (r->data + r->step * i)[j];
			if (val == 0) {
				if (j == width - 1) {
					q.push_back('0');
				}
			}
			else {
				if (val == 1) {
					q.push_back('1');
					q.push_back('1');
				}
				else if (val == 2) {
					q.push_back('1');
					q.push_back('0');
					q.push_back('1');
				}
				else if (val == 3) {
					q.push_back('1');
					q.push_back('0');
					q.push_back('0');
				}
				int b = ceil(log((double)(width - c - count)) / log(2.0f));
				if (count == 0) {
					offsetValue = j;
				}
				else {
					offsetValue = j - c - 1;
				}
				b = (b == 0) ? 1 : b;
				count = 1;
				c = j;
				for (int v = b - 1; v >= 0; --v) {
					if ((offsetValue & (1 << v)) == 0) {
						q.push_back('0');
					}
					else { 	
						q.push_back('1');
					}
				}
			}
		}
	}
}

void RNAMC::decode(const cv::Mat* r, const int& height, const int& width, const std::vector<char>& q) const
{
	int n = 0;
	int count = 0;
	int c = 0;
	int row = 0;
	int num = 0;
	for (size_t pos = 0; pos < q.size(); ++pos) {
		if (q[pos] == '1') {
			pos++;
			if (q[pos] == '1') {
				n = 1;
			}
			else {
				pos++;
				if (q[pos] == '1') {
					n = 2;
				}
				else {
					n = 3;
				}
			}
		}
		else
		{
			row++;
			count = 0;
			c = 0;
			num = 0;
			continue;
		}
		int b = ceil(log((double)(width - c - count)) / log(2.0f));
		b = b == 0 ? 1 : b;
		count = 1;
		int value = 0;
		for (int i = b - 1; i >= 0; i--) {
			pos++;
			if (q[pos] == '1')
			{
				value += 1 << i;
			}
		}
		if (num == 0) {
			c = c + value;
		}
		else {
			c = c + value + 1;
		}
		num++;
		(r->data + row * r->step)[c] = n;
		if (c == (width - 1)) {
			row++;
			count = 0;
			c = 0;
			num = 0;
		}
	}
}

bool RNAMC::isSameBlock(const cv::Mat* img, const int& x1, const int& y1, const int& x2, const int& y2, const int& margin) const
{
	const uchar* gy1 = img->data + y1 * img->step;
	const uchar* g1 = gy1 + x1;
	const uchar* g2 = gy1 + x2;
	const uchar* gy2 = img->data + y2 * img->step;
	const uchar* g3 = gy2 + x1;
	const uchar* g4 = gy2 + x2;
	bool returnValue = true;
	if (x1 == x2 && y1 == y2) {
		returnValue = true;
	}
	else if (y1 == y2) {
		for (int x = x1 + 1; x < x2; x++) {
			const double i2 = static_cast<double>((x - x1)) / static_cast<double>((x2 - x1));
			const double g = *g1 + (*g4 - *g1) * i2;
			const uchar* gValue = gy1 + x;
			if (abs(*gValue - g) > margin) {
				returnValue = false;
				break;
			}
		}
	}
	else if (x1 == x2) {
		for (int y = y1 + 1; y < y2; y++) {
			const double i1 = static_cast<double>((y - y1)) / static_cast<double>((y2 - y1));
			const double g = *g1 + (*g4 - *g1) * i1;
			const uchar* gy = img->data + y * img->step;
			const uchar* gValue = gy + x1;
			if (abs(*gValue - g) > margin) {
				returnValue = false;
				break;
			}
		}
	}
	else {
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				const double i1 = static_cast<double>((y - y1)) / static_cast<double>((y2 - y1));
				const double i2 = static_cast<double>((x - x1)) / static_cast<double>((x2 - x1));
				const double g5 = *g1 + (*g2 - *g1) * i2;
				const double g6 = *g3 + (*g4 - *g3) * i2;
				const double g = g5 + (g6 - g5) * i1;
				const uchar* gy = img->data + y * img->step;
				const uchar* gValue = gy + x;
				if (abs(*gValue - g) > margin) {
					returnValue = false;
					break;
				}
			}
		}
	}
	return returnValue;
}

double RNAMC::psnr(const cv::Mat* img, const cv::Mat* newImg) const
{
	const int yn = img->rows;
	const int xn = img->cols;
	double sum = 0.;
	for (int i = 0; i < yn; ++i) {
		const uchar* imgptr = img->data + i * img->step;
		const uchar* newImgptr = newImg->data + i * newImg->step;
		for (int j = 0; j < xn; ++j) {
			sum += pow(static_cast<double>(imgptr[j] - newImgptr[j]), 2);
		}
	}
	const double temp = 255. * 255 * xn * yn / sum;
	return 10 * log(temp) / log(10.);
}

void RNAMC::restoreImage(cv::Mat* img, cv::Mat* markMatrix, cv::Mat* r, const std::vector<ColorNode>& cn, const int& height, const int& width)
{
	int x1 = 0;
	int x2 = 0;
	int y1 = 0;
	int y2 = 0;
	for (const auto& it : cn)
	{
		int i = 0;
		while (x2 < width)
		{
			if ((markMatrix->data + markMatrix->step * y2)[x2++] == 1)
			{
				break;
			}
			if (x2 == width)
			{
				x1 = x2 = 0;
				y1 = ++y2;
			}
		}
		x1 = --x2;
		if (it.kind == 0) {
			while (x2 < width) {
				if ((r->data + r->step * y2)[++x2] != 0 || (markMatrix->data + markMatrix->step * y2)[x2] == 0) {
					break;
				}
			}
			x2--;
			while (y2 < height) {
				if ((r->data + r->step * y2)[x2] == 2 || (markMatrix->data + markMatrix->step * y2)[x2] == 0) {
					break;
				}
				y2++;
			}
		}
		else if (it.kind == 1) {
			while (x2 < width) {
				if ((r->data + r->step * y2)[++x2] == 2) {
					break;
				}
			}
		}
		else if (it.kind == 2) {
			while (y2 < height) {
				if ((r->data + r->step * y2)[x2] == 2) {
					break;
				}
				y2++;
			}
		}
		restoreImageValue(img, it, x1, y1, x2, y2);
		setMarkMatrix(markMatrix, x1, y1, x2, y2, 0);
		x1 = x2;
		y2 = y1;
	}
}

void RNAMC::restoreImageValue(cv::Mat* img, ColorNode node, const int& x1, const int& y1, const int& x2, const int& y2)
{
	uchar* upPtr = (img->data + img->step * y1);
	uchar* downPtr = (img->data + img->step * y2);
	if (node.kind == 3) {
		upPtr[x1] = node.g1;
	}
	else if (node.kind == 1) {
		upPtr[x1] = node.g1;
		upPtr[x2] = node.g2;
		for (int x = x1 + 1; x < x2; x++) {
			const double i2 = (double)(x - x1) / (double)(x2 - x1);
			upPtr[x] = (int)(node.g1 + (node.g2 - node.g1) * i2);

		}
	}
	else if (node.kind == 2) {
		upPtr[x1] = node.g1;
		downPtr[x1] = node.g2;
		for (int y = y1 + 1; y < y2; y++) {
			const double i1 = (double)(y - y1) / (double)(y2 - y1);
			(img->data + img->step * y)[x1] = (int)(node.g1 + (node.g2 - node.g1) * i1);
		}
	}
	else {
		for (int x = x1; x <= x2; x++) {
			for (int y = y1; y <= y2; y++) {
				const double i1 = (double)(y - y1) / (double)(y2 - y1);
				const double i2 = (double)(x - x1) / (double)(x2 - x1);
				const double g5 = node.g1 + (node.g2 - node.g1) * i2;
				const double g6 = node.g3 + (node.g4 - node.g3) * i2;
				(img->data + img->step * y)[x] = (int)(g5 + (g6 - g5) * i1);

			}
		}
		upPtr[x1] = node.g1;
		upPtr[x2] = node.g2;
		downPtr[x1] = node.g3;
		downPtr[x2] = node.g4;
	}
}

void RNAMC::setMarkMatrix(const cv::Mat* markMatrix, const int& x1, const int& y1, const int& x2, const int& y2, const int& val) const
{
	for (int y = y1; y <= y2; ++y) {
		for (int x = x1; x <= x2; ++x) {
			(markMatrix->data + markMatrix->step * y)[x] = val;
		}
	}
}

void RNAMC::startNamCut(const cv::Mat* img, const cv::Mat* markMatrix, const cv::Mat* r, std::vector<ColorNode>& colorList, std::vector<Location>& locList, const int& height, const int& width, const double& margin, int& num, const double& ratio)
{
	for (int row = 0; row < height; ++row) {
		for (int col = 0; col < width; ++col) {
			if ((markMatrix->data + row * markMatrix->step)[col] == 0) {
				++num;
				Location loc = findSameBlock(img, markMatrix, r, col, row, margin, ratio);
				locList.push_back(loc);
				setMarkMatrix(markMatrix, loc.x1, loc.y1, loc.x2, loc.y2, 1);
				if (loc.x1 == loc.x2 && loc.y1 == loc.y2) {
					uchar* g = r->data + r->step * loc.y1;
					g[loc.x1] = 3;
					ColorNode node(3, (img->data + img->step * loc.y1)[loc.x1]);
					colorList.push_back(node);
				}
				else if (loc.x1 == loc.x2) {
					for (int j = loc.y1; j <= loc.y2; j++)
					{
						uchar* g = r->data + r->step * j;
						g[loc.x1] = 0;
					}
					(r->data + r->step * loc.y1)[loc.x1] = 1;
					(r->data + r->step * loc.y2)[loc.x1] = 2;
					ColorNode node(2, (img->data + img->step * loc.y1)[loc.x1], (img->data + img->step * loc.y2)[loc.x1]);
					colorList.push_back(node);
				}
				else {
					for (int i = loc.y1; i <= loc.y2; i++) {
						for (int j = loc.x1; j <= loc.x2; j++) {
							(r->data + r->step * i)[j] = 0;
						}
					}
					if (loc.y1 == loc.y2) {
						ColorNode node(1, (img->data + img->step * loc.y1)[loc.x1], (img->data + img->step * loc.y1)[loc.x2]);
						colorList.push_back(node);
					}
					else {
						ColorNode node(0, (img->data + img->step * loc.y1)[loc.x1], (img->data + img->step * loc.y1)[loc.x2],
							(img->data + img->step * loc.y2)[loc.x1], (img->data + img->step * loc.y2)[loc.x2]);
						colorList.push_back(node);
					}
					(r->data + r->step * loc.y1)[loc.x1] = 1;
					(r->data + r->step * loc.y2)[loc.x2] = 2;
				}
			}
		}
	}
}
} //namespace NAM
