#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 2e9;

int solution(vector<int> sticker)
{
    int answer = 0;
    int mx = 0;
    int n = sticker.size();
    int dp[100010];
    
    if(n == 1)
        return sticker[0];
    dp[0] = sticker[0];
    dp[1] = dp[0];
    
    for(int i=2; i<n-1; i++)
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    
    dp[n-1] = dp[n-2];
    
    mx = *max_element(dp, dp+n);
    dp[0] = 0;
    
    for(int i=1; i<n; i++)
        dp[i] = max(dp[i-1], dp[i-2] + sticker[i]);
    
    answer = max(mx, *max_element(dp, dp + n));
    return answer;
}