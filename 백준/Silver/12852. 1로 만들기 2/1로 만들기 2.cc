#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>

using namespace std;

const int MAX = 1000000 + 1;

int n, ans_cnt = 0;
int dp[MAX];

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
		dp[i] = i;

	for (int i = 2; i <= n; i++)
	{
		if (i % 2 == 0)
		{
			dp[i] = min(dp[i], dp[i / 2]);
		}
		if (i % 3 == 0)
			dp[i] = min(dp[i], dp[i / 3]);
		dp[i] = min(dp[i], dp[i - 1]) + 1;
	}
	cout << dp[n] - 1<< '\n';
	while (n != 0)
	{
		cout << n << '\n';
		if (dp[n] == dp[n - 1] + 1)
		{
			n--;
		}
		else if (dp[n] == dp[n / 2] + 1 && n % 2 == 0)
		{
			n /= 2;
		}
		else if (dp[n] == dp[n / 3] + 1 && n % 3 == 0)
			n /= 3;
	}
	return 0;
}