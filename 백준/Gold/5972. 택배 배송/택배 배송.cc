#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>
#include <cstring>

using namespace std;

const int MAX = 50010;
const int INF = 2e9;

int n, m;
int a, b, c;
vector<pair<int, int>> graph[MAX];
int dist[MAX];


int main() {
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
        graph[b].push_back({ a, c });
    }
   
    for (int i = 2; i <= n; i++)
        dist[i] = INF;


    dist[1] = 0;
    pq.push({ 0, 1 });
    
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
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
    cout << dist[n] << endl;
    return 0;
}
