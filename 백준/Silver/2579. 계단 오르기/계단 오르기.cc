#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 300 + 1;

int n, ans=0, cnt = 0;

long long dp[MAX] = { 0, };
int arr[MAX] = { 0, };

int main(void)
{
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];
	dp[2] = arr[1] + arr[2];
	dp[3] = max(arr[1] + arr[3], arr[2] + arr[3]);
	for (int i = 4; i <= n; i++)
	{
		dp[i] = max(dp[i - 2] + arr[i], dp[i - 3] + arr[i - 1] + arr[i]);
	}
	cout << dp[n] << endl;
	return 0;

}
