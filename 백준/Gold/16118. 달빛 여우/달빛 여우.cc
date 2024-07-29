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
int a, b, d;
vector<pair<int, int>> v[MAX];
double dist_wolf[2][MAX];
int dist_fox[MAX];

void solve_fox()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    for (int i = 1; i <= n; i++)
        dist_fox[i] = INF;

    pq.push({0, 1});
    dist_fox[1] = 0;

    while (!pq.empty())
    {
        int cur = pq.top().second;
        int cost = pq.top().first;
        pq.pop();

        if (dist_fox[cur] != cost)
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;
            int nxt_cost = v[cur][i].second;

            if (dist_fox[nxt] > dist_fox[cur] + nxt_cost)
            {
                dist_fox[nxt] = dist_fox[cur] + nxt_cost;
                pq.push({dist_fox[nxt], nxt});
            }
        }
    }
}
void solve_wolf()
{
    priority_queue<pair<double, pair<int, int>>, vector<pair<double, pair<int, int>>>, greater<pair<double, pair<int, int>>>> pq;

    for (int i = 1; i <= n; i++)
    {
        dist_wolf[0][i] = INF;
        dist_wolf[1][i] = INF;
    }
    dist_wolf[0][1] = 0;
    pq.push({dist_wolf[0][1], {0, 1}});

    while (!pq.empty())
    {
        int cur = pq.top().second.second;
        int cur_cnt = pq.top().second.first;
        double cost = pq.top().first;
        pq.pop();

        if (dist_wolf[cur_cnt % 2][cur] != cost)
            continue;

        for (int i = 0; i < v[cur].size(); i++)
        {
            int nxt = v[cur][i].first;
            int nxt_cnt = (cur_cnt + 1) % 2;
            double nxt_cost;
            if (nxt_cnt % 2 != 0)
            {
                nxt_cost = double(v[cur][i].second) / 2;
            }
            else
                nxt_cost = double(v[cur][i].second) * 2;

            if (dist_wolf[nxt_cnt][nxt] > dist_wolf[cur_cnt][cur] + nxt_cost)
            {
                dist_wolf[nxt_cnt][nxt] = dist_wolf[cur_cnt][cur] + nxt_cost;
                pq.push({dist_wolf[nxt_cnt][nxt], {nxt_cnt, nxt}});
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
    for (int i = 0; i < m; i++)
    {
        cin >> a >> b >> d;
        v[a].push_back({b, d});
        v[b].push_back({a, d});
    }
    solve_wolf();
    solve_fox();

    double ans_wolf[MAX];
    int answer = 0;
    for (int i = 1; i <= n; i++)
    {
        ans_wolf[i] = min(dist_wolf[0][i], dist_wolf[1][i]);
        if (dist_fox[i] < ans_wolf[i])
            answer++;
    }
    cout << answer << endl;
    return 0;
}