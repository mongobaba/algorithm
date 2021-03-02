#include <gtest/gtest.h>

// 水坑
// 求水坑个数

namespace
{
	const int N = 10;
	const int M = 12;
	char area[N][M + 1] = {
		{"W........WW."},
		{".WWW.....WWW"},
		{"....WW...WW."},
		{".........WW."},
		{".........W.."},
		{"..W......W.."},
		{".W.W.....WW."},
		{"W.W.W.....W."},
		{".W.W......W."},
		{"..W.......W."},
	};

	void deep_search(int x, int y)
	{
		for (int i = -1; i <= 1; ++i)
		{
			for (int j = -1; j <= 1; ++j)
			{
				int nx = x + i;
				int ny = y + j;
				if (0 <= nx && nx < M &&
					0 <= ny && ny < N &&
					area[ny][nx] == 'W')
				{
					area[ny][nx] = '#';
					deep_search(nx, ny);
				}
			}
		}
	}

	int simple()
	{
		int count = 0;
		for (int x = 0; x < M; x++)
		{
			for (int y = 0; y < N; y++)
			{
				if (area[y][x] == 'W')
				{
					deep_search(x, y);
					++count;
				}
			}
		}
		return count;
	}
}

TEST(Code2_1_4_2, Simple)
{
	ASSERT_EQ(3, simple());
}
