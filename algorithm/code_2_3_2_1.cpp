#include <gtest/gtest.h>

// ��ȫ��������

namespace
{
	const int N = 3;
	const int W = 7;
	const int weight[] = { 3, 4, 2 };
	const int value[] = { 4, 5, 3 };

	namespace normal
	{
		int dp[N + 1][W + 1];

		// �򵥴���
		// ���ƹ�ʽΪ
		// dp[i+1][j] = max{dp[i][j-k*w[i]] + k*v[i]; k>=0��j-k*w[i]>=0}
		// ����Ҫ������ô�Ƶ�dp[i][j+1]������Ĺ�ʽ�͹���
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

		// �򵥴���
		// ���ƹ�ʽΪ
		// dp[i+1][j] = max{dp[i][j], dp[i+1][j-w[i]] + v[i]; j-w[i]>=0}
		// ֱ������ǣ�Ҫô��ѡi��Ҫôѡ1��i֮�������i���￪ʼѡ
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
		// �ڴ��Ż��汾
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
