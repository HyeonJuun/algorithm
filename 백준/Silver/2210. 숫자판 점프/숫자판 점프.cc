#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include <string>

using namespace std;

int map[5][5] = { 0, };
bool visited[1000000] = { false, };
int ans;
int dx[] = { 0,0,-1, 1 };
int dy[] = { -1, 1, 0, 0 };


void dfs(int x, int y, string num, int dep)
{
	if (dep == 6)
	{
		int n = stoi(num);
		if (!visited[n])
		{
			visited[n] = true;
			ans++;
		}
		return;
	}
	else
	{
		for (int i = 0; i < 4; i++)
		{
			int tx = x + dx[i];
			int ty = y + dy[i];
			
			if (0 <= tx && tx < 5 && 0 <= ty && ty < 5)
			{
				string c_num = num;
				c_num.append(to_string(map[tx][ty]));
				dfs(tx, ty, c_num, dep + 1);
			}
		}
	}

}
int main()
{
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 5; j++)
		{
			string str = to_string(map[i][j]);
			dfs(i, j, str, 1);
		}
	}
	cout << ans;
	return 0;
}