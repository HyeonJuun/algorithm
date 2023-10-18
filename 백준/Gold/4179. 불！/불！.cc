#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 1001;

int n, m;
int answer;
string map[MAX];
bool flag;
int dist1[MAX][MAX];
int dist2[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	queue<pair<int, int>> q1;
	queue<pair<int, int>> q2;

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		cin >> map[i];

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			dist1[i][j] = -1;
			dist2[i][j] = -1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (map[i][j] == 'F')
			{
				q1.push({ i, j });
				dist1[i][j] = 0;
			}
			if (map[i][j] == 'J')
			{
				q2.push({ i, j });
				dist2[i][j] = 0;
			}
		}
	}

	while (!q1.empty())
	{
		int x = q1.front().first;
		int y = q1.front().second;
		q1.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
				continue;
			if (dist1[nx][ny] >= 0 || map[nx][ny] == '#')
				continue;
			dist1[nx][ny] = dist1[x][y] + 1;
			q1.push({ nx, ny });
		}
	}

	while (!q2.empty())
	{
		int x = q2.front().first;
		int y = q2.front().second;
		q2.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || ny < 0 || nx >= n || ny >= m)
			{
				answer = dist2[x][y] + 1;
				flag = true;
				break;
			}
			if (dist2[nx][ny] >= 0 || map[nx][ny] == '#')
				continue;
			if (dist1[nx][ny] != -1 && dist1[nx][ny] <= dist2[x][y] + 1)
				continue;

			dist2[nx][ny] = dist2[x][y] + 1;
			q2.push({ nx, ny });
		}
		if (flag)
			break;
	}

	if (flag)
		cout << answer;
	else
		cout << "IMPOSSIBLE";
	return 0;
}