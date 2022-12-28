#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 300 + 1;

int t, n;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -2, -2, -1, -1, 1, 1, 2, 2 };
int dy[] = { 1, -1, 2, -2, 2, -2, 1, -1 };
int ans;


void bfs(int start_x, int start_y, int end_x, int end_y)
{
	queue<pair<int, int>> q;
	q.push({ start_x, start_y });
	visited[start_x][start_y] = true;

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
		for (int i = 0; i < 8; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
		
			if (nx < 0 || nx >= n || ny < 0 || ny >= n)
				continue;

			if (!visited[nx][ny])
			{
				visited[nx][ny] = true;
				q.push({ nx, ny });
				map[nx][ny] = map[x][y] + 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> t;

	while (t--)
	{
		cin >> n;
		int start_x, start_y, end_x, end_y;
		cin >> start_x >> start_y >> end_x >> end_y;
		bfs(start_x, start_y, end_x, end_y);
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
	return 0;
}