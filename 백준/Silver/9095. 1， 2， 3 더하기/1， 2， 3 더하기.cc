#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 11 + 1;

int t, n;

int dp[MAX] = { 0, };
int main(void)
{
	cin >> t;
	while (t--)
	{
		cin >> n;
		dp[1] = 1;
		dp[2] = 2;
		dp[3] = 4;
		for (int i = 4; i <= n; i++)
		{
			dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
		}
		cout << dp[n] << endl;
	}
	return 0;

}
