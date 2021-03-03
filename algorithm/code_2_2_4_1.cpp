#include <gtest/gtest.h>
#include <vector>
#include <cassert>

// ����

namespace
{
	int simple(const std::vector<int>& vec, int r)
	{
		int count = 0;
		size_t i = 0;			// û�б����ǵĵ�һ������±�
		while (i < vec.size())	// �������û�����ǵ�
		{
			// û�б����ǵĵ�һ�����λ��
			int pos = vec[i];
			// �ҳ�����Χ�ĵ�һ���㣬��ǰһ����Ҫ�����
			while (i < vec.size() && vec[i] - pos <= r) ++i;
			// ���i - 1
			++count;
			// ��¼i - 1��λ��
			pos = vec[i - 1];
			// Ȼ����ܱ�i - 1���ǵĵ�ȫ���ų�
			while (i < vec.size() && vec[i] - pos <= r) ++i;
		}
		return count;
	}
}

TEST(Code2_2_4, Simple)
{
	std::vector<int> v1{ 1, 7, 15, 20, 30, 50 };
	ASSERT_EQ(3, simple(v1, 10));
}

TEST(Code2_2_4, AllShouldBeMarked)
{
	std::vector<int> v2{ 1, 50, 100, 200, 500 };
	ASSERT_EQ(5, simple(v2, 10));
}
