#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>

using namespace std;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[50][50] = { 0, };
bool visit[50][50] = { false, };

int t, n, m, k;

void dfs(int x, int y)
{
	visit[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < m)
		{
			if (map[nx][ny] == 1)
			{
				if (!visit[nx][ny])
					dfs(nx, ny);
			}
		}
	}
}
int main()
{
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> n >> m >> k;
		for (int i = 0; i < k; i++)
		{
			int x, y;
			cin >> x >> y;
			map[x][y] = 1;
		}

		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (map[i][j] == 1)
				{
					if (!visit[i][j])
					{
						ans++;
						dfs(i, j);
					}
				}
			}
		}
		cout << ans << endl;
		memset(visit, false, sizeof(visit));
		memset(map, 0, sizeof(map));
	}
	return 0;
}