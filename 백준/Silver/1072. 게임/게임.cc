#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<queue>
#include<cmath>
using namespace std;

#define MAX 1000000000

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	long long x, y, mid;
	cin >> x >> y;
	long long z = (y * 100) / x ;
	if (z >= 99)
	{
		cout << -1 << endl;
		return 0;
	}
	long long left = 0, right = MAX;
	long long ans = -1;
	while (left <= right)
	{
		mid = (left + right) / 2;
		long long new_z = ((y + mid) * 100) / (x + mid);
		if (z >= new_z)
		{
			ans = mid + 1;
			left = mid + 1;
		}
		else
			right = mid - 1;
	}
	cout << ans << endl;
	return 0;
}