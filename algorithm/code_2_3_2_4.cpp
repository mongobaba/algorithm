#include <gtest/gtest.h>
#include <tuple>
#include <iostream>
// 最长上升子序列问题

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

		// dp[i][j]表示子序列ai...aj的最大上升子序列的最小最大值和长度
		min_max_t dp[N][N];

		min_max_t get(int i, int j)
		{
			auto& thiz = dp[i][j];
			if (thiz.length == 0)	// 未计算过
			{
				// 递归调用
				auto head = get(i, j - 1);
				auto tail = get(i + 1, j);

				if (a[j] > head.max)	// 只考虑向后扩张
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
					else  // 一样长那就取max小的，跟向后扩张对应
					{
						thiz = head.max < tail.max ? head : tail;
					}
				}
			}
			return thiz;
		}

		int simple()
		{
			// 初始化对角线
			for (int i = 0; i < N; i++)
			{
				dp[i][i] = { a[i], a[i], 1 };
			}
			return get(0, N - 1).length;
		}
	}

	namespace normal2
	{
		// dp[i]表示以a[i]结尾的最长上升子串的长度
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
			// 最长的不一定是以a[N-1]结尾的
			return result;
		}
	}

	namespace fast
	{
		const int INF = 10 * N;

		// dp[i]为长度为i+1的所有上升子序列的末尾元素的最小值
		// INF表示不存在
		int dp[N];

		int simple()
		{
			std::fill(dp, dp + N, INF);
			for (int i = 0; i < N; i++)
			{
				// 从逻辑上分析，dp中除了INF，不可能再有值相等，所以更新最多更新1个位置
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
