#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 100 + 1;

int n;
int map[MAX][MAX];
vector<int> v[MAX];
int visited[MAX];

void dfs(int x)
{
	for (int i = 0; i < v[x].size(); i++)
	{
		if (!visited[v[x][i]])
		{
			visited[v[x][i]] = 1;
			dfs(v[x][i]);
		}
	}
}

void floyd()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			for (int k = 0; k < n; k++)
			{
				if (map[i][k] && map[j][i])
					map[j][k] = 1;
			}
		}
	}
}
int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int l, h;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			int x; cin >> x;
			if (x)
				v[i].push_back(j);
			map[i][j] = x;
		}
	}
	//for (int i = 0; i < n; i++)
	//{
	//	memset(visited, 0, sizeof(visited));
	//	dfs(i);
	//	for (int j = 0; j < n; j++)
	//	{
	//		cout << visited[j] << " ";
	//	}
	//	cout << '\n';
	//}
	//cout << '\n';
	floyd();
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << map[i][j] << " ";
		}
		cout << '\n';
	}
	return 0;
}