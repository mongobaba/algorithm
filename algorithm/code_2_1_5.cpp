#include <gtest/gtest.h>
#include <utility>
#include <deque>

// �Թ����·��

namespace
{
	// ��������
	const int N = 10;	// ��
	const int M = 10;	// ��
	char area[][M + 1] = {
		"#S######.#",
		"......#..#",
		".#.##.##.#",
		".#........",
		"##.##.####",
		"....#....#",
		".#######.#",
		"....#.....",
		".####.###.",
		"....#...G#",
	};

	// �������ݺͽṹ
	using position = std::pair<int, int>;
	const int INF = 2 * N * M;
	int distance[N][M] = { 0 };

	position find_start()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (area[i][j] == 'S')
					return { i, j };
			}
		}
		return { -1, -1 };
	}

	position find_finish()
	{
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				if (area[i][j] == 'G')
					return { i, j };
			}
		}
		return { -1, -1 };
	}

	bool in_area(int x, int y)
	{
		return x >= 0 && x < M && y >= 0 && y < N;
	}

	int simple()
	{
		position start = find_start();
		position finish = find_finish();

		// ��ʼ������
		for (int i = 0; i < N; ++i)
		{
			for (int j = 0; j < M; ++j)
			{
				distance[i][j] = INF;
			}
		}
		// ��ʼλ�þ���Ϊ0
		distance[start.first][start.second] = 0;

		std::deque<position> dq;
		// ������ʼ��
		dq.push_back(start);
		area[start.first][start.second] = '*';
		
		const int dy[] = { 0, -1, 0, 1 };	// �еĸı�������������
		const int dx[] = { -1, 0, 1, 0 };	// �еĸı�������������

		while (!dq.empty())
		{
			position top = dq.front();
			dq.pop_front();

			for (int i = 0; i < 4; ++i)
			{
				int y = top.first + dy[i];
				int x = top.second + dx[i];
				if (in_area(x, y) && (area[y][x] == '.' || area[y][x] == 'G'))
				{
					dq.push_back(position{ y, x });
					area[y][x] = '*';
					distance[y][x] = (std::min)(distance[y][x], distance[top.first][top.second] + 1);
				}
			}
		}

		return distance[finish.first][finish.second];
	}
}

TEST(Code2_1_5, FindStart)
{
	position expected{ 0, 1 };
	ASSERT_EQ(expected, find_start());
}

TEST(Code2_1_5, FindFinish)
{
	position expected{ 9, 8 };
	ASSERT_EQ(expected, find_finish());
}

TEST(Code2_1_5, InArea)
{
	ASSERT_TRUE(in_area(0, 0));
	ASSERT_FALSE(in_area(0, -1));
	ASSERT_FALSE(in_area(-1, 0));
	ASSERT_FALSE(in_area(0, 10));
	ASSERT_FALSE(in_area(10, 0));
}

TEST(Code2_1_5, Simple)
{
	ASSERT_EQ(22, simple());
}
