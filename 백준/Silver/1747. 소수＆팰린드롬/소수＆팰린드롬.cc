#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000000 + 1;

int n, ans = 0;
bool Prime[MAX];

bool isPal(int n)
{
	string front, back;
	front = back = to_string(n);
	reverse(back.begin(), back.end());

	if (front == back)
		return true;
	else
		return false;
}

bool isPrime(int n)
{
	if (n < 2)return false;
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return false;
	}
	return true;
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	while (true)
	{
		if (isPal(n) == true && isPrime(n) == true)
		{
			ans = n;
			break;
		}
		n++;
	}
	cout << ans << '\n';
	return 0;
}