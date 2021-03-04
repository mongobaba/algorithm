#include <gtest/gtest.h>
#include <string>

// �����������

namespace
{
	// dp[i][j]��ʾs[1]...s[i]��t[1]...t[j]������������еĳ���
	// �ڳ����ϣ���ʾs[0]...s[i-1]��t[0]...t[j-1]������������еĳ���
	// ���ƹ�ʽΪ
	// dp[i+1][j+1]=max(dp[i][j]+1,dp[i+1][j],dp[i][j+1]) ���s[i+1]==t[j+1]
	// dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]) �������
	// max(dp[i][j]+1,dp[i+1][j],dp[i][j+1])�ֿ��Լ�Ϊdp[i][j]+1
	int simple(const std::string& s1, const std::string& s2)
	{
		std::vector<std::vector<int>> dp{ s1.size() + 1 };
		for (auto& v : dp)
		{
			v.assign(s1.size() + 1, 0);
		}

		for (size_t i = 0; i < s1.size(); i++)
		{
			for (size_t j = 0; j < s2.size(); j++)
			{
				if (s1[i] == s2[j])
				{
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else
				{
					dp[i + 1][j + 1] = (std::max)(dp[i + 1][j], dp[i][j + 1]);
				}
			}
		}

		return dp[s1.size()][s2.size()];
	}
}

TEST(Code2_3_1_2, Simple)
{
	ASSERT_EQ(3, simple("abcd", "becd"));
}
