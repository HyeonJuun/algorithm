#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

#define MAX 500 + 10
#define INF 2e9
using namespace std;

int n, m;
int mp[MAX][MAX];
int dp[MAX][MAX];

int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

int solve(int x, int y)
{
    if (x == 0 && y == 0)
        return dp[x][y] = 1;
    if (dp[x][y] != INF)
        return dp[x][y];
    // cout << x << " " << y << endl;
    int res = 0;
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        // cout << nx << " " << ny << endl;
        if (nx < 0 || ny < 0 || nx >= n || ny >= m)
            continue;
        if (mp[x][y] >= mp[nx][ny])
            continue;
        res += solve(nx, ny);
    }
    return dp[x][y] = res;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> mp[i][j];
            dp[i][j] = INF;
        }
    }
    int res = solve(n - 1, m - 1);
    cout << res << endl;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //         cout << dp[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}