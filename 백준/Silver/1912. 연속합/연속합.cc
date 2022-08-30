#include <iostream>
#include <vector>
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

const int MAX = 100000 + 1;
int dp[MAX] = { 0, };
int arr[MAX] = { 0, };
int n;
vector<int> v;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
		dp[i] = arr[i];
	}
	int max_sum = dp[0];
	for (int i = 1; i < n; i++)
	{
		dp[i] = max(dp[i], dp[i - 1] + arr[i]);
		if (dp[i] > max_sum)
			max_sum = dp[i];
	}
	cout << max_sum << endl;
	return 0;
}