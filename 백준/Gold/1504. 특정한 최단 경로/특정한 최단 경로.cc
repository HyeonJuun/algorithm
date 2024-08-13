#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 800 + 10
#define INF 987654321

int n, e;
int a, b, c;
vector<pair<int, int>> g[MAX];
int v1, v2;
int answer = INF;
int cost[MAX];

void solve(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (int i = 0; i <= n; i++)
        cost[i] = INF;

    pq.push({0, start});
    cost[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (cost[cur] != dist)
            continue;

        for (int i = 0; i < g[cur].size(); i++)
        {
            int nxt = g[cur][i].first;
            int ndist = g[cur][i].second;

            if (cost[nxt] > dist + ndist)
            {
                cost[nxt] = dist + ndist;
                pq.push({cost[nxt], nxt});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> e;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }
    cin >> v1 >> v2;

    solve(1);
    int sToV1 = cost[v1];
    int sToV2 = cost[v2];

    solve(v1);
    int v1Tov2 = cost[v2];
    int v1ToN = cost[n];

    solve(v2);
    int v2ToN = cost[n];

    answer = min(answer, sToV1 + v1Tov2 + v2ToN);
    answer = min(answer, sToV2 + v1Tov2 + v1ToN);
    if (v1Tov2 == INF || answer == INF)
        answer = -1;
    cout << answer << endl;
    return 0;
}