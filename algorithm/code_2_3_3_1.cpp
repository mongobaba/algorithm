#include <gtest/gtest.h>

// ������

namespace
{
	const int n = 4;
	const int m = 3;
	const int M = 10000;

	// dp[0][x] = 1
	// dp[x][0] = 0, x > 0
	int dp[n + 1][m + 1];

	int simple()
	{
		dp[0][0] = 1;

		for (int i = 0; i <= n; i++)
		{
			// j = 0ʱֵΪ0�����ǳ�ʼֵ�����ü���
			for (int j = 1; j <= m; j++)
			{
				if (i >= j) 
				{
					dp[i][j] = (dp[i - j][j] + dp[i][j - 1]) % M;
				}
				else
				{
					dp[i][j] = dp[i][j-1];
				}
			}
		}

		return dp[n][m];
	}
}

TEST(Code2_3_3_1, Simple)
{
	ASSERT_EQ(4, simple());
}
