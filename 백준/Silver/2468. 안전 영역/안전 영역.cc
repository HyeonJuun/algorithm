#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>

using namespace std;

const int MAX = 102;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[MAX][MAX] = { 0, };
int real_map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };

queue<pair<int, int> > q;
vector<int> ans;

int n, cnt = 0;
void bfs(int y, int x)
{
	q.push(make_pair(y, x));
	visited[y][x] = true;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>=n || ny >=n)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
			}
		}		
		
	}
	
}
void reset()
{
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			map[i][j] = 0;
			visited[i][j] = 0;
		}
	}
	cnt = 0;
}

int main()
{
	int max_h = -1;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> real_map[i][j];
			max_h = max(max_h, real_map[i][j]);
		}
	}
	for (int h = 1; h <= max_h; h++)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
			{
				if (real_map[i][j] < h)
					map[i][j] = 0;
				else
					map[i][j] = 1;
			}
		}

		for (int i = 0; i < n; i++)
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
		ans.push_back(cnt);
		memset(map, 0, sizeof(map));
		memset(visited, false, sizeof(visited));
		cnt = 0;
	}
	sort(ans.begin(), ans.end(), greater<>());
	cout << ans[0] << endl;
	return 0;
}
