#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 10000 + 1;

int dp[MAX] = { 0, };
int arr[MAX] = { 0, };
int n, x, ans=0;

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
	dp[0] = 0;
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	for (int i = 3; i <= n; i++)
	{
		dp[i] = max(dp[i-3] + arr[i-1] + arr[i], max(dp[i-2] + arr[i], dp[i-1]));
	}
	cout << dp[n] << endl;
	return 0;
}