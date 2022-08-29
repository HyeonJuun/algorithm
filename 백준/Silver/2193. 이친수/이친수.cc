#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 90 + 1;

int n, ans=0, cnt = 0;

long long dp[MAX] = { 0, };

int main(void)
{
	cin >> n;
	
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	cout << dp[n] << endl;
	return 0;

}
