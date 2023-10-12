#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2e9;
int n, m;
int a, b, c;

vector<pair<int, int>> graph[1010];

int dist[1010];

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }
    cin >> a >> b;
    priority_queue < pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    dist[a] = 0;
    pq.push({ 0, a });

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();

        if (dist[cur] != d)
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nxt = graph[cur][i].first;
            
            if (dist[nxt] > dist[cur] + graph[cur][i].second)
            {
                dist[nxt] = dist[cur] + graph[cur][i].second;
                pq.push({ dist[nxt], nxt });
            }
        }
    }
    cout << dist[b] << endl;
    return 0;
}
