#include <gtest/gtest.h>
#include <vector>
#include <algorithm>

// ������
// ��n����������ѡ3�����Ƿ�������һ�������Ρ�
// ������ԣ��������ܳ���������ܣ����0��

namespace
{
	std::vector<int> ok{ 2, 3, 4, 5, 10 };		// ����
	std::vector<int> not_ok{ 4,5, 10, 20 };		// ������

	int simple(const std::vector<int>& vec)
	{
		using size_type = std::vector<int>::size_type;
		size_type n = vec.size();
		int result = 0;
		for (size_type a = 0; a < n; ++a)
		{
			for (size_type b = a + 1; b < n; ++b)
			{
				for (size_type c = b + 1; c < n; ++c)
				{
					int sum = vec[a] + vec[b] + vec[c];
					int max = (std::max)(vec[a], (std::max)(vec[b], vec[c]));
					if (max + max < sum)
					{
						result = (std::max)(result, sum);	// �������ֵ
					}
				}
			}
		}
		return result;
	}

	int fast(const std::vector<int>& vec)
	{
		auto sorted(vec);
		std::sort(sorted.begin(), sorted.end());
		for (auto n = sorted.size(); n >= 3; --n)
		{
			if (sorted[n - 3] + sorted[n - 2] > sorted[n - 1])
			{
				return sorted[n - 3] + sorted[n - 2] + sorted[n - 1];
			}
		}
		return 0;
	}
}

TEST(Code1_6_1, Simple)
{
	ASSERT_EQ(12, simple(ok));
	ASSERT_EQ(0, simple(not_ok));
}

TEST(Code1_6_1, Fast)
{
	ASSERT_EQ(12, fast(ok));
	ASSERT_EQ(0, fast(not_ok));
}
