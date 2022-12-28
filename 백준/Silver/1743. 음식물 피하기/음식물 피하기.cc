#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 102;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };

int map[MAX][MAX] = { 0, };
bool visited[MAX][MAX] = { false, };

queue<pair<int, int> > q;
int area = 1;
vector<int> ans;
int h, w, k;
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
			if (nx<0 || ny<0 || nx>w || ny >h)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				area++;
			}
		}		
		
	}
	
}

int main()
{
	cin >> h >> w >> k;
	for (int i = 0; i < k; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x][y] = 1;
	}
	for (int i = 1; i <= h; i++)
	{
		for (int j = 1; j <= w; j++)
		{
			if (map[i][j] == 1 && visited[i][j] == 0)
			{
				bfs(i, j);
				ans.push_back(area);
				area = 1;
			}
		}
	}
	sort(ans.begin(), ans.end(), greater<>());
	cout << ans[0] << endl;
	return 0;
}