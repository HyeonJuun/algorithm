#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1001;
vector<pair<int, int> > map[MAX];
bool visited[MAX];
int n, m;
int bfs(int start, int end)
{
	memset(visited, false, sizeof(visited));
	queue<pair<int, int> > q;

	visited[start] = true;
	q.push(make_pair(start, 0));

	while (!q.empty())
	{
		int cur = q.front().first;
		int curdist = q.front().second;
		q.pop();

		if (cur == end)
			return curdist;

		for (int i = 0; i < map[cur].size(); i++)
		{
			int nx = map[cur][i].first;
			int ndist = map[cur][i].second;
			if (!visited[nx])
			{
				visited[nx] = true;
				q.push(make_pair(nx, curdist + ndist));
			}
		}
	}
}

int main()
{
	cin >> n >> m;
	for (int i = 0; i < n-1; i++)
	{
		int x, y, d;
		cin >> x >> y >> d;
		map[x].push_back(make_pair(y, d));
		map[y].push_back(make_pair(x, d));
	}
	while (m--)
	{
		int start, end;
		cin >> start >> end;
		cout << bfs(start, end) << endl;
	}

	return 0;
}
