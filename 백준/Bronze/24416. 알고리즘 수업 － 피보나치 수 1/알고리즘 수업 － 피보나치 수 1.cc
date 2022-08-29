#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
#include<algorithm>
using namespace std;

const int MAX = 40 + 1;

int n, cnt1 = 0, cnt2 = 0;

long long dp[MAX] = { 0, };
int fib(int n)
{
	if (n == 1 || n == 2)
	{
		cnt1++;
		return 1;
	}
	else
		return (fib(n - 1) + fib(n - 2));
}


int main(void)
{
	cin >> n;
	fib(n);
	dp[1] = 1;
	dp[2] = 1;
	for (int i = 3; i <= n; i++)
	{
		dp[i] = dp[i - 1] + dp[i - 2];
		cnt2++;
	}
	cout << cnt1 << " " << cnt2 << endl;
	return 0;

}
