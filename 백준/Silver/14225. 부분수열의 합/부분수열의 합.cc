#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
using namespace std;

const int MAX = 20000000 + 1;

int n;
int arr[21];
int ck_sum[MAX];


void solve(int x, int sum)
{
	ck_sum[sum] = true;
	if (x == n)
		return;
	else
	{
		solve(x + 1, sum);
		solve(x + 1, sum + arr[x]);
	}
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];

	solve(0, 0);
	int j = 1;
	while (ck_sum[j] == true)
		j++;
	cout << j;
	return 0;
}