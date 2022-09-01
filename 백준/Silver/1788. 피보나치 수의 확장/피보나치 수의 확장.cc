#include <iostream>
#include <algorithm>
#define mod 1000000000;

using namespace std;

const int MAX = 1000000 + 1;
int p[MAX];

int n, ind;

int main() {
	cin >> n;
	if (n < 0)
		ind = n * (-1);
	else
		ind = n;
	if (ind == 0)
	{
		cout << 0 << endl << 0;
		return 0;
	}
	p[0] = 0;
	p[1] = 1;
	for (int i = 2; i <= ind; i++)
	{
		p[i] = (p[i - 1] + p[i - 2]) % mod;
	}
	p[ind] = p[ind] % mod;
	if (n < 0)
	{
		if (ind % 2 == 0)
		{
			cout << -1 << endl;
			cout << p[ind] << endl;
			return 0;
		}
	}
	cout << 1 << endl << p[ind] << endl;
	return 0;
}