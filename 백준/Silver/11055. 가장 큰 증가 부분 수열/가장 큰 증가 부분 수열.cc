#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

int n, sum = 0;
int max_num = 0;
int dp[MAX];
int arr[MAX];

int main() {
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	dp[1] = arr[1];

	for (int i = 1; i <= n; i++)
	{
		dp[i] = arr[i];
		for (int j = 1; j < i; j++)
		{
			if (arr[i] > arr[j] && dp[i] < dp[j] + arr[i])
				dp[i] = dp[j] + arr[i];
		}
		if (max_num < dp[i])
			max_num = dp[i];
	}
	cout << max_num << endl;
	return 0;
}