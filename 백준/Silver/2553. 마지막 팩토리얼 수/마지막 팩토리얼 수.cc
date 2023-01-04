#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 20000 + 1;

int n;
int arr[MAX];


int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	long long ans = 1;

	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		ans %= 10000000;
		while (ans % 10 == 0)
			ans /= 10;
	}
	cout << ans % 10 << '\n';
	return 0;
}