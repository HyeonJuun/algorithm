#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 101;


vector<int> map[MAX];

int rs[MAX][MAX] = { 0, };
int visited[MAX] = { 0, };
queue<int > q;
vector<int> v;

int n, m, k, sum = 0, ans = 0;
void bfs(int x)
{
	memset(visited, 0, sizeof(visited));
	q.push(x);
	visited[x] = 1;
	while (!q.empty())
	{
		int front = q.front();
		q.pop();

		for (int i = 0; i < map[front].size(); i++)
		{
			int idx = map[front][i];
			if (visited[idx] == 0)
			{
				visited[idx] = 1;
				q.push(idx);
				rs[idx][x] = rs[front][x] + 1;
				rs[x][idx] = rs[x][front] + 1;
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < m; i++)
	{
		int x, y;
		cin >> x >> y;
		map[x].push_back(y);
		map[y].push_back(x);
	}
	int min_result = 100000;
	for (int i = 1; i <= n; i++)
	{
		bfs(i);
	}
	for (int i = 1; i <= n; i++)
	{
		sum = 0;
		for (int j = 1; j <= n; j++)
		{
			sum += rs[i][j];
		}
		if (min_result > sum)
		{
			min_result = sum;
			ans = i;
		}
	}
	cout << ans << endl;

	return 0;
}
