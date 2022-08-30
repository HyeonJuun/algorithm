#include <iostream>
#include <vector>
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
int arr[MAX];
int dp[MAX];
int n, ans = 0;
vector<int> v;


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (arr[i] > arr[j])
			{
				dp[i] = max(dp[i], dp[j] + 1);
				ans = max(dp[i], ans);
			}
		}
	}
	cout << ans + 1 << endl;
	return 0;
}