#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 10000010 + 1;

int t;
int n, m;

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> t;
	while (t--)
	{
		cin >> n >> m;
		vector<int> fibo;
		fibo.push_back(0);
		fibo.push_back(1);
		fibo.push_back(1);
		int i = 3;
		while (true)
		{
			fibo.push_back((fibo[i - 1] + fibo[i - 2]) % m);
			if (fibo[i - 1] % m == 0 && fibo[i] % m == 1)
				break;
			i++;
		}
		cout << n << " " << i - 1 << '\n';
	}

	return 0;
}