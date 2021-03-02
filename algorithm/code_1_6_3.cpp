#include <gtest/gtest.h>
#include <algorithm>
using namespace std;

// 抽签，与1.1相同
// 从n个数字中抽出4个（可重复），是否可以相加后等于m

namespace
{
	int n = 3;
	int k[] = { 1, 3, 5 };

	bool simple(int m)
	{
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				for (int c = 0; c < n; ++c)
				{
					for (int d = 0; d < n; ++d)
					{
						if (k[a] + k[b] + k[c] + k[d] == m)
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}

	// O(n^4) -> O(n^3*log2(n))
	bool improved(int m)
	{
		std::vector<int> sorted{ begin(k), end(k) };
		std::sort(sorted.begin(), sorted.end());
		auto end = sorted.end();
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				for (int c = 0; c < n; ++c)
				{
					int d = m - (k[a] + k[b] + k[c]);
					if (std::binary_search(sorted.begin(), end, d))
					{
						return true;
					}
				}
			}
		}
		return false;
	}

	// O(n^4) -> O(n^2*log2(n))
	bool fast(int m)
	{
		std::vector<int> sum;
		const int space = n * n;
		sum.reserve(space);
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				sum.push_back(k[a] + k[b]);
			}
		}
		std::sort(sum.begin(), sum.end());
		for (int i = 0; i < space; ++i)
		{
			if (std::binary_search(sum.begin(), sum.end(), m - sum[i]))
			{
				return true;
			}
		}
		return false;
	}

	// O(n^4) -> O(n^2*log2(n))
	bool fast2(int m)
	{
		std::vector<int> sum;
		const int space = n * n;
		sum.reserve(space);
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				sum.push_back(k[a] + k[b]);
			}
		}
		std::sort(sum.begin(), sum.end());

		for (int i = 0, j = space - 1; i <= j;)
		{
			int add = sum[i] + sum[j];
			if (add == m) return true;
			else if (add > m) --j;
			else ++i;
		}
		return false;
	}
}

TEST(Code1_6_3, Simple)
{
	// 可以得出10，但是无法得出9
	ASSERT_TRUE(simple(10));
	ASSERT_FALSE(simple(9));
}

TEST(Code1_6_3, Improved)
{
	// 可以得出10，但是无法得出9
	ASSERT_TRUE(improved(10));
	ASSERT_FALSE(improved(9));
}

TEST(Code1_6_3, Fast)
{
	// 可以得出10，但是无法得出9
	ASSERT_TRUE(fast(10));
	ASSERT_FALSE(fast(9));
}

TEST(Code1_6_3, Fast2)
{
	// 可以得出10，但是无法得出9
	ASSERT_TRUE(fast2(10));
	ASSERT_FALSE(fast2(9));
}
