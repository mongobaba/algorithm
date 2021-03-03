#include <gtest/gtest.h>
#include <vector>
#include <cassert>

// 点标记

namespace
{
	int simple(const std::vector<int>& vec, int r)
	{
		int count = 0;
		size_t i = 0;			// 没有被覆盖的第一个点的下标
		while (i < vec.size())	// 如果还有没被覆盖的
		{
			// 没有被覆盖的第一个点的位置
			int pos = vec[i];
			// 找超出范围的第一个点，则前一个需要被标记
			while (i < vec.size() && vec[i] - pos <= r) ++i;
			// 标记i - 1
			++count;
			// 记录i - 1的位置
			pos = vec[i - 1];
			// 然后把能被i - 1覆盖的点全部排除
			while (i < vec.size() && vec[i] - pos <= r) ++i;
		}
		return count;
	}
}

TEST(Code2_2_4, Simple)
{
	std::vector<int> v1{ 1, 7, 15, 20, 30, 50 };
	ASSERT_EQ(3, simple(v1, 10));
}

TEST(Code2_2_4, AllShouldBeMarked)
{
	std::vector<int> v2{ 1, 50, 100, 200, 500 };
	ASSERT_EQ(5, simple(v2, 10));
}
