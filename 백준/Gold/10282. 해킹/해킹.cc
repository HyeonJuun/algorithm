#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <cstring>
using namespace std;

#define MAX 10000 + 1
#define INF 2e9
int tc, n, d, c, a, b, s;
vector<pair<int, int>> graph[MAX];
vector<long long> dist;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
void solve(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    dist.assign(n + 1, INF);
    dist[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        int cur = pq.top().first;
        int cost = pq.top().second;
        pq.pop();

        if (dist[cur] < cost)
            continue;
        for (int i = 0; i < graph[cur].size(); i++)
        {
            int nxt = graph[cur][i].first;
            int nxcost = cost + graph[cur][i].second;

            if (dist[nxt] > nxcost)
            {
                dist[nxt] = nxcost;
                pq.push({nxt, nxcost});
            }
        }
    }
}
int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> tc;
    while (tc--)
    {
        cin >> n >> d >> c;
        for (int i = 0; i <= n; i++)
        {
            graph[i].clear();
        }
        for (int i = 0; i < d; i++)
        {
            cin >> a >> b >> s;
            graph[b].push_back({a, s});
        }

        solve(c);
        int cnt = 0, time = 0;
        for (int i = 1; i <= n; i++)
        {
            if (dist[i] != INF)
            {
                if (time < dist[i])
                {
                    time = dist[i];
                }
                cnt++;
            }
        }
        cout << cnt << " " << time << endl;
    }
    return 0;
}