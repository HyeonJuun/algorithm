#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 20000 + 1;
const int INF = 987654321;

int V, E, u, v, w, start;

vector<pair<int, int>> graph[MAX];
int dist[MAX];

void dijkstra(int start)
{
	dist[start] = 0;
	priority_queue<pair<int, int>>  pq;

	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cur = pq.top().second;
		int cost = -pq.top().first;
		pq.pop();

		for (int i = 0; i < graph[cur].size(); i++)
		{
			int next = graph[cur][i].first;
			int ncost = graph[cur][i].second;

			if (dist[next] > cost + ncost)
			{
				dist[next] = cost + ncost;
				pq.push({ -dist[next], next });
			}
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> V >> E;
	cin >> start;

	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		graph[u].push_back({ v, w });
	}
	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	dijkstra(start);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}
	return 0;
}