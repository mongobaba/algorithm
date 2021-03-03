#include <gtest/gtest.h>
#include <vector>

// �����������
// �����ʱ�����ص�������ͬʱ���롣������Բ���Ĺ������������

namespace
{
	const std::vector<int> start{ 1, 2, 4, 6, 8 };
	// �����Ѿ����ս���ʱ���ź�����
	const std::vector<int> finish{ 3, 5, 7, 9, 10 };

	int simple(std::vector<int> start, std::vector<int> finish)
	{
		int count = 0;
		int last = 0;
		for (size_t i = 0; i < finish.size(); ++i)
		{
			if (start[i] > last)
			{
				++count;
				last = finish[i];
			}
		}
		return count;
	}
}

TEST(Code2_2_2, Simple)
{
	ASSERT_EQ(3, simple(start, finish));
}
