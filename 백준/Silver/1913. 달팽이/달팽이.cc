#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 1000 + 1;

int n, m, ansx, ansy, x = 0, y = 0, dir = 0;
int map[MAX][MAX];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = n * n; i > 0; i--)
	{
		map[y][x] = i;
		if (i == m)
		{
			ansx = x + 1;
			ansy = y + 1;
		}
		if (y + dy[dir] < 0 || y + dy[dir] >= n || x + dx[dir] < 0 || x + dx[dir] >= n || map[y + dy[dir]][x + dx[dir]] != 0)
			dir = (dir + 1) % 4;
		x = x + dx[dir];
		y = y + dy[dir];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << map[i][j] << " ";
		cout << '\n';
	}
	cout << ansy << " " << ansx << '\n';
	return 0;
}