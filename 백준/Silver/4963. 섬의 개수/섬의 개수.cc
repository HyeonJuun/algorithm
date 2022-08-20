#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>;
using namespace std;
int map[51][51] = { 0, };
bool visited[51][51] = { false, };

int dx[8] = { 1, 1, 0, -1, -1, -1, 0, 1 };
int dy[8] = { 0, 1, 1, 1, 0, -1, -1, -1 };

int w, h;
queue<pair<int, int>> q;

void bfs()
{
	while (!q.empty())
	{
		int x = q.front().second;
		int y = q.front().first;
		q.pop();
		for (int i = 0; i < 8; i++)
		{
			int next_x = x + dx[i];
			int next_y = y + dy[i];
			if (next_x < 0 || next_y < 0 || next_x >= w || next_y >= h)
				continue;
			if (map[next_y][next_x] && !visited[next_y][next_x])
			{
				q.push(make_pair(next_y, next_x));
				visited[next_y][next_x] = true;
			}
		}
	}
}
int main()
{
	while (true)
	{
		cin >> w >> h;
		if (w == 0 && h == 0)
			break;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				cin >> map[i][j];
			}
		}
		int cnt = 0;
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (!visited[i][j] && map[i][j])
				{
					q.push(make_pair(i, j));
					visited[i][j] = true;
					bfs();
					cnt++;
				}
			}
		}
		cout << cnt << endl;
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
	
	return 0;
}