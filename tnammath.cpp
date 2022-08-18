#include "tnammath.h"
namespace NAM {
	void TNAMMath::triu(const std::vector<std::vector<int>>& matrix, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	{
		isSumNull = true;
		for (int i = r1; i <= r2; ++i) {
			for (int j = c1; j <= c2; ++j) {
				if ((j - c1) - (i - r1) >= k) {
					if (matrix[i][j]) {
						isSumNull = false;
						return;
					}
				}
			}
		}
	}
	void TNAMMath::recu(const std::vector<std::vector<int>>& matrix, const int& r1, const int& r2, const int& c1, const int& c2, bool& isSumNull)
	{
		isSumNull = true;
		for (int i = r1; i <= r2; ++i)
		{
			for (int j = c1; j <= c2; ++j)
			{
				if (matrix[i][j])
				{
					isSumNull = false;
					return;
				}
			}
		}
	}


	// void TNAMMath::triu(int**& matrix, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	// {
	// 	assert(rows > r2);
	// 	assert(cols > c2);
	// 	isSumNull = true;
	// 	for (int i = r1; i <= r2; ++i) {
	// 		for (int j = c1; j <= c2; ++j) {
	// 			if ((j - c1) - (i - r1) >= k) {
	// 				if (matrix[i][j]) {
	// 					isSumNull = false;
	// 					return;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	//
	// void TNAMMath::triu(const int**& matrix, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	// {
	// 	assert(rows > r2);
	// 	assert(cols > c2);
	// 	isSumNull = true;
	// 	for (int i = r1; i <= r2; ++i) {
	// 		for (int j = c1; j <= c2; ++j) {
	// 			if ((j - c1) - (i - r1) >= k) {
	// 				if (matrix[i][j]) {
	// 					isSumNull = false;
	// 					return;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	void TNAMMath::tril(const std::vector<std::vector<int>>& matrix, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	{
		isSumNull = true;
		for (int i = r1; i <= r2; ++i) {
			for (int j = c1; j <= c2; ++j) {
				if ((i - r1) - (j - c1) >= k) {
					if (matrix[i][j]) {
						isSumNull = false;
						return;
					}
				}
			}
		}
	}

	// void TNAMMath::tril(int**& matrix, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	// {
	// 	assert(rows > r2);
	// 	assert(cols > c2);
	// 	isSumNull = true;
	// 	for (int i = r1; i <= r2; ++i) {
	// 		for (int j = c1; j <= c2; ++j) {
	// 			if ((i - r1) - (j - c1) >= k) {
	// 				if (matrix[i][j]) {
	// 					isSumNull = false;
	// 					return;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	//
	// void TNAMMath::tril(const int**& matrix, const int& rows, const int& cols, const int& r1, const int& r2, const int& c1, const int& c2, const int& k, bool& isSumNull)
	// {
	// 	assert(rows > r2);
	// 	assert(cols > c2);
	// 	isSumNull = true;
	// 	for (int i = r1; i <= r2; ++i) {
	// 		for (int j = c1; j <= c2; ++j) {
	// 			if ((i - r1) - (j - c1) >= k) {
	// 				if (matrix[i][j]) {
	// 					isSumNull = false;
	// 					return;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
} //namespace NAM
