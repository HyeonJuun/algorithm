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

#define MAX 100 + 10
#define INF 2100000000

int n, m, answer, sum;
int bite[MAX], cost[MAX];
int dp[MAX][10001];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> bite[i];
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i];
        sum += cost[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= sum; j++)
        {
            if (j - cost[i] >= 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - cost[i]] + bite[i]);
            }
            dp[i][j] = max(dp[i][j], dp[i - 1][j]);
        }
    }
    for (int i = 0; i <= sum; i++)
    {
        if (dp[n][i] >= m)
        {
            cout << i << endl;
            break;
        }
    }
    return 0;
}