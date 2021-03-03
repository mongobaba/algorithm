#include <gtest/gtest.h>
#include <vector>
#include <set>

// ľ���и�����
// ľ���и��NС�飬�и�ɱ���ľ�鳤�ȳ����ȣ�������С�и�ɱ���

namespace
{
	int simple(const std::vector<int>& vec)
	{
		int cost = 0;
		std::multiset<int> ms(vec.begin(), vec.end());
		while (ms.size() > 1)
		{
			auto it = ms.begin();
			// ȡ����С������С��
			int length_1 = *it++;
			int length_2 = *it++;
			// ɾ���������С��ƴ�ӳɵĴ��
			ms.erase(ms.begin(), it);
			ms.insert(length_1 + length_2);
			// ���³ɱ�
			cost += (length_1 + length_2);
		}
		return cost;
	}
}

TEST(Code2_2_4_2, Simple)
{
	ASSERT_EQ(34, simple({8, 5, 8}));
}
