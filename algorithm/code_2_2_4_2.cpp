#include <gtest/gtest.h>
#include <vector>
#include <set>

// 木块切割问题
// 木块切割成N小块，切割成本与木块长度成正比，计算最小切割成本。

namespace
{
	int simple(const std::vector<int>& vec)
	{
		int cost = 0;
		std::multiset<int> ms(vec.begin(), vec.end());
		while (ms.size() > 1)
		{
			auto it = ms.begin();
			// 取出最小的两个小块
			int length_1 = *it++;
			int length_2 = *it++;
			// 删掉后加入两小块拼接成的大块
			ms.erase(ms.begin(), it);
			ms.insert(length_1 + length_2);
			// 更新成本
			cost += (length_1 + length_2);
		}
		return cost;
	}
}

TEST(Code2_2_4_2, Simple)
{
	ASSERT_EQ(34, simple({8, 5, 8}));
}
