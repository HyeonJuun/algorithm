#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 32000 + 1;

int n, m;
vector<int> graph[MAX];
int inDegree[MAX];
void solve()
{
	queue<int> q;
	for (int i = 1; i <= n; i++)
		if (!inDegree[i])
			q.push(i);
	while (!q.empty())
	{
		int cur = q.front();
		q.pop();
		cout << cur << " ";
		for (int i = 0; i < graph[cur].size(); i++)
		{
			inDegree[graph[cur][i]]--;
			if (!inDegree[graph[cur][i]])
				q.push(graph[cur][i]);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		graph[x].push_back(y);
		inDegree[y]++;
	}
	solve();
	return 0;
}