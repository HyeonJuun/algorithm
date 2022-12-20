#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 20 + 1;

int r, c, max_cnt = 0;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

char map[MAX][MAX];
bool alpha[26];

void dfs(int cnt, int y, int x)
{
	max_cnt = max(max_cnt, cnt);

	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 &&  nx < c && ny >= 0 && ny < r)
		{
			if (alpha[map[ny][nx] - 'A'] == false)
			{
				alpha[map[ny][nx] - 'A'] = true;
				dfs(cnt + 1, ny, nx);
				alpha[map[ny][nx] - 'A'] = false;
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> r >> c;
	memset(alpha, false, sizeof(alpha));
	for (int i = 0; i < r; i++)
	{
		string s;
		cin >> s;
		for (int j = 0; j < c; j++)
		{
			map[i][j] = s[j];
		}
	}
	alpha[map[0][0] - 'A'] = true;
	dfs(1, 0, 0);
	cout << max_cnt << '\n';
	return 0;
}