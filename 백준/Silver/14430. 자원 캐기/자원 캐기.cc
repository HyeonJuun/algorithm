#include<bits/stdc++.h>
using namespace std; 
int n, m, a[304][304], dp[304][304], ret; 
int main(){
    cin >> n >> m; 
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> a[i][j];
        }
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i][j], dp[i - 1][j] + (a[i][j] == 1));
            dp[i][j] = max(dp[i][j], dp[i][j - 1] + (a[i][j] == 1));
            ret = max(dp[i][j], ret);
        }
    } 
    cout << ret << "\n";
    return 0;
}