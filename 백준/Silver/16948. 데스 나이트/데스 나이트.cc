#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include<cstring>

using namespace std;

const int MAX = 300 + 1;

int t, n, cnt = 0;
int start_x, start_y, end_x, end_y;

int dy[] = { -1,1,-2,2,-1,1 };
int dx[] = { -2,-2,0,0,2,2 };

int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };

void bfs(int sx, int sy)
{
	queue < pair<int, int> > q;

	visited[sx][sy] = true;
	q.push(make_pair(sx, sy));

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (x == end_x && y == end_y)
		{
			cout << map[x][y] << endl;
			return;
		}
		for (int i = 0; i < 6; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (!visited[nx][ny])
			{
				visited[nx][ny] = 1;
				q.push(make_pair(nx, ny));
				map[nx][ny] = map[x][y] + 1;
			}
		}
	}
	cout << -1 << endl;
}

int main(void)
{
	cin >> n;
	cin >> start_x >> start_y >> end_x >> end_y;
	bfs(start_x, start_y);

	return 0;
}
