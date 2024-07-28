#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 5000 + 10
#define INF 987654321

int n, m;
int st, ed;
int a, b, c;
vector<pair<int, int>> v[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int cost[MAX];

void solve(int x)
{
    pq.push({0, x});
    cost[x] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int dist = pq.top().first;
        pq.pop();

        if (cost[cur] != dist)
            continue;
        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;

            if (cost[nxt] > v[cur][i].second + dist)
            {
                cost[nxt] = v[cur][i].second + dist;
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
    cin >> n >> m;
    for (int i = 0; i <= n; i++)
        cost[i] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    cin >> st >> ed;
    solve(st);
    cout << cost[ed] << endl;
    return 0;
}