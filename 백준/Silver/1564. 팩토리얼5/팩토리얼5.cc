#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 1000000 + 1;

int n;
long long ans = 1;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		ans *= i;
		while (ans % 10 == 0)
			ans /= 10;
		ans %= 1000000000000;
	}
	ans %= 100000;

	if (0 <= ans && ans < 10)
		cout << "0000" << ans;
	else if (10 <= ans && ans < 100)
		cout << "000" << ans;
	else if (100 <= ans && ans < 1000)
		cout << "00" << ans;
	else if (1000 <= ans && ans < 10000)
		cout << "0" << ans;
	else
		cout << ans;
	return 0;
}