#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100 + 1;

int n, ans = 0;

int map[MAX][MAX];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int r, c;
		cin >> r >> c;
		for (int j = r; j < r + 10; j++)
		{
			for (int k = c; k < c + 10; k++)
			{
				map[j][k] = 1;
			}
		}
	}

	for (int r = 1; r < MAX; r++)
	{
		for (int c = 1; c < MAX; c++)
		{
			if (map[r][c] == 1)
			{
				for (int i = 0; i < 4; i++)
				{
					int nc = c + dx[i];
					int nr = r + dy[i];
					if (map[nr][nc] == 0)
						ans++;
				}
			}
		}
	}
	cout << ans;

	return 0;
}