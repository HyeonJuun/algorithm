#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int n, m, k;
int a, b, c;

vector<pair<int, int>> v[1010];
vector<pair<int, int>> revv[1010];
int dist[1010];
int ans[1010];
void get_dist(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = 1000000000;

    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist[cur] != d)
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;

            if (dist[nxt] > dist[cur] + v[cur][i].second)
            {
                dist[nxt] = dist[cur] + v[cur][i].second;
                pq.push({ dist[nxt], nxt });
            }
        }
    }
}
void get_revdist(int start)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>,
        greater<pair<int, int>>> pq;
    for (int i = 1; i <= n; i++)
        dist[i] = 1000000000;

    dist[start] = 0;
    pq.push({ 0, start });
    while (!pq.empty())
    {
        int cur = pq.top().second;
        int d = pq.top().first;
        pq.pop();
        if (dist[cur] != d)
            continue;

        for (int i = 0; i < revv[cur].size(); i++)
        {
            int nxt = revv[cur][i].first;

            if (dist[nxt] > dist[cur] + revv[cur][i].second)
            {
                dist[nxt] = dist[cur] + revv[cur][i].second;
                pq.push({ dist[nxt], nxt });
            }
        }
    }
}
int main() {

    cin >> n >> m >> k;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({ b, c });
        revv[b].push_back({ a, c });
    }
    get_dist(k);
    int res = 0;
    for (int i = 1; i <= n; i++)
        ans[i] = dist[i];
    get_revdist(k);
    for (int i = 1; i <= n; i++)
        ans[i] += dist[i];
    for (int i = 1; i <= n; i++)
    {
        res = max(res, ans[i]);
    }
    cout << res;
    return 0;
}