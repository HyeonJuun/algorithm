#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 1000 + 1;

long long n, m;

long long solve(int a, int b)
{
	int num = 0;
	for (long long i = b; n / i >= 1; i *= b)
	{
		num += a / i;
	}
	return num;
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	long long five = 0;
	long long two = 0;
	five = solve(n, 5) - solve(n - m, 5) - solve(m, 5);
	two = solve(n, 2) - solve(n - m, 2) - solve(m, 2);

	long long ans = min(five, two);
	cout << ans << endl;
	return 0;
}