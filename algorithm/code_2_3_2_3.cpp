#include <gtest/gtest.h>

// ���ز��ֺ�����

namespace 
{
	const int N = 3;
	const int V[] = { 3, 5, 8 };
	const int M[] = { 3, 2, 2 };
	const int S = 17;

	namespace normal
	{
		// dp[i][j]��ʾ��ǰi�������Ƿ������ӵó�j
		bool dp[N + 1][S + 1];

		bool simple()
		{
			dp[0][0] = true;
			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j <= S; j++)
				{
					// ����ʹ�ò�ͬ������iԪ��
					for (int k = 0; k <= M[i] && k * V[i] <= j; k++)
					{
						dp[i + 1][j] |= dp[i][j - k * V[i]];
					}
				}
			}
			return dp[N][S];
		}
	}

	namespace fast1
	{
		// dp[i][j]��ʾ��ǰi��������ӵó�jʱ��i-1���ֻ�ʣ�µĸ���
		int dp[N + 1][S + 1];

		bool simple()
		{
			memset(dp, -1, sizeof(dp));
			dp[0][0] = 0;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j <= S; j++)
				{
					if (dp[i][j] >= 0)
					{
						dp[i + 1][j] = M[i];
					}
					else if (j < V[i] || dp[i + 1][j - V[i]] <= 0)
					{
						dp[i + 1][j] = -1;
					}
					else
					{
						dp[i + 1][j] = dp[i + 1][j - V[i]] - 1;
					}
				}
			}
			return dp[N][S] >= 0;
		}
	}

	// ѹ���ռ�
	namespace fast2
	{
		// dp[j]��ʾ��ǰi��������ӵó�jʱ��i-1���ֻ�ʣ�µĸ���
		int dp[S + 1];

		bool simple()
		{
			memset(dp, -1, sizeof(dp));
			dp[0] = 0;

			for (int i = 0; i < N; i++)
			{
				for (int j = 0; j <= S; j++)
				{
					if (dp[j] >= 0)
					{
						dp[j] = M[i];
					}
					else if (j < V[i] || dp[j - V[i]] <= 0)
					{
						dp[j] = -1;
					}
					else
					{
						dp[j] = dp[j - V[i]] - 1;
					}
				}
			}
			return dp[S] >= 0;
		}
	}
}

TEST(Code2_3_2_3, Simple)
{
	ASSERT_TRUE(normal::simple());
}

TEST(Code2_3_2_3, Fast1)
{
	ASSERT_TRUE(fast1::simple());
}

TEST(Code2_3_2_3, Fast2)
{
	ASSERT_TRUE(fast2::simple());
}
