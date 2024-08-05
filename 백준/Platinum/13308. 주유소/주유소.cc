#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 2500 + 10
#define INF 987654321

int n, m;
long long answer;
int oil[MAX];
long long dp[MAX][MAX];
vector<pair<int, int>> mp[MAX];
priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> pq;
void solve()
{
    pq.push({0, {1, oil[1]}});

    while (!pq.empty())
    {
        int cur = pq.top().second.first;
        long long cur_cost = pq.top().first;
        int cur_oil = pq.top().second.second;
        pq.pop();

        if (dp[cur][cur_oil] != -1)
            continue;

        dp[cur][cur_oil] = cur_cost;

        if (cur == n)
        {
            answer = cur_cost;
            break;
        }
        for (int i = 0; i < mp[cur].size(); i++)
        {
            int nxt = mp[cur][i].first;
            long long nxt_cost = mp[cur][i].second * min(cur_oil, oil[cur]) + cur_cost;
            int nxt_oil = min(cur_oil, oil[cur]);

            if (dp[nxt][nxt_oil] == -1)
            {
                pq.push({nxt_cost, {nxt, nxt_oil}});
            }
        }
    }
    cout << answer << endl;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            dp[i][j] = -1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> oil[i];
    }
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        mp[a].push_back({b, c});
        mp[b].push_back({a, c});
    }
    solve();

    return 0;
}