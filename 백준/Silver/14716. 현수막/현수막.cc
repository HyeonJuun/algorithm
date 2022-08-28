#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 250 + 1;


int n, m, cnt = 0;

int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };

int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
int dy[] = { 1, 0, -1, 1, -1, 1,0, -1 };

void bfs(int y , int x)
{
	queue<pair<int, int>> q;
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty())
	{
		int fy = q.front().first;
		int fx = q.front().second;
		q.pop();

		for (int i = 0; i < 8; i++)
		{
			int nx = fx + dx[i];
			int ny = fy + dy[i];
			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (!visited[ny][nx] && map[ny][nx] == 1)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}
	}
}



int main(void)
{
	cin >> m >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (map[i][j] == 1 && !visited[i][j])
			{
				bfs(i, j);
				cnt++;
			}
		}
	}
	cout << cnt << endl;
	return 0;

}
