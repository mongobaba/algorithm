#include <gtest/gtest.h>
#include <algorithm>
#include <iostream>
using namespace std;

// 另外两种枚举/遍历方式

namespace
{
	const int N = 3;
	const string expected = 
		"0 1 2\n"
		"0 2 1\n"
		"1 0 2\n"
		"1 2 0\n"
		"2 0 1\n"
		"2 1 0\n";
	stringstream output;

	template <typename Iterator>
	void display(stringstream& os, Iterator begin, Iterator end)
	{
		while (begin != end)
		{
			os << *begin;
			if (++begin != end)
			{
				os << ' ';
			}
		}
		os << endl;
	}

	bool used[N];
	int perm[N];

	void permutaion_1(int pos, int n)
	{
		if (pos == n)
		{
			display(output, begin(perm), end(perm));
			return;
		}
		for (int i = 0; i < n; i++)
		{
			if (!used[i])
			{
				perm[pos] = i;
				used[i] = true;
				permutaion_1(pos + 1, n);
				used[i] = false;
			}
		}
	}

	void permutaion_2(int n)
	{
		for (int i = 0; i < n; i++)
		{
			perm[i] = i;
		}
		do
		{
			display(output, begin(perm), end(perm));
		} while (next_permutation(begin(perm), end(perm)));
	}
}

TEST(Code2_1_6, Permutaion_1)
{
	output.str("");
	permutaion_1(0, N);
	ASSERT_EQ(expected, output.str());
}

TEST(Code2_1_6, Permutaion_2)
{
	output.str("");
	permutaion_2(N);
	ASSERT_EQ(expected, output.str());
}
