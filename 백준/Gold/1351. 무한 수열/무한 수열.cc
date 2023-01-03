#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include<string>
#include <cstring>
#include<queue>
#include<map>

using namespace std;

const int MAX = 10000000 + 1;


long long  n, p, q;
map<long long, long long> m;

long long solve(long long num)
{
	if (m[num] != 0)
		return m[num];
	
	return m[num] = solve(num / p) + solve(num / q);

}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> p >> q;

	m[0] = 1;
	cout << solve(n);
	return 0;
}