#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

#define INF  1e13 + 7
const int MAX = 1001;

int n, m;
int a, b, c;
vector<pair<int, int>> answer;
vector<pair<int, int>> map[MAX];
int dist[MAX];
int route[MAX];
bool visited[MAX];

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
		map[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++)
		dist[i] = INF;

	priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>>pq;

	pq.push({ 0, 1 });
	dist[1] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();

		if (dist[cur] != cost)
			continue;

		for (int i = 0; i < map[cur].size(); i++)
		{
			int nxt = map[cur][i].first;
			int ncost = map[cur][i].second;

			if (dist[nxt] > cost + ncost)
			{
				dist[nxt] = cost + ncost;
				pq.push({ dist[nxt], nxt });
				route[nxt] = cur;
			}
		}
	}
	for (int i = 1; i <= n; i++)
	{
		int x = route[i];
		if (route[i] == 0)
			continue;
		if (!visited[x] && !visited[i])
		{
			answer.push_back({ i, x });
		}
	}
	cout << answer.size() << '\n';
	for (int i = 0; i < answer.size(); i++)
	{
		cout << answer[i].first << ' ' << answer[i].second << '\n';
	}
	return 0;
}