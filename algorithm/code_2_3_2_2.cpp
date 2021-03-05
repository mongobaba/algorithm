#include <gtest/gtest.h>

// 0-1背包问题
// W区间较大，但是V区间较小

namespace
{
	const int N = 4;			// 物品个数
	const int W = 5;			// 重量上限
	const int MAX_VALUE = 100;	// 价值最大值
	const int weight[] = { 2, 1, 3, 2 };
	const int value[] = { 3, 2, 4, 2 };

	// 设置为INF表示不存在此方案
	const int INF = 1000000;
	// dp[i][j]表示从前i个中选取价值等于j的物品时，重量的最小值
	int dp[N + 1][N * MAX_VALUE + 1];

	int simple()
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N * MAX_VALUE; j++)
			{
				dp[i][j] = INF;
			}
		}
		dp[0][0] = 0;

		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j <= N * MAX_VALUE; j++)
			{
				if (j >= value[i])
				{
					dp[i + 1][j] = (std::min)(
						dp[i][j - value[i]] + weight[i],	// 选取i
						dp[i][j]);							// 不选i
				}
				else
				{
					dp[i + 1][j] = dp[i][j];				// 无法选i
				}
			}
		}

		int result = 0;

		// 正序遍历完，找最后一个
		//for (int j = 0; j <= N * MAX_VALUE; j++)
		//{
		//	if (dp[N][j] <= W)
		//	{
		//		result = j;
		//	}
		//}

		// 反序找第一个
		for (int j = N * MAX_VALUE; j >= 0; j--)
		{
			if (dp[N][j] <= W)
			{
				result = j;
				break;
			}
		}

		return result;
	}
}

TEST(Code2_3_2_2, Simple)
{
	ASSERT_EQ(7, simple());
}
