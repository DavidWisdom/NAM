#ifndef TNAM_MATH_H
#define TNAM_MATH_H
// #include "math.h"
#include <vector>
#include <cassert>
namespace NAM {
// template <typename T>
class TNAMMath {
protected:
	static void triu(const std::vector<std::vector<int>>&, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
	// static void triu(const int**&, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
	// static void triu(int**&, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
	static void tril(const std::vector<std::vector<int>>&, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
	static void recu(const std::vector<std::vector<int>>&, const int& r1, const int& r2, const int& c1, const int& c2, bool& isSumNull);
	// static void tril(const int**&, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
	// static void tril(int**&, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull);
};
} //namespace Numpy

#endif //TNAM_MATH_H

