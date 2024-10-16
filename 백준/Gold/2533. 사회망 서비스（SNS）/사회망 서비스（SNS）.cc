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

#define endl "\n"
#define MAX 1000000 + 10
#define INF 2100000000

int n;
int dp[MAX][2];
vector<int> v[MAX];
bool visited[MAX];
int a, b;

void dfs(int cur)
{
    visited[cur] = true;
    dp[cur][0] = 0;
    dp[cur][1] = 1;

    for (int i = 0; i < v[cur].size(); i++)
    {
        int nx = v[cur][i];

        if (visited[nx])
            continue;

        dfs(nx);
        dp[cur][0] += dp[nx][1];
        dp[cur][1] += min(dp[nx][0], dp[nx][1]);
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    dfs(1);
    cout << min(dp[1][0], dp[1][1]) << endl;
    return 0;
}