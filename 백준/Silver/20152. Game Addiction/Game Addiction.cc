#include <iostream>
 
using namespace std;
 
int h, n;
 
int main()
{
    cin >> h >> n;
 
    long long dp[31][31];
    fill(&dp[0][0], &dp[30][31], 0);
 
    for (int i = 0; i < 31; i++) dp[0][i] = 1;
 
    for (int i = 1; i < 31; i++)
    {
        for (int j = i; j < 31; j++)
        {
            dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
        }
    }
 
    int m = abs(h - n);
    cout << dp[m][m];
 
    return 0;
}
 