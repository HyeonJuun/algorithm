#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
using namespace std;

#define MAX 1000 + 10
#define INF 1000000 + 10

int n;
int cost[MAX][3];
int answer = INF;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> cost[i][0] >> cost[i][1] >> cost[i][2];
    }

    for (int start = 0; start <= 2; start++)
    {
        int dp[MAX][3];
        for (int j = 0; j <= 2; j++)
        {
            if (j == start)
                dp[1][start] = cost[1][start];
            else
                dp[1][j] = INF;
        }

        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = min(dp[i - 1][1], dp[i - 1][2]) + cost[i][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][2]) + cost[i][1];
            dp[i][2] = min(dp[i - 1][0], dp[i - 1][1]) + cost[i][2];
        }

        for (int j = 0; j <= 2; j++)
        {
            if (j == start)
                continue;
            answer = min(answer, dp[n][j]);
        }
    }
    cout << answer << endl;
    return 0;
}