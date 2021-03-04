#include <gtest/gtest.h>
#include <string>

// 最长公共子序列

namespace
{
	// dp[i][j]表示s[1]...s[i]与t[1]...t[j]的最长公共子序列的长度
	// 在程序上，表示s[0]...s[i-1]与t[0]...t[j-1]的最长公共子序列的长度
	// 递推公式为
	// dp[i+1][j+1]=max(dp[i][j]+1,dp[i+1][j],dp[i][j+1]) 如果s[i+1]==t[j+1]
	// dp[i+1][j+1]=max(dp[i+1][j],dp[i][j+1]) 其他情况
	// max(dp[i][j]+1,dp[i+1][j],dp[i][j+1])又可以简化为dp[i][j]+1
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
