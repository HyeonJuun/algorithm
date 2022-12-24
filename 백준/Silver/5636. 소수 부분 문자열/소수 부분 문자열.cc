#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;

bool prime[MAX] = { true, true, };

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for (int i = 2; i <= 320; i++)
	{
		for (int j = i * 2; j < 100000; j += i)
		{
			prime[j] = true;
		}
	}
	while (true)
	{
		string str;
		cin >> str;
		if (str == "0")
			return 0;
		int ans = 0;
		for (int i = 0; i < str.size(); i++)
		{
			int k = 0; 
			for (int j = 0; j < 5 && j < (str.size() - i); j++)
			{
				k *= 10;
				k += (int)str[i + j] - '0';
				if (!prime[k])
					ans = max(ans, k);
			}
		}
		cout << ans << '\n';
	}
	
	return 0;
}