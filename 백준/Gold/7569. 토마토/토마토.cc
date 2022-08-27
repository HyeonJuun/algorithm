#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 100 +1;

int dx[] = { -1, 1, 0,0 , 0, 0};
int dy[] = { 0, 0, 1, -1, 0 ,0 };
int dz[] = { 0, 0, 0, 0, 1, -1 };

queue<pair<int, pair<int, int>>> q;
int n, m, h;
int map[MAX][MAX][MAX] = { 0, };

int ans = 0;

void bfs()
{
	while (!q.empty())
	{
		int fz = q.front().first;
		int fx = q.front().second.first;
		int fy = q.front().second.second;

		q.pop();
		for (int i = 0; i < 6; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			int nz = fz + dz[i];

			if (nx < 0 || ny < 0 || nz < 0 || nx >= n|| ny >= m || nz >= h)
				continue;
			if (map[nz][nx][ny] == 0)
			{
				map[nz][nx][ny] = map[fz][fx][fy] + 1;
				q.push(make_pair(nz, (make_pair(nx, ny))));
			}
		}
	}
}



int main(void)
{
	cin >> m >> n >> h;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				cin >> map[i][j][k];

				if (map[i][j][k] == 1)
					q.push(make_pair(i, (make_pair(j, k))));
			}
		}
	}

	bfs();
	bool ck = true;
	for (int i = 0; i < h; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < m; k++)
			{
				if (map[i][j][k] == 0)
				{
					ck = false;
				}
				if (ans < map[i][j][k])
					ans = map[i][j][k];
			}
			
		}
	}
	if (ck)
		cout << ans - 1 << endl;
	else
		cout << -1 << endl;
	return 0;

}
