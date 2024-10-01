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

#define MAX 5000 + 10
#define INF 987654321

int v, e, p;
int a, b, c;
int dist1[MAX];
int dist2[MAX];
vector<pair<int, int>> mp[MAX];

void solve_start1()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, 1});
    dist1[1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist1[cur] != cost)
            continue;

        for (int i = 0; i < mp[cur].size(); i++)
        {
            int nxt = mp[cur][i].first;
            int nxcost = mp[cur][i].second;

            if (dist1[nxt] > cost + nxcost)
            {
                dist1[nxt] = cost + nxcost;
                pq.push({dist1[nxt], nxt});
            }
        }
    }
}
void solve_startP()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    pq.push({0, p});
    dist2[p] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist2[cur] != cost)
            continue;

        for (int i = 0; i < mp[cur].size(); i++)
        {
            int nxt = mp[cur][i].first;
            int nxcost = mp[cur][i].second;

            if (dist2[nxt] > cost + nxcost)
            {
                dist2[nxt] = cost + nxcost;
                pq.push({dist2[nxt], nxt});
            }
        }
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> v >> e >> p;
    for (int i = 0; i < e; i++)
    {
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    for (int i = 1; i <= v; i++)
    {
        dist1[i] = INF;
        dist2[i] = INF;
    }
    solve_start1();
    solve_startP();

    // for (int i = 1; i <= v; i++)
    //     cout << dist1[i] << " ";
    // cout << endl;
    // for (int i = 1; i <= v; i++)
    //     cout << dist2[i] << " ";
    // cout << endl;
    if (dist1[p] + dist2[v] <= dist1[v])
    {
        cout << "SAVE HIM" << '\n';
    }
    else
    {
        cout << "GOOD BYE" << "\n";
    }
    return 0;
}