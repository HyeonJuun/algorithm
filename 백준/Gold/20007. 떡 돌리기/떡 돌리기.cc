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

int n, m, x, y;
int a, b, c;
int answer;
vector<pair<int, int>> v[MAX];
int dist[MAX];

void solve()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, y});
    dist[y] = 0;

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
            int ncost = v[cur][i].second;

            if (dist[nxt] > cost + ncost)
            {
                dist[nxt] = cost + ncost;
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
    cin >> n >> m >> x >> y;
    for (int i = 0; i < MAX; i++)
        dist[i] = INF;
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> c;
        v[a].push_back({b, c});
        v[b].push_back({a, c});
    }
    solve();
    bool flag = true;
    vector<int> dist_v;
    for (int i = 0; i < n; i++)
    {
        if (dist[i] * 2 > x || dist[i] == INF)
        {
            flag = false;
            break;
        }
        if (dist[i] > 0)
            dist[i] *= 2;
    }

    if (flag)
    {
        int idx = 0;
        sort(dist, dist + n);
        while (true)
        {
            answer++;
            int curx = x;
            while (true)
            {
                if (curx < dist[idx])
                    break;
                curx -= dist[idx++];
                if (idx == n)
                    break;
            }
            if (idx == n)
                break;
        }
    }
    else
        answer = -1;

    cout << answer << endl;
    return 0;
}