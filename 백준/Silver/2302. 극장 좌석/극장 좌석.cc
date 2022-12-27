#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<deque>
#define mod 1000000009

using namespace std;

const int MAX = 40 + 1;

int n, m;
int dp[MAX];
int ans = 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	dp[0] = 1;
	dp[1] = 1;
	dp[2] = 2;
	dp[3] = 3;
	for (int i = 4; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
	}
	int start = 0;
	for (int i = 0; i < m; i++)
	{
		int end; cin >> end;
		ans = ans * dp[end - start - 1];
		start = end;
	}
	ans = ans * dp[n - start];
	cout << ans << '\n';
	return 0;
}