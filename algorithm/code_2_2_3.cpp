#include <gtest/gtest.h>
#include <string>
#include <deque>
#include <algorithm>

// ��С�ֵ����ַ���
// ����S����ͬ�����ȵ�T��ʹT���ֵ�����С
// ������ʽ����S�Ŀ�ͷ��ĩβɾ��һ���ַ�������T��ĩβ

namespace
{
	std::string simple1(const std::string& s)
	{
		// ����һ�ݱ����޸�
		std::deque<char> dq(s.begin(), s.end());

		std::string result;
		result.reserve(s.size());

		while (!dq.empty())
		{
			std::string s(dq.begin(), dq.end());	// ����
			std::string r(dq.rbegin(), dq.rend());	// ����
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
		// ����һ�ݱ����޸�
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
