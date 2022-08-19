#include<iostream>
#include<cstring>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;

int map[10001] = { 0, };
bool visited[10001] = { false, };
int ans[10001];
int n, a, b;
void bfs(int a, int b)
{
	queue<int> q;
	q.push(a);
	visited[a] = true;

	while (!q.empty())
	{
		int tmp = q.front();
		q.pop();
		if (tmp == b)
			return;
		for (int i = tmp + map[tmp]; i <= n; i += map[tmp])
		{
			if (!visited[i])
			{
				ans[i] = ans[tmp] + 1;
				q.push(i);
				visited[i] = true;
			}
		}
		for (int i = tmp - map[tmp]; i >= 1; i -= map[tmp])
		{
			if (!visited[i])
			{
				ans[i] = ans[tmp] + 1;
				q.push(i);
				visited[i] = true;
			}
		}
	}
}
int main()
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> map[i];
	}
	cin >> a >> b;
	if (a == b)
	{
		cout << "0" << endl;
		return 0;
	}
	bfs(a, b);
	if (ans[b] == 0)
		cout << -1 << endl;
	else
		cout << ans[b] << endl;
	return 0;
}