#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 1000 + 1;

long long a, b;

long long gcd(long long a, long long b)
{
	if (a % b == 0)
	{	
		return b;
	}
	return gcd(b, a % b);
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> a >> b;
	long long n = gcd(a, b);
	while (n--)
		cout << 1;

	return 0;
}