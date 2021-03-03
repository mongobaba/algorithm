#include <gtest/gtest.h>
#include <vector>

// 区间调度问题
// 多项工作时间有重叠，不能同时参与。计算可以参与的工作的最大数量

namespace
{
	const std::vector<int> start{ 1, 2, 4, 6, 8 };
	// 假设已经按照结束时间排好序了
	const std::vector<int> finish{ 3, 5, 7, 9, 10 };

	int simple(std::vector<int> start, std::vector<int> finish)
	{
		int count = 0;
		int last = 0;
		for (size_t i = 0; i < finish.size(); ++i)
		{
			if (start[i] > last)
			{
				++count;
				last = finish[i];
			}
		}
		return count;
	}
}

TEST(Code2_2_2, Simple)
{
	ASSERT_EQ(3, simple(start, finish));
}
