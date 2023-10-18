#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 10001;
const int INF = 1000000;
int n, m, k;
int a, b, c;

vector<pair<long long, long long>> map[MAX];
long long dist[MAX][21];

long long answer = 2e10;

int main() {

	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> n >> m >> k;

	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> c;
		map[a].push_back({ b, c });
		map[b].push_back({ a, c });
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dist[i][j] = 2e10;
		}
	}
	priority_queue<pair<long long,pair<long long, long long>>, vector< pair<long long, pair<long long, long long>>>, greater<pair<int, pair<int, int>>>> pq;

	pq.push({ 0, { 0, 1 } });
	dist[1][0] = 0;

	while (!pq.empty())
	{
		long long cur = pq.top().second.second;
		long long cost = pq.top().first;
		long long cnt = pq.top().second.first;
		pq.pop();

		if (dist[cur][cnt] != cost)
			continue;

		for (int i = 0; i < map[cur].size(); i++)
		{
			long long nxt = map[cur][i].first;
			long long ncost = map[cur][i].second;

			if (dist[nxt][cnt] > cost + ncost)
			{
				dist[nxt][cnt] = cost + ncost;
				pq.push({ dist[nxt][cnt], {cnt, nxt} });
			}
			if (cnt < k && dist[nxt][cnt + 1] > cost)
			{
				dist[nxt][cnt + 1] = cost;
				pq.push({ dist[nxt][cnt + 1],{cnt + 1, nxt} });
			}
		}
	}
	answer = dist[n][0];
	for (int i = 1; i <= k; i++)
	{
		answer = min(answer, dist[n][i]);
	}
	cout << answer;
	return 0;
}