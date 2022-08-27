#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 1000 +1;

int dx[] = { -1, 1, 0,0 };
int dy[] = { 0, 0, 1, -1 };

queue<pair<int, int>> q;
int n, m;
int map[MAX][MAX] = { 0, };

int ans = 0;

void bfs()
{
	while (!q.empty())
	{
		int fx = q.front().first;
		int fy = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m )
				continue;
			if (map[nx][ny] == 0)
			{
				map[nx][ny] = map[fx][fy] + 1;
				q.push(make_pair(nx, ny));
				
			}
		}
	}
}



int main(void)
{
	cin >> m >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
			
			if (map[i][j] == 1)
				q.push(make_pair(i, j));
		}
	}

	bfs();
	bool ck = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 0)
			{
				ck = false;
			}
			if (ans < map[i][j])
				ans = map[i][j];
		}
	}
	if (ck)
		cout << ans - 1 << endl;
	else
		cout << -1 << endl;
	return 0;

}
