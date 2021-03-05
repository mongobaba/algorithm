#include <gtest/gtest.h>

// 0-1��������
// W����ϴ󣬵���V�����С

namespace
{
	const int N = 4;			// ��Ʒ����
	const int W = 5;			// ��������
	const int MAX_VALUE = 100;	// ��ֵ���ֵ
	const int weight[] = { 2, 1, 3, 2 };
	const int value[] = { 3, 2, 4, 2 };

	// ����ΪINF��ʾ�����ڴ˷���
	const int INF = 1000000;
	// dp[i][j]��ʾ��ǰi����ѡȡ��ֵ����j����Ʒʱ����������Сֵ
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
						dp[i][j - value[i]] + weight[i],	// ѡȡi
						dp[i][j]);							// ��ѡi
				}
				else
				{
					dp[i + 1][j] = dp[i][j];				// �޷�ѡi
				}
			}
		}

		int result = 0;

		// ��������꣬�����һ��
		//for (int j = 0; j <= N * MAX_VALUE; j++)
		//{
		//	if (dp[N][j] <= W)
		//	{
		//		result = j;
		//	}
		//}

		// �����ҵ�һ��
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
