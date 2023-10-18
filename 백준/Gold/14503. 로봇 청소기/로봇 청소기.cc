#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 50;

int n, m;
int answer;
int map[MAX][MAX];
bool visited[MAX][MAX];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int r, c, dir;

void dfs()
{

	for (int i = 0; i < 4; i++)
	{
		int nx_dir = (dir + 3 - i) % 4;
		int nr = r + dx[nx_dir];
		int nc = c + dy[nx_dir];

		if (nr < 0 || nc < 0 || nr >= n || nc >= m || map[nr][nc] == 1)
			continue;

		if (map[nr][nc] == 0 && visited[nr][nc] == 0)
		{
			visited[nr][nc] = 1;
			r = nr;
			c = nc;
			dir = nx_dir;
			answer++;
			dfs();
		}
	}

	int back_ind = dir > 1 ? dir - 2 : dir + 2;
	int back_r = r + dx[back_ind];
	int back_c = c + dy[back_ind];

	if (back_r >= 0 && back_r <= n && back_c >= 0 && back_c <= m)
	{
		if (map[back_r][back_c] == 0)
		{
			r = back_r;
			c = back_c;
			dfs();
		}
		else
		{
			cout << answer;
			exit(0);
		}
	}
}
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;
	cin >> r >> c >> dir;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cin >> map[i][j];
		}
	}
	
	visited[r][c] = true;
	answer++;

	dfs();
	return 0;
}