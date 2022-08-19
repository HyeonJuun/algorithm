#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
using namespace std;
int move_x[2] = { 0, 1 };
int move_y[2] = { 1, 0 };

int map[3][3] = { 0, };
bool visit[3][3] = { false, };

int n;

bool bfs()
{
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		if (map[x][y] == -1)
			return true;
		for (int i = 0; i < 2; i++)
		{
			int gx = x + map[x][y] * move_x[i];
			int gy = y + map[x][y] * move_y[i];

			if (0 <= gx && gx < n - 1 && 0 <= gy && gy <= n - 1)
			{
				if (!visit[x][y])
				{
					visit[x][y] = true;
					q.push(make_pair(x, y));
				}
			}
		}
	}
	return false;
}

bool dfs()
{
	stack<pair<int, int>> s;
	s.push(make_pair(0, 0));
	visit[0][0] = true;

	while (!s.empty())
	{
		int x = s.top().first;
		int y = s.top().second;
		s.pop();
		if (map[x][y] == -1)
			return true;

		for (int i = 0; i < 2; i++)
		{
			int gx = x + move_x[i] * map[x][y];
			int gy = y + move_y[i] * map[x][y];

			if (0 <= gx && gx <= n - 1 && 0 <= gy && gy <= n - 1)
			{
				if (!visit[gx][gy])
				{
					visit[gx][gy] = true;
					s.push(make_pair(gx, gy));
				}
			}
		}
	}
	return false;
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> map[i][j];
		}
	}
	if (dfs())
		cout << "HaruHaru" << endl;
	else
		cout << "Hing" << endl;
	return 0;
}