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
int dist[MAX][MAX] = { 0, };
queue<pair<int, int> > q;

int n, m, k;
void bfs(int y, int x)
{
	q.push(make_pair(y, x));
	visited[y][x] = true;
	dist[y][x] ++;

	while (!q.empty())
	{
		y = q.front().first;
		x = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>m || ny >n)
				continue;
			if (map[ny][nx] == 1 && visited[ny][nx] == 0)
			{
				visited[ny][nx] = true;
				q.push(make_pair(ny, nx));
				dist[ny][nx] = dist[y][x] + 1;
			}
		}		
		
	}
	
}

int main()
{
	cin >> n >> m;
	for(int i=0; i<n;i++)
	{
		string str;
		cin >> str;
		for (int j = 0; j < m; j++)
		{
			map[i][j] = str[j] - '0';
		}
	}

	bfs(0, 0);

	cout << dist[n-1][m-1] << endl;
	return 0;
}