#include <gtest/gtest.h>
#include <vector>

// 部分和
// 从n个数中取若干个数，是否能使和恰好为k。

namespace
{
	std::vector<int> a{ 1, 2, 4, 7 };

	// 前n个元素和为sum
	bool partial_sum(int n, int sum, int k)
	{
		if (sum == k) return true;
		if (n == a.size()) return false;
		// 包含下标为n的元素
		if (partial_sum(n + 1, sum + a[n], k)) return true;
		// 不包含下标为n的元素
		else if (partial_sum(n + 1, sum, k)) return true;
		return false;
	}

	bool simple(int k)
	{
		return partial_sum(0, 0, k);
	}
}

TEST(Code2_1_4_1, Simple)
{
	ASSERT_TRUE(simple(13));
	ASSERT_FALSE(simple(15));
}
