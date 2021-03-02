#include <gtest/gtest.h>
#include <utility>

// 蚂蚁
// n只蚂蚁在竹竿上爬行，求所有蚂蚁从竹竿掉落的最大和最小时间。
// 蚂蚁相遇时会回头，竹竿宽度只能容许一只蚂蚁爬行。

namespace
{
	int L = 10;
	int n = 3;
	int x[] = { 2, 6, 7 };

	std::pair<int, int> simple()
	{
		int min = 0, max = 0;
		for (int i = 0; i < n; ++i)
		{
			// 单只蚂蚁从竹竿掉落的最大最小值
			int min_fall = (std::min)(x[i], L - x[i]);
			int max_fall = (std::max)(x[i], L - x[i]);

			// 所有蚂蚁都掉落，所以是最大值
			min = (std::max)(min, min_fall);

			max = (std::max)(max, max_fall);
		}
		return { min, max };
	}
}

TEST(Code1_6_2, Simple)
{
	ASSERT_EQ(std::make_pair(4, 8), simple());
}
