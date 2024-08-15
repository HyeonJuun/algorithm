#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int n, m;
int a, b, c;
vector<pair<int, int>> v[MAX];
int dist[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int st, ed;

void solve()
{
    pq.push({0, st});
    dist[st] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;
            int nxcost = v[cur][i].second;

            if (dist[nxt] > nxcost + cost)
            {
                dist[nxt] = nxcost + cost;
                pq.push({dist[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        // v[b].push_back({a, c});
    }
    cin >> st >> ed;

    for (int i = 1; i <= n; i++)
    {
        dist[i] = INF;
    }
    solve();

    cout << dist[ed] << endl;
    return 0;
}