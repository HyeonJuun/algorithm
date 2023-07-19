#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 100000;
const long mod = 1000000007;
int dp[MAX];

int solution(int n, vector<int> money) {
    int answer = 0;
    
    sort(money.begin(), money.end());
    
    dp[0] = 1;
    
    for(int i = 0; i < money.size() ; i++)
    {
       for(int j = money[i]; j<=n; j++)
       {
           dp[j] += dp[j - money[i]];
           dp[j] %= mod;
       }
    }
    answer = dp[n] % mod;
    return answer;
}