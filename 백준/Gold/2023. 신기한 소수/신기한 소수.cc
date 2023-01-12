#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 10000000 + 1;

int n;
int arr[8];

bool ck_prime(int num)
{
	for (int i = 2; i * i <= num; i++)
	{
		if (num % i == 0)
			return false;
	}
	return true;
}

void solve(int dep, int num)
{
	if (dep == n)
	{
		cout << num << '\n';
		return;
	}
	for (int i = 1; i <= 9; i++)
	{
		if (ck_prime(num * 10 + i))
		{
			solve(dep + 1, num * 10 + i);
		}

	}
}
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;
	solve(1, 2);
	solve(1, 3);
	solve(1, 5);
	solve(1, 7);
	return 0;
}