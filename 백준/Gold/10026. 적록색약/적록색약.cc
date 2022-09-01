#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 100 + 1;

char map[MAX][MAX] = { ' ', };
bool visited[MAX][MAX] = { false, };

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int n, cnt1 = 0, cnt2 = 0;

void bfs(int y, int x, char c)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty())
	{
		int fx = q.front().second;
		int fy = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == c)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}
void bfs_RG(int y, int x, char c1, char c2)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;
	while (!q.empty())
	{
		int fx = q.front().second;
		int fy = q.front().first;
		q.pop();
		for (int i = 0; i < 4; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= n)
				continue;
			if (!visited[ny][nx] && (map[ny][nx] == c1 || map[ny][nx] == c2))
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < n; j++)
		{
			map[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && map[i][j] == 'R')
			{
				visited[i][j] = true;
				bfs(i, j, 'R');
				cnt1++;
			}
			else if (!visited[i][j] && map[i][j] == 'G')
			{
				visited[i][j] = true;
				bfs(i, j, 'G');
				cnt1++;
			}
			else if (!visited[i][j] && map[i][j] == 'B')
			{
				visited[i][j] = true;
				bfs(i, j, 'B');
				cnt1++;
			}
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!visited[i][j] && (map[i][j] == 'R' || map[i][j] == 'G'))
			{
				visited[i][j] = true;
				bfs_RG(i, j, 'R', 'G');
				cnt2++;
			}
			else if (!visited[i][j] && map[i][j] == 'B')
			{
				visited[i][j] = true;
				bfs(i, j, 'B');
				cnt2++;
			}
		}
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;
}