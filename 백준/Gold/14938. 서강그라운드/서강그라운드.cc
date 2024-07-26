#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 100 + 10
#define INF 2e9

int n, m, r;
vector<pair<int, int>> mp[MAX];
int item[MAX];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int result[MAX];
int a, b, l, answer;

int solve(int k)
{
    for (int i = 1; i <= n; i++)
        result[i] = INF;

    result[k] = 0;

    pq.push({0, k});
    while (!pq.empty())
    {
        int x = pq.top().first;
        int u = pq.top().second;
        pq.pop();

        for (int i = 0; i < mp[u].size(); i++)
        {
            int v = mp[u][i].first;
            int w = mp[u][i].second;

            if (x + w < result[v])
            {
                result[v] = x + w;
                pq.push({x + w, v});
            }
        }
    }
    int sum = 0;
    for (int i = 1; i <= n; i++)
    {
        if (result[i] <= m)
            sum += item[i];
    }
    return sum;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> r;
    for (int i = 1; i <= n; i++)
        cin >> item[i];

    for (int i = 0; i < r; i++)
    {
        cin >> a >> b >> l;
        mp[a].push_back({b, l});
        mp[b].push_back({a, l});
    }
    for (int i = 1; i <= n; i++)
        answer = max(answer, solve(i));
    cout << answer << endl;
    return 0;
}