#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100010;
const int INF = 2e9;

int n, m, start, goal, money;
int a, b, c;

vector<pair<long long, long long>> map[MAX];

int dist[MAX];

long long answer = 2e9;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> m >> start >> goal >> money;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
		map[b].push_back({ a,c });
	}
	for (int i = 0; i < MAX; i++)
		dist[i] = INF;
	priority_queue<pair<long long, pair<long long, int>>, vector< pair<long long, pair<long long, int>>>, greater<pair<long long, pair<long long, int>>>>pq;

	dist[start] = 0;
	pq.push({ 0, { 0, start } });


	while (!pq.empty())
	{
		int cur = pq.top().second.second;
		int cost = pq.top().first;
		long long mx = pq.top().second.first;
		pq.pop();


		if (cur == goal)
		{
			answer = min(answer, mx);
		}
		for (int i = 0; i < map[cur].size(); i++)
		{
			int nxt = map[cur][i].first;
			long long ncost = map[cur][i].second;

			if (dist[cur] + ncost > money)
				continue;

			if (dist[nxt] > dist[cur] + ncost)
			{
				dist[nxt] = dist[cur] + ncost;
				mx = max(mx, ncost);
				pq.push({ dist[nxt], {mx, nxt} });
			}
		}
	}
	if (answer == INF)
		cout << -1;
	else
		cout << answer;
	return 0;
}