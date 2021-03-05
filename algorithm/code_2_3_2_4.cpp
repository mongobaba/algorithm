#include <gtest/gtest.h>
#include <tuple>
#include <iostream>
// ���������������

namespace
{
	const int N = 5;
	const int a[] = { 4, 2, 3, 1, 5 };

	namespace normal1
	{
		struct min_max_t
		{
			int min;
			int max;
			int length;
		};

		// dp[i][j]��ʾ������ai...aj��������������е���С���ֵ�ͳ���
		min_max_t dp[N][N];

		min_max_t get(int i, int j)
		{
			auto& thiz = dp[i][j];
			if (thiz.length == 0)	// δ�����
			{
				// �ݹ����
				auto head = get(i, j - 1);
				auto tail = get(i + 1, j);

				if (a[j] > head.max)	// ֻ�����������
				{
					thiz = { head.min, a[j], head.length + 1 };
				}
				else
				{
					if (head.length > tail.length)
					{
						thiz = head;
					}
					else if (head.length < tail.length)
					{
						thiz = tail;
					}
					else  // һ�����Ǿ�ȡmaxС�ģ���������Ŷ�Ӧ
					{
						thiz = head.max < tail.max ? head : tail;
					}
				}
			}
			return thiz;
		}

		int simple()
		{
			// ��ʼ���Խ���
			for (int i = 0; i < N; i++)
			{
				dp[i][i] = { a[i], a[i], 1 };
			}
			return get(0, N - 1).length;
		}
	}

	namespace normal2
	{
		// dp[i]��ʾ��a[i]��β��������Ӵ��ĳ���
		int dp[N];

		int simple()
		{
			int result = 0;
			for (int i = 0; i < N; i++)
			{
				dp[i] = 1;
				for (int j = 0; j < i; j++)
				{
					if (a[j] < a[i])
					{
						dp[i] = (std::max)(dp[i], dp[j] + 1);
					}
				}
				result = (std::max)(result, dp[i]);
			}
			// ��Ĳ�һ������a[N-1]��β��
			return result;
		}
	}

	namespace fast
	{
		const int INF = 10 * N;

		// dp[i]Ϊ����Ϊi+1���������������е�ĩβԪ�ص���Сֵ
		// INF��ʾ������
		int dp[N];

		int simple()
		{
			std::fill(dp, dp + N, INF);
			for (int i = 0; i < N; i++)
			{
				// ���߼��Ϸ�����dp�г���INF������������ֵ��ȣ����Ը���������1��λ��
				*std::lower_bound(dp, dp + N, a[i]) = a[i];
			}
			int* first_inf = std::lower_bound(dp, dp + N, INF);
			return int(first_inf - dp);
		}
	}
}

TEST(Code2_3_2_4, Simple)
{
	ASSERT_EQ(3, normal1::simple());
}

TEST(Code2_3_2_4, Simple2)
{
	ASSERT_EQ(3, normal2::simple());
}

TEST(Code2_3_2_4, Fast)
{
	ASSERT_EQ(3, fast::simple());
}
