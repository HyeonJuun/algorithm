#include<iostream>
#include<vector>
#include<memory.h>
#include<algorithm>
#include <map>
#include<cmath>
using namespace std;

const int MAX = 100000 + 1;

long long n;
long long  k;


long long  getOder(long long  num)
{
	long long   res = 0;
	for (int i = 1; i <= n; i++)
	{
		res += min(n, (long long)num / i);
		if (i > num)
			break;
	}
	return res;
}
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	long long  s = 1, e = n * n, ans = 0;
	while (s <= e)
	{
		long long  mid = (s + e) / 2;
		long long  oder = getOder(mid);
		if (oder < k)
		{
			s = mid + 1;
		}
		else
		{
			ans = mid;
			e = mid - 1; 
		}
	}
	cout << ans;
	return 0;
}