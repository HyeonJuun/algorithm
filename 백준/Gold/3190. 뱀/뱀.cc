#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 100 + 1;

int n, k, l, sec = 0;

char c;

int map[MAX][MAX];
bool snake_body[MAX][MAX];

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

char snake_move[10001];

queue<pair<int, int>> snake;

void solve()
{
	snake.push({ 1, 1 });
	int i = 1;
	snake_body[1][1] = true;

	while (true)
	{
		sec++;

		int nx = snake.back().second + dx[i];
		int ny = snake.back().first + dy[i];


		if (ny <1 || ny > n || nx <1 || nx >n)
			return;
		snake.push({ ny, nx });

		if (snake_move[sec] == 'D')
		{
			if (i == 1)
				i = 0;
			else if (i == 2)
				i = 1;
			else if (i == 3)
				i = 2;
			else if( i== 0)
				i = 3;
		}
		else if (snake_move[sec] == 'L')
		{
			if (i == 1)
				i = 2;
			else if (i == 2)
				i = 3;
			else if (i == 3)
				i = 0;
			else if (i == 0)
				i = 1;
		}

		if (map[ny][nx] == 1)
			map[ny][nx] = 0;
		else
		{
			if (snake_body[ny][nx])
				return;
			snake_body[snake.front().first][snake.front().second] = false;
			snake.pop();
		}
		if (snake_body[ny][nx])
			return;
		else
			snake_body[ny][nx] = true;
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> y >> x;
		map[y][x] = 1;
	}
	cin >> l;
	for (int i = 0; i < l; i++)
	{
		int smove;	char m;
		cin >> smove >> m;
		snake_move[smove] = m;
	}
	solve();
	cout << sec << '\n';
	return 0;
}