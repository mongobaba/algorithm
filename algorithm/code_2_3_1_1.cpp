#include <gtest/gtest.h>
#include <vector>

// ��������

namespace
{
	const int N = 4;	// ��Ʒ����
	const int W = 5;	// ���������
	const int weight[N] = { 2, 1, 3, 2 };
	const int value[N] = { 3, 2, 4, 2 };

	// Ѱ���ĵݹ�ⷨ������ÿһ����Ʒ����Ͳ����뱳�����ַ���
	namespace normal
	{
		// ��һ�������±�Ϊi����Ʒ��wΪ������������������ܻ�õ�����ֵ
		int solve(int i, int w)
		{
			if (i == N)	// ��ͷ��
			{
				return 0;
			}
			else if (weight[i] > w)	// �޷�ѡ�������Ʒ����Ϊ����
			{
				return solve(i + 1, w);	// �������
			}
			else
			{
				// ѡ���߲�ѡ��ȡ��ֵ���
				return (std::max)(
					solve(i + 1, w - weight[i]) + value[i],	// ѡ
					solve(i + 1, w));	// ��ѡ
			}
		}

		int simple()
		{
			return solve(0, W);	// �ӵ�1����ʼ���ԣ�����ΪW
		}
	}

	// ��̬�滮1
	// ǰһ�ַ����ĸĽ�������ֻ�������м����ļ�¼��ʹ��
	namespace dp1
	{
		int dp[N + 1][W + 1];

		// ��һ�������±�Ϊi����Ʒ��wΪ������������������ܻ�õ�����ֵ
		int solve(int i, int w)
		{
			if (dp[i][w] >= 0)
			{
				return dp[i][w];	// ʹ�ý��
			}

			int result = 0;
			if (i == N)
			{
				result = 0;
			}
			else if (weight[i] > w)	// �޷�ѡ�������Ʒ
			{
				result = solve(i + 1, w);
			}
			else
			{
				// ѡ���߲�ѡ��ȡ���
				result = (std::max)(
					value[i] + solve(i + 1, w - weight[i]),	// ѡ
					solve(i + 1, w));	// ��ѡ
			}
			dp[i][w] = result;	// ��¼���
			return result;
		}

		int simple()
		{
			memset(dp, -1, sizeof(dp));	// ��Ҫ��ʼ��
			return solve(0, W);
		}
	}

	// ��̬�滮2
	// ʹ�õ��ƹ�ʽ���ж���ѭ������������
	namespace dp2
	{
		// dp[i][j]��ʾ�ӵ�i����Ʒ��ʼ��ѡ��������������jʱ��Ʒ�ļ�ֵ���ֵ
		// ���ƹ�ʽΪ
		// dp[N][j] = 0
		// dp[i][j] = max(dp[i+1][j],							// ��ʹ�õ�i����Ʒ
		//                dp[i+1][j - weight[i]] + value[i])	// ʹ�õ�i����Ʒ
		int dp[N + 1][W + 1] = { 0 };

		int simple()
		{
			for (int i = N - 1; i >= 0; --i)	// iΪNʱ�̶�Ϊ0�����Դ�N-1�Ƶ�0
			{
				for (int j = 0; j <= W; ++j)	// jΪ0��ʵûʲô�ã�Ҳ�̶�Ϊ0����������Ҳû�д�
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
			return dp[0][W];	// �ӵ�0����ʼ��������������W
		}
	}

	// ��̬�滮3
	// ʹ�õ��ƹ�ʽ���ж���ѭ������������
	namespace dp3
	{
		// dp[i][j]��ʾ��ǰi����Ʒ����ѡ����������������j����Ʒ�ļ�ֵ���ֵ
		// ���ƹ�ʽΪ
		// dp[0][j] = 0
		// dp[i+1][j] = max(dp[i+1][j], dp[i][j])
		// dp[i+1][j+weight[i]] = max(dp[i][j]+value[i], dp[i+1][j+weight[i]])
		// ��Ϊdp[i][j]�����в�ֹһ��·���������ÿ�ζ���Ҫ�ж�һ�£��Ƿ����µ����ֵ
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
			return dp[N][W];	// ǰN����������������W
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
