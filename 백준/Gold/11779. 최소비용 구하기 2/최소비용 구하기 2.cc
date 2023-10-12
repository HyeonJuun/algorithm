#include<iostream>
#include<algorithm>
#include <queue>
#include <vector>

using namespace std;

const int INF = 2e8;
int n, m;
int a, b, c;

vector<pair<int, int>> graph[1010];
priority_queue<pair<int, int>, vector< pair<int, int>>, greater< pair<int, int>>> pq;

int dist[1010];
int route[1010];

int main() {
    
    cin >> n >> m;
    
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({ b, c });
    }

    cin >> a >> b;
    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    pq.push({ 0, a });
    dist[a] = 0;
    route[a] = 0;
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
                route[nxt] = cur;
                pq.push({ dist[nxt], nxt });

            }
        }
    }
    vector<int> answer;
    int x = b;
  
    while (x)
    {
        answer.push_back(x);
        x = route[x];
    }
    reverse(answer.begin(), answer.end());

    cout << dist[b] << endl;
    cout << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
        cout << answer[i] << " ";
    return 0;
}
