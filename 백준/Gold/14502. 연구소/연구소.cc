#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 7 + 1;

int map[8][8];
int tmp_map[8][8];

int dx[] = { 1, -1,0,0 };
int dy[] = { 0, 0, -1, 1 };

int n, m, cnt = 0, ans = 0;

void copy_map(int (*a)[8], int (*b)[8])
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j] = b[i][j];
		}
	}
}

void bfs() 
{
	int map2[MAX][MAX];
	copy_map(map2, tmp_map);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map2[i][j] == 2)
				q.push(make_pair(i, j));
		}
	}
	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if(map2[nx][ny] == 0)
			{
				map2[nx][ny] = 2;
				q.push(make_pair(nx, ny));
			}
		}
	}
	int cnt = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map2[i][j] == 0)
				cnt++;
		}
	}
	ans = max(ans, cnt);
}

void make_wall(int num)
{
	if (num == 3)
	{
		bfs();
		return;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (tmp_map[i][j] == 0)
			{
				tmp_map[i][j] = 1;
				make_wall(num + 1);
				tmp_map[i][j] = 0;
			}
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				copy_map(tmp_map, map);
				tmp_map[i][j] = 1;
				make_wall(1);
				tmp_map[i][j] = 0;
			}
		}
	}
	cout << ans << endl;
	return 0;
}