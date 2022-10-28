#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 51;

char map[MAX][MAX];
bool visited[MAX][MAX];

int n, m;

int dx[] = { 1, -1};
int dy[] = {-1 ,1 };

void bfs(int y, int x)
{
	queue<pair<int, int>> q;
	q.push({ y, x });
	visited[y][x] = true;

	while (!q.empty())
	{
		int xx = q.front().second;
		int yy = q.front().first;
		q.pop();
		if (map[yy][xx] == '-')
		{
			for (int i = 0; i < 2; i++)
			{
				int nx = xx + dx[i];
				if (nx < 0 || nx > m)
					continue;
				if (!visited[yy][nx] && map[yy][nx] == '-')
				{
					q.push({ yy, nx });
					visited[yy][nx] = true;
				}
			}
		}
		else if (map[yy][xx] == '|')
		{
			for (int i = 0; i < 2; i++)
			{
				int ny = yy + dy[i];
				if (ny < 0 || ny>n)
					continue;
				if (!visited[ny][xx] && map[ny][xx] == '|')
				{
					q.push({ ny, xx });
					visited[ny][xx] = true;

				}
			}
		}
		
	}
}

int ans = 0;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			cin >> map[i][j];
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (!visited[i][j])
			{
				bfs(i, j);
				ans++;
			}
		}
	}
	cout << ans << '\n';
	return 0;
}