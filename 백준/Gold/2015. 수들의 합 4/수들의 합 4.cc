#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include <map>
using namespace std;

const int MAX = 250000 + 1;

int n, k;
int arr[MAX];
int prefix[MAX];
map<int, long long> m;

int main()
{
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}
	long long ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (prefix[i] == k)
			ans++;
		ans += m[prefix[i] - k];

		m[prefix[i]]++;
	}
	cout << ans;
	return 0;
}