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

#define MAX 500 + 10
#define INF 987654321

int n, m, answer;
int mp[MAX][MAX];
int visited[MAX];
int cnt[MAX];

void dfs(int n, int cur, int start)
{
    if (!visited[cur])
        cnt[start]++;
    visited[cur] = true;

    for (int i = 1; i <= n; i++)
    {
        if (mp[cur][i] == 1 && visited[i] == 0)
        {
            dfs(n, i, start);
        }
    }
}
void reverse_dfs(int n, int cur, int start)
{
    if (!visited[cur])
        cnt[start]++;

    visited[cur] = true;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && mp[cur][i] == -1)
        {
            reverse_dfs(n, i, start);
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
        int a, b;
        cin >> a >> b;
        mp[a][b] = 1;
        mp[b][a] = -1;
    }

    for (int i = 1; i <= n; i++)
    {
        dfs(n, i, i);
        memset(visited, false, sizeof(visited));
        reverse_dfs(n, i, i);
        memset(visited, false, sizeof(visited));
    }
    for (int i = 1; i <= n; i++)
    {
        if (cnt[i] == n + 1)
            answer++;
    }
    cout << answer << '\n';

    return 0;
}