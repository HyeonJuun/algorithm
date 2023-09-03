#include <vector>
#include <cstring>
using namespace std;

int MOD = 20170805;
int answer = 0;

int dp[510][510][2];

int solution(int m, int n, vector<vector<int>> city_map) {
    
    memset(dp, 0, sizeof(dp));
    
    dp[1][1][0] = 1;
    dp[1][1][1] = 1;
    
    for(int i=1; i<=m; i++)
    {
        for(int j=1; j<=n; j++)
        {
            if(city_map[i-1][j-1] == 0)
            {
                dp[i][j][0] = (dp[i][j][0] + dp[i-1][j][0] + dp[i][j-1][1]) % MOD;
                dp[i][j][1] = (dp[i][j][1] + dp[i-1][j][0] + dp[i][j-1][1]) % MOD;
            }
            else if(city_map[i-1][j-1] == 1)
                dp[i][j][0] = dp[i][j][1] = 0;
            else
            {
                dp[i][j][0] = dp[i-1][j][0] % MOD;
                dp[i][j][1] = dp[i][j-1][1] % MOD; 
            }
        }
    }
    return dp[m][n][0] % MOD;
}