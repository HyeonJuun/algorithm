#include <iostream>
#include <queue>
#include <vector>
#include <stdio.h>
#include <cstring> 

using namespace std;

vector<int> connected[1001];
bool visited[1001] = { false, };

void dfs(int start)
{
	visited[start] = true;
	for (int i = 0; i < connected[start].size(); i++)
	{
		int next = connected[start][i];
		if (!visited[next])
		{
			dfs(next);
		}
	}
}

void bfs(int start)
{
	queue<int> q;
	visited[start] = true;
	q.push(start);
	while (!q.empty())
	{
		int c = q.front();
		q.pop();

		for (int i = 0; i < connected[c].size(); i++)
		{
			int next = connected[c][i];
			if (!visited[next])
			{
				visited[next] = true;
				q.push(next);
			}
		}
	}
}
int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		connected[x].push_back(y);
		connected[y].push_back(x);
	}
	int ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (!visited[i])
		{
			ans++;
			bfs(i);
			//dfs(i);
		}
	}
	cout << ans << endl;
	return 0;
}


