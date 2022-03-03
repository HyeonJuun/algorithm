#include <iostream>

using namespace std;

long long d[1001];

long long dp(int n)
{
	if (n == 1 || n == 2) return 1;
	if (n == 3) return 2;
	if (d[n] != 0) return d[n];
	return d[n] = dp(n - 1) + dp(n - 2);
}
int main() {

		long long x;
		cin >> x;
		cout << 2 * dp(x) + 2 * dp(x+1) << endl;
	return 0;
}