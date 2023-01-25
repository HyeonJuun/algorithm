#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 1000 + 1;

int n, m;
int map[MAX][MAX];
int visited[MAX][MAX][2];
bool flag = false;
int dist = 0;
int ans = 987654321;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

queue<pair<pair<int, int>, int>> q;


int bfs(int x, int y)
{
	q.push(make_pair(make_pair(x, y), 1));
	visited[y][x][1] = 1;

	while (!q.empty())
	{
		int x = q.front().first.first;
		int y = q.front().first.second;
		int block = q.front().second;
		q.pop();

		if (x == n - 1 && y == m - 1)
			return visited[x][y][block];

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (map[nx][ny] == 1 && block)
			{
				q.push({ {nx, ny}, 0 });
				visited[nx][ny][0] = visited[x][y][block] + 1;
			}
			
			else if (map[nx][ny] == 0 && !visited[nx][ny][block])
			{
				q.push({ {nx, ny}, block });
				visited[nx][ny][block] = visited[x][y][block] + 1;
			}
		}
	}
	return - 1;
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;

		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	cout << bfs(0, 0);

	return 0;
}