#include <gtest/gtest.h>
#include <vector>

// 硬币问题
// 用尽可能少的硬币组成指定的面额

namespace
{
	const std::vector<int> values =  { 1, 5, 10, 50, 100, 500 };
	const std::vector<int> numbers = { 3, 2,  1,  3,   0,   2 };

	// values和numbers拷贝一份，避免修改全局数据
	int simple(int total, std::vector<int> values, std::vector<int> numbers)
	{
		int count = 0;
		auto index = values.size();		// 无符号类型，要避免越界
		while (total > 0 && index-- > 0)
		{
			int use = (std::min)(total / values[index], numbers[index]);
			count += use;
			numbers[index] -= use;
			total -= use * values[index];
		}
		// total不为0说明拼不出来
		return total == 0 ? count : -1;
	}
}

TEST(Code2_2_1, Simple)
{
	ASSERT_EQ(6, simple(620, values, numbers));
	ASSERT_EQ(3, simple(600, values, numbers));
	ASSERT_EQ(-1, simple(14, values, numbers));
}
