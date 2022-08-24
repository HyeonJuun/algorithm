#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;

const int MAX = 100001;

bool visited[MAX] = { false, };

int n, k;
void bfs(int a)
{
	queue<pair<int, int> > q;
	q.push(make_pair(a, 0));
	while (!q.empty())
	{
		int x = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (x == k)
		{
			cout << cnt << endl;
			break;
		}
		if (x + 1 >= 0 && x + 1 < 100001)
		{
			if (!visited[x + 1])
			{
				visited[x + 1] = true;
				q.push(make_pair(x + 1, cnt + 1));
			}
		}
		if (x - 1 >= 0 && x - 1 < 100001)
		{
			if (!visited[x - 1])
			{
				visited[x - 1] = true;
				q.push(make_pair(x - 1, cnt + 1));
			}
		}
		if (2 * x >= 0 && 2 * x < 100001)
		{
			if (!visited[2 * x])
			{
				visited[2 * x] = true;
				q.push(make_pair(2 * x, cnt+1));

			}
		}
	}
}

int main()
{
	cin >> n >> k;
	visited[n] = true;
	bfs(n);
	return 0;
}