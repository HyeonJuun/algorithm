#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int t, w, h;

int dx[4] = { -1, 1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };

int map[100][100] = { 0, };
bool visited[100][100] = { false , };

void dfs(int x, int y)
{
	visited[x][y] = true;
	for (int i = 0; i < 4; i++)
	{
		int next_x = x + dx[i];
		int next_y = y + dy[i];
		if (0 <= next_x && next_x < h && 0 <= next_y && next_y < w)
		{
			if (map[next_x][next_y] == 1)
			{
				if (!visited[next_x][next_y])
					dfs(next_x, next_y);
			}
		}
	}
}

int main()
{
	cin >> t;
	while (t--)
	{
		int ans = 0;
		cin >> h >> w;
		string str = "";
		for (int i = 0; i < h; i++)
		{
			cin >> str;
			for (int j = 0; j < w; j++)
			{
				if (str[j] == '#')
					map[i][j] = 1;
				else
					map[i][j] = 0;
			}
		}
		for (int i = 0; i < h; i++)
		{
			for (int j = 0; j < w; j++)
			{
				if (map[i][j] == 1)
				{
					if (!visited[i][j])
					{
						ans++;
						dfs(i, j);
					}
				}
			}
		}
		cout << ans << endl;
		memset(visited, false, sizeof(visited));
		memset(map, 0, sizeof(map));
	}
	return 0;
}