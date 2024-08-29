#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int n, m, x;
int a, b, c;
vector<pair<int, int>> mp[MAX];
vector<pair<int, int>> rev_mp[MAX];
int dist[MAX];
int answer[MAX];

void resetDist()
{
    for (int i = 1; i <= MAX; i++)
        dist[i] = INF;
}
void getDist_rev(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
            continue;
        for (int i = 0; i < rev_mp[cur].size(); i++)
        {
            int nx = rev_mp[cur][i].first;
            int nxCost = rev_mp[cur][i].second;

            if (dist[nx] > dist[cur] + nxCost)
            {
                dist[nx] = dist[cur] + nxCost;
                pq.push({dist[nx], nx});
            }
        }
    }
}
void getDist(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, start});
    dist[start] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist[cur] != cost)
            continue;
        for (int i = 0; i < mp[cur].size(); i++)
        {
            int nx = mp[cur][i].first;
            int nxCost = mp[cur][i].second;

            if (dist[nx] > dist[cur] + nxCost)
            {
                dist[nx] = dist[cur] + nxCost;
                pq.push({dist[nx], nx});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> x;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        rev_mp[b].push_back({a, c});
    }

    resetDist();
    getDist_rev(x);
    for (int i = 1; i <= n; i++)
        answer[i] += dist[i];
    resetDist();
    getDist(x);
    for (int i = 1; i <= n; i++)
        answer[i] += dist[i];

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, answer[i]);
    cout << ans << endl;
    return 0;
}