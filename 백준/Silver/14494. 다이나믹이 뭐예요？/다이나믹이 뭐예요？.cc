#include <iostream>
#include <algorithm>
#include<string>
#include<cstring>
#include<vector>

using namespace std;

const int MAX = 1000 + 1;
const int mod = 1000000007;
int n, m;
long long dp[MAX][MAX] = { 0, };

int main() 
{
    cin >> n >> m;
    dp[1][1] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if(i * j != 1)
                dp[i][j] = (dp[i - 1][j]%mod + dp[i - 1][j - 1] % mod + dp[i][j - 1] % mod) % mod;
        }
    }
    cout << dp[n][m] % mod << endl;
    return 0;

}