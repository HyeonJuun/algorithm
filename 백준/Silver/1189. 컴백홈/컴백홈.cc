#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 5 + 1;

int r, c, k;

char map[MAX][MAX];
bool visited[MAX][MAX];
int ans = 0;

int dx[] = { -1, 1 ,0 , 0 };
int dy[] = { 0, 0, -1, 1 };

void solve(int x, int y, int cnt)
{
	if (cnt == k)
	{
		if (x == c - 1 && y == 0)
		{
			ans++;
			return;
		}
	}
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (map[nx][ny] == 'T')
			continue;
		if (nx < 0 || ny < 0 || nx >= c || ny >= r)
			continue;
		if (!visited[nx][ny])
		{
			visited[nx][ny] = true;
			solve(nx, ny, cnt + 1);
			visited[nx][ny] = false;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c >> k;
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < s.length(); j++)
		{
			map[i][j] = s[j];
		}
	}
	visited[0][r - 1] = true;
	solve(0, r - 1, 1);
	cout << ans << '\n';
	return 0;
}