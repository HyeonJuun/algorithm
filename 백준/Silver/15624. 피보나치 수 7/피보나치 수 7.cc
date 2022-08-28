#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 1000000 + 1;
const long mod = 1000000007;

int n, ans=0, cnt = 0;

long long dp[MAX] = { 0, };


int main(void)
{
	cin >> n;
	dp[0] = 0;
	dp[1] = 1;
	dp[2] = 1;
	dp[3] = 2;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = (dp[i - 1] + dp[i - 2]) % mod;
	}
	cout << dp[n] << endl;
	return 0;

}
