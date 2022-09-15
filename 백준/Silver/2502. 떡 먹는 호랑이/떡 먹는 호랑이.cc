#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 10000;

int dp[31][2];

int n, k;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int d, k;
	cin >> d >> k;
	dp[1][0] = 1;
	dp[2][0] - 0;
	dp[1][1] = 0;
	dp[2][1] = 1;

	for (int i = 3; i <= d; i++)
	{
		dp[i][0] = dp[i - 1][0] + dp[i - 2][0];
		dp[i][1] = dp[i - 1][1] + dp[i - 2][1];
	}
	for (int i = 1; i <= k; i++)
	{
		int s = k - (dp[d][0] * i);
		if (s % dp[d][1] == 0)
		{
			cout << i << endl << s / dp[d][1] << endl;
			return 0;
		}
	}
	return 0;
}