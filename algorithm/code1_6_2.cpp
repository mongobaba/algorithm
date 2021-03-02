#include <gtest/gtest.h>
#include <utility>

// ����
// nֻ��������������У����������ϴ���͵����������Сʱ�䡣
// ��������ʱ���ͷ����Ϳ��ֻ������һֻ�������С�

namespace
{
	int L = 10;
	int n = 3;
	int x[] = { 2, 6, 7 };

	std::pair<int, int> simple()
	{
		int min = 0, max = 0;
		for (int i = 0; i < n; ++i)
		{
			// ��ֻ���ϴ���͵���������Сֵ
			int min_fall = (std::min)(x[i], L - x[i]);
			int max_fall = (std::max)(x[i], L - x[i]);

			// �������϶����䣬���������ֵ
			min = (std::max)(min, min_fall);

			max = (std::max)(max, max_fall);
		}
		return { min, max };
	}
}

TEST(Code1_6_2, Simple)
{
	ASSERT_EQ(std::make_pair(4, 8), simple());
}
