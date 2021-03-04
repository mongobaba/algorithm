#include <gtest/gtest.h>
#include <vector>

// 背包问题

namespace
{
	const int N = 4;	// 物品个数
	const int W = 5;	// 最大总重量
	const int weight[N] = { 2, 1, 3, 2 };
	const int value[N] = { 3, 2, 4, 2 };

	// 寻常的递归解法，尝试每一个物品放入和不放入背包两种方案
	namespace normal
	{
		// 下一步尝试下标为i的物品，w为还允许的重量，返回能获得的最大价值
		int solve(int i, int w)
		{
			if (i == N)	// 到头了
			{
				return 0;
			}
			else if (weight[i] > w)	// 无法选择这个物品，因为超重
			{
				return solve(i + 1, w);	// 看后面的
			}
			else
			{
				// 选或者不选，取价值大的
				return (std::max)(
					solve(i + 1, w - weight[i]) + value[i],	// 选
					solve(i + 1, w));	// 不选
			}
		}

		int simple()
		{
			return solve(0, W);	// 从第1个开始尝试，总重为W
		}
	}

	// 动态规划1
	// 前一种方法的改进，单纯只是增加中间结果的记录和使用
	namespace dp1
	{
		int dp[N + 1][W + 1];

		// 下一步尝试下标为i的物品，w为还允许的重量，返回能获得的最大价值
		int solve(int i, int w)
		{
			if (dp[i][w] >= 0)
			{
				return dp[i][w];	// 使用结果
			}

			int result = 0;
			if (i == N)
			{
				result = 0;
			}
			else if (weight[i] > w)	// 无法选择这个物品
			{
				result = solve(i + 1, w);
			}
			else
			{
				// 选或者不选，取大的
				result = (std::max)(
					value[i] + solve(i + 1, w - weight[i]),	// 选
					solve(i + 1, w));	// 不选
			}
			dp[i][w] = result;	// 记录结果
			return result;
		}

		int simple()
		{
			memset(dp, -1, sizeof(dp));	// 需要初始化
			return solve(0, W);
		}
	}

	// 动态规划2
	// 使用递推公式进行二次循环遍历（逆序）
	namespace dp2
	{
		// dp[i][j]表示从第i个物品开始挑选，总重量不超过j时物品的价值最大值
		// 递推公式为
		// dp[N][j] = 0
		// dp[i][j] = max(dp[i+1][j],							// 不使用第i个物品
		//                dp[i+1][j - weight[i]] + value[i])	// 使用第i个物品
		int dp[N + 1][W + 1] = { 0 };

		int simple()
		{
			for (int i = N - 1; i >= 0; --i)	// i为N时固定为0，所以从N-1推到0
			{
				for (int j = 0; j <= W; ++j)	// j为0其实没什么用，也固定为0，不过加上也没有错
				{
					if (j < weight[i])
					{
						dp[i][j] = dp[i + 1][j];
					}
					else
					{
						dp[i][j] = (std::max)(dp[i + 1][j], dp[i + 1][j - weight[i]] + value[i]);
					}
				}
			}
			return dp[0][W];	// 从第0个开始，总重量不超过W
		}
	}

	// 动态规划3
	// 使用递推公式进行二次循环遍历（正序）
	namespace dp3
	{
		// dp[i][j]表示从前i个物品中挑选出的总重量不超过j的物品的价值最大值
		// 递推公式为
		// dp[0][j] = 0
		// dp[i+1][j] = max(dp[i+1][j], dp[i][j])
		// dp[i+1][j+weight[i]] = max(dp[i][j]+value[i], dp[i+1][j+weight[i]])
		// 因为dp[i][j]可能有不止一条路径到达，所以每次都需要判断一下，是否有新的最大值
		int dp[N + 1][W + 1] = { 0 };

		int simple()
		{
			for (int i = 0; i < N; ++i)
			{
				for (int j = 0; j <= W; ++j)
				{
					dp[i + 1][j] = (std::max)(dp[i + 1][j], dp[i][j]);
					if (j + weight[i] <= W)
					{
						dp[i + 1][j + weight[i]] = (std::max)(dp[i + 1][j + weight[i]], dp[i][j] + value[i]);
					}
				}
			}
			return dp[N][W];	// 前N个，总总量不超过W
		}
	}
}

TEST(Code2_3_1, Simple)
{
	ASSERT_EQ(7, normal::simple());
}

TEST(Code2_3_1, DP1)
{
	ASSERT_EQ(7, dp1::simple());
}

TEST(Code2_3_1, DP2)
{
	ASSERT_EQ(7, dp2::simple());
}

TEST(Code2_3_1, DP3)
{
	ASSERT_EQ(7, dp3::simple());
}
