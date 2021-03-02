#include <gtest/gtest.h>
#include <vector>

// ���ֺ�
// ��n������ȡ���ɸ������Ƿ���ʹ��ǡ��Ϊk��

namespace
{
	std::vector<int> a{ 1, 2, 4, 7 };

	// ǰn��Ԫ�غ�Ϊsum
	bool partial_sum(int n, int sum, int k)
	{
		if (sum == k) return true;
		if (n == a.size()) return false;
		// �����±�Ϊn��Ԫ��
		if (partial_sum(n + 1, sum + a[n], k)) return true;
		// �������±�Ϊn��Ԫ��
		else if (partial_sum(n + 1, sum, k)) return true;
		return false;
	}

	bool simple(int k)
	{
		return partial_sum(0, 0, k);
	}
}

TEST(Code2_1_4_1, Simple)
{
	ASSERT_TRUE(simple(13));
	ASSERT_FALSE(simple(15));
}
