#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1001;

int n, m, k;
int answer = 2e9;


int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int map[MAX][MAX];
int dist[MAX][MAX][11];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
	{
		string s;	cin >> s;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = s[j] - '0';
		}
	}
	queue<pair<int, pair<int, int>>> q;

	q.push({ 0, {0, 0 } });
	dist[0][0][0] = 0;

	while (!q.empty())
	{
		int x = q.front().second.first;
		int y = q.front().second.second;
		int cost = q.front().first;
		q.pop();

		if (x == n - 1 && y == m - 1)
		{
			
			answer = dist[x][y][cost];
			break;
		}
		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;

			if (map[nx][ny] == 1)
			{
				if (cost == k)
					continue;
				else
				{
					if (dist[nx][ny][cost + 1] != 0)
						continue;
					dist[nx][ny][cost + 1] = dist[x][y][cost] + 1;
					q.push({ cost + 1, {nx, ny} });
				}
			}
			else
			{
				if (dist[nx][ny][cost] != 0)
					continue;

				dist[nx][ny][cost] = dist[x][y][cost] + 1;
				q.push({ cost,{nx,ny} });
			}
		}
	}

	if (answer == 2e9)
		cout << -1 << endl;
	else
		cout << answer + 1 << endl;
	return 0;
}