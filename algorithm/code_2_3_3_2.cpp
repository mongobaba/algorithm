#include <gtest/gtest.h>

// 多重集组合数

namespace 
{
	const int n = 3;
	const int a[] = { 1, 2, 3 };
	const int m = 3;
	const int M = 10000;

	namespace simple
	{
		// dp[i][j]表示从前i种物品中取j个的组合数
		int dp[n + 1][m + 1];

		int simple()
		{
			// 从前i个一个都不取，总是只有1种方法
			for (int i = 0; i <= n; i++)
			{
				dp[i][0] = 1;
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					for (int k = 0; k <= a[i - 1] && k <= j; k++)
					{
						dp[i][j] += dp[i - 1][j - k];
					}
				}
			}

			return dp[n][m];
		}
	}

	namespace fast
	{
		// dp[i][j]表示从前i种物品中取j个的组合数
		int dp[n + 1][m + 1];

		int fast()
		{
			// 从前i个一个都不取，总是只有1种方法
			for (int i = 0; i <= n; i++)
			{
				dp[i][0] = 1;
			}

			for (int i = 1; i <= n; i++)
			{
				for (int j = 1; j <= m; j++)
				{
					if (j - 1 - a[i-1] >= 0)
					{
						dp[i][j] = (dp[i][j - 1] + dp[i-1][j] - dp[i-1][j - 1 - a[i-1]] + M) % M;
					}
					else
					{
						dp[i][j] = (dp[i][j - 1] + dp[i-1][j]) % M;
					}
				}
			}

			return dp[n][m];
		}
	}
}

TEST(Code2_3_3_2, Simple)
{
	ASSERT_EQ(6, simple::simple());
}

TEST(Code2_3_3_2, Fast)
{
	ASSERT_EQ(6, fast::fast());
}
