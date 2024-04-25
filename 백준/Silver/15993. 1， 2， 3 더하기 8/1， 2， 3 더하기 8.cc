#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#define MOD 1000000009
using namespace std;

const int MAX = 100000 + 1;

int t, n;
// [n][0] -> n을 홀수개로 나타낼 수 있는 방법
// [n][1] -> n을 짝수개로 나타낼 수 있는 방법
int dp[MAX][2];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    dp[1][1] = dp[2][1] = dp[2][0] = dp[0][0] = 1;
    for (int i = 3; i <= 100000; i++)
    {
        dp[i][0] = ((dp[i - 1][1] + dp[i - 2][1]) % MOD + dp[i - 3][1]) % MOD;
        dp[i][1] = ((dp[i - 1][0] + dp[i - 2][0]) % MOD + dp[i - 3][0]) % MOD;
    }
    while (t--)
    {
        cin >> n;
        cout << dp[n][1] << " " << dp[n][0] << endl;
    }
    return 0;
}