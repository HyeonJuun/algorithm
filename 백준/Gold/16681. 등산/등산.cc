#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>


using namespace std;

#define INF  1e13 + 7
const int MAX = 100010;

int n, m, d, e;
long long height[MAX];
vector<pair<int, long long>> map[MAX];
long long dist1[MAX];
long long dist2[MAX];


void dijkstra(int start, long long dist[MAX])
{
	priority_queue<pair<long long, int>, vector< pair<long long, int>>, greater< pair<long long, int>>> pq;

	pq.push({ 0, start });
	dist[start] = 0;

	while (!pq.empty())
	{
		int cur = pq.top().second;
		long long cost = pq.top().first;
		pq.pop();

		if (dist[cur] < cost)
			continue;

		for (int i = 0; i < map[cur].size(); i++)
		{
			int nxt = map[cur][i].first;
			int ncost = map[cur][i].second;

			if (dist[nxt] > cost + ncost && height[nxt] > height[cur])
			{
				dist[nxt] = cost + ncost;
				pq.push({ dist[nxt], nxt });
			}
		}
	}
}

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	/// INPUT
	{
		cin >> n >> m >> d >> e;
		for (int i = 1; i <= n; i++)
		{
			cin >> height[i];
		}
		for (int i = 0; i < m; i++)
		{
			int a, b, c;
			cin >> a >> b >> c;
			map[a].push_back({ b, c });
			map[b].push_back({ a, c });
		}

		for (int i = 0; i <= n; i++)
		{
			dist1[i] = INF;
			dist2[i] = INF;
		}
	}

	dijkstra(1, dist1);
	dijkstra(n, dist2);

	long long ans = -INF * 100000;
	for (int i = 1; i <= n; i++)
	{
		ans = max(ans, height[i] * e - d * (dist1[i] + dist2[i]));
	}

	if (ans == -INF * 100000)
		cout << "Impossible" << endl;
	else
		cout << ans << '\n';
	return 0;
}