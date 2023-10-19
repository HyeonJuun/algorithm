#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

#define INF  1e13 + 7
const int MAX = 130;

int n;
int map[MAX][MAX];
int dist[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { -1, 1, 0, 0 };


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int count = 1;
	while (true)
	{
		cin >> n;
		if (n == 0)
			break;
		memset(map, 0, sizeof(map));
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				dist[i][j] = INF;
			}
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				cin >> map[i][j];
			}
		}

		priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
		
		dist[0][0] = map[0][0];
		pq.push({ dist[0][0],{0, 0 }});

		while (!pq.empty())
		{
			int x = pq.top().second.first;
			int y = pq.top().second.second;
			int cost = pq.top().first;
			pq.pop();

			if (dist[x][y] > cost)
				continue;

			for (int i = 0; i < 4; i++)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if (nx < 0 || ny < 0 || nx >= n || ny >= n)
					continue;

				if (dist[nx][ny] > cost + map[nx][ny])
				{
					dist[nx][ny] = cost + map[nx][ny];
					pq.push({ dist[nx][ny], {nx, ny} });
				}
			}
		}
		cout << "Problem " << count << ": " << dist[n - 1][n - 1] << '\n';
		count++;
	}
	return 0;
}