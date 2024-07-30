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
int answer;
vector<pair<int, int>> v[MAX];
int dist[MAX];
int dp[MAX];

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 2});
    dist[2] = 0;
    dp[2] = 1;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (cost > dist[cur])
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;
            int nxt_cost = v[cur][i].second;

            if (dist[nxt] > cost + nxt_cost)
            {
                dist[nxt] = cost + nxt_cost;
                pq.push({dist[nxt], nxt});
            }

            if (cost > dist[nxt])
                dp[cur] += dp[nxt];
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < MAX; i++)
        dist[i] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    solve();
    cout << dp[1] << endl;
    return 0;
}