#include <string>
#include <vector>

using namespace std;

const int mod = 1000000007;

int solution(int n) {
    int answer = 0;
    long long dp[60001];
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 3;
    for(int i=4; i<=n; i++)
    {
        dp[i] = dp[i-1] % mod + dp[i-2] % mod;
    }
    return dp[n] % mod;
}