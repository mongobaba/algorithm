#include <gtest/gtest.h>

// 完全背包问题

namespace
{
	const int N = 3;
	const int W = 7;
	const int weight[] = { 3, 4, 2 };
	const int value[] = { 4, 5, 3 };

	namespace normal
	{
		int dp[N + 1][W + 1];

		// 简单处理
		// 递推公式为
		// dp[i+1][j] = max{dp[i][j-k*w[i]] + k*v[i]; k>=0且j-k*w[i]>=0}
		// 不需要考虑怎么推导dp[i][j+1]，上面的公式就够了
		int simple()
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j <= W; j++)
				{
					for (int k = 0; k * weight[i] <= j; k++)
					{
						dp[i + 1][j] = (std::max)(dp[i + 1][j], dp[i][j - k * weight[i]] + k * value[i]);
					}
				}
			}
			return dp[N][W];
		}
	}

	namespace fast1
	{
		int dp[N + 1][W + 1];

		// 简单处理
		// 递推公式为
		// dp[i+1][j] = max{dp[i][j], dp[i+1][j-w[i]] + v[i]; j-w[i]>=0}
		// 直观理解是：要么不选i，要么选1个i之后继续从i这里开始选
		int simple()
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j <= W; j++)
				{
					if (j >= weight[i])
					{
						dp[i + 1][j] = (std::max)(dp[i][j], dp[i + 1][j - weight[i]] + value[i]);
					}
					else
					{
						dp[i + 1][j] = dp[i][j];
					}
				}
			}
			return dp[N][W];
		}
	}

	namespace fast2
	{
		// 内存优化版本
		int dp[W + 1];

		int simple()
		{
			for (int i = 0; i < N; i++)
			{
				for (int j = weight[i]; j <= W; j++)
				{
					dp[j] = (std::max)(dp[j], dp[j - weight[i]] + value[i]);
				}
			}
			return dp[W];
		}
	}
}

TEST(Code2_3_2_1, Simple)
{
	ASSERT_EQ(10, normal::simple());
}

TEST(Code2_3_2_1, Fast1)
{
	ASSERT_EQ(10, fast1::simple());
}

TEST(Code2_3_2_1, Fast2)
{
	ASSERT_EQ(10, fast2::simple());
}
