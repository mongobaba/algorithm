#include <gtest/gtest.h>

// ��ǩ
// ��n�������г��4�������ظ������Ƿ������Ӻ����m

namespace
{
	int n = 3;
	int k[] = { 1, 3, 5 };

	bool simple(int m)
	{
		for (int a = 0; a < n; ++a)
		{
			for (int b = 0; b < n; ++b)
			{
				for (int c = 0; c < n; ++c)
				{
					for (int d = 0; d < n; ++d)
					{
						if (k[a] + k[b] + k[c] + k[d] == m)
						{
							return true;
						}
					}
				}
			}
		}
		return false;
	}
}

TEST(Code1_1, Simple)
{
	// ���Եó�10�������޷��ó�9
	ASSERT_TRUE(simple(10));
	ASSERT_FALSE(simple(9));
}
