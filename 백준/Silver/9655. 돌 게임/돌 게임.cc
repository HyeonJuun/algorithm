#include <iostream>
#include <algorithm>

using namespace std;

int n;
// 상근이가 이기면 1
// 창영이가 이기면 0
int dp[1001];

int main(void) {
	cin >> n;
	dp[1] = 1;
	dp[2] = 0;
	dp[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		if (dp[i - 1] && dp[i - 3]) dp[i] = 0;
		else
			dp[i] = 1;
	}
	if (dp[n])
		cout << "SK" << endl;
	else
		cout << "CY" << endl;
	return 0;
}