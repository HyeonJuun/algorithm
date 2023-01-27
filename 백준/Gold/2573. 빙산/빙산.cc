#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include<cmath>
#include<queue>

using namespace std;

const int MAX = 300 + 1;

int n, m;
int map[MAX][MAX];
bool visited[MAX][MAX];
int tmp[MAX][MAX];
int ans = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

queue<pair<int, int>> q;

void bfs()
{
	memset(tmp, 0, sizeof(tmp));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
				continue;
			int cntWater = 0;
			for (int k = 0; k < 4; k++)
			{
				int nx = i + dx[k];
				int ny = j + dy[k];
				if (nx < 0 || ny < 0 || nx >= n || ny >= m)
					continue;
				if (map[nx][ny] == 0)
					cntWater++;
			}
			//if (map[i][j] - cntWater < 0)
			//	map[i][j] = 0;
			//else
			//	map[i][j] -= cntWater;
			int val = map[i][j] - cntWater;
			if (val > 0)
				tmp[i][j] = val;
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
			map[i][j] = tmp[i][j];
	}
}
void ck(int x, int y)
{
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty())
	{
		int curx = q.front().first;
		int cury = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i ++ )
		{
			int nx = curx + dx[i];
			int ny = cury + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] && !visited[nx][ny])
			{
				q.push({ nx, ny });
				visited[nx][ny] = true;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	while (true)
	{
		int cnt = 0;
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < m; j++)
			{
				if (!visited[i][j] && map[i][j] != 0)
				{
					ck(i, j);
					cnt++;

				}
			}
		}
		if (cnt == 0)
		{
			cout << 0;
			break;
		}
		else if (cnt >= 2)
		{
			cout << ans;
			break;
		}
		ans++;
		bfs();
		memset(visited, false, sizeof(visited));
	}
	return 0;
}