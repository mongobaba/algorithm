#include <gtest/gtest.h>
#include <string>
#include <deque>
#include <algorithm>

// 最小字典序字符串
// 根据S构建同样长度的T，使T的字典序最小
// 构建方式：从S的开头或末尾删除一个字符，加入T的末尾

namespace
{
	std::string simple1(const std::string& s)
	{
		// 拷贝一份便于修改
		std::deque<char> dq(s.begin(), s.end());

		std::string result;
		result.reserve(s.size());

		while (!dq.empty())
		{
			std::string s(dq.begin(), dq.end());	// 正序串
			std::string r(dq.rbegin(), dq.rend());	// 逆序串
			if (s <= r)
			{
				result.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				result.push_back(dq.back());
				dq.pop_back();
			}
		}

		return result;
	}

	std::string simple2(const std::string& s)
	{
		// 拷贝一份便于修改
		std::deque<char> dq(s.begin(), s.end());

		std::string result;
		result.reserve(s.size());

		while (!dq.empty())
		{
			if (std::lexicographical_compare(dq.begin(), dq.end(), dq.rbegin(), dq.rend()))
			{
				result.push_back(dq.front());
				dq.pop_front();
			}
			else
			{
				result.push_back(dq.back());
				dq.pop_back();
			}
		}

		return result;
	}
}

TEST(Code2_2_3, Simple1)
{
	ASSERT_EQ("ABCBCD", simple1("ACDBCB"));
}

TEST(Code2_2_3, Simple2)
{
	ASSERT_EQ("ABCBCD", simple2("ACDBCB"));
}
