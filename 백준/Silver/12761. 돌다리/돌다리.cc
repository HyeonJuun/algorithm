#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 100001;
bool visited[MAX];
int n, m, a, b;
int cnt = 0 , pos = 0;
int bfs(int n)
{
	queue<pair<int, int> > q;

	visited[n] = true;
	q.push(make_pair(0, n));

	while (!q.empty())
	{
		int cnt = q.front().first;
		int pos = q.front().second;
		q.pop();

		if (pos == m)
			return cnt;

		if (pos + 1 < MAX && !visited[pos + 1])
		{
			visited[pos + 1] = true;
			q.push(make_pair(cnt + 1, pos + 1));
		}
		if (pos - 1 > 0 && !visited[pos - 1])
		{
			visited[pos - 1] = true;
			q.push(make_pair(cnt + 1, pos - 1));
		}
		if (pos + a < MAX && !visited[pos + a])
		{
			visited[pos + a] = true;
			q.push(make_pair(cnt + 1, pos + a));
		}
		if (pos - a > 0 && !visited[pos - a])
		{
			visited[pos - a] = true;
			q.push(make_pair(cnt + 1, pos - a));
		}
		if (pos + b < MAX && !visited[pos + b])
		{
			visited[pos + b] = true;
			q.push(make_pair(cnt + 1, pos + b));
		}
		if (pos - b > 0 && !visited[pos - b])
		{
			visited[pos - b] = true;
			q.push(make_pair(cnt + 1, pos - b));
		}
		if (pos * a < MAX && !visited[pos * a])
		{
			visited[pos * a] = true;
			q.push(make_pair(cnt + 1, pos * a));
		}
		if (pos * b < MAX && !visited[pos * b])
		{
			visited[pos * b] = true;
			q.push(make_pair(cnt + 1, pos * b));
		}
	}
	return -1;
}

int main()
{
	cin >> a >> b >> n >> m;
	cout << bfs(n);
	return 0;
}
