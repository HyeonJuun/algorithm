#include <iostream>
#include <algorithm>

using namespace std;

int n;

int dp[11];

int main(void) {
	cin >> n;
	dp[1] = 0;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
		dp[i] = dp[i - 1] + (i - 1);
	cout << dp[n] << endl;
	return 0;
}