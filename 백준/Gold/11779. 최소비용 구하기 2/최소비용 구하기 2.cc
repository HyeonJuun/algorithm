#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 1000 + 10
#define INF 2e9
using namespace std;

int n, m;
int a, b, c;
int start_pos, target_pos;
int dist[MAX];
int route[MAX];
vector<int> answer;
vector<pair<int, int>> graph[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }

    cin >> start_pos >> target_pos;

    for (int i = 1; i <= n; i++)
        dist[i] = INF;

    pq.push({0, start_pos});
    dist[start_pos] = 0;
    route[start_pos] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
            continue;

        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nx = graph[cur][i].first;
            int ncost = graph[cur][i].second;

            if (dist[nx] > dist[cur] + ncost)
            {
                dist[nx] = dist[cur] + ncost;
                route[nx] = cur;
                pq.push({dist[nx], nx});
            }
        }
    }
    int x = target_pos;
    while (x)
    {
        answer.push_back(x);
        x = route[x];
    }
    reverse(answer.begin(), answer.end());
    cout << dist[target_pos] << endl
         << answer.size() << endl;
    for (int i = 0; i < answer.size(); i++)
    {
        cout << answer[i] << " ";
    }
    cout << endl;
    return 0;
}