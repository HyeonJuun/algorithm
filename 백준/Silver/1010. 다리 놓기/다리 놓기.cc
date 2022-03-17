#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int num, n, m;
    cin >> num;
    int dp[33][33] = { 0, };
    while (num--)
    {
        cin >> n >> m;
        for (int i = 1; i <= m; i++) 
        {
            dp[1][i] = i;
        }
        for (int i = 2; i <= n; i++)
        {
            for (int j = 2; j <= m; j++)
            {
                dp[i][j] = dp[i - 1][j - 1] + dp[i][j - 1];
                
            }
        }
        cout << dp[n][m] << endl;
    }
    return 0;
}