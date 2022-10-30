#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 9;


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;	cin >> n;

	int x = 0;
	int cnt = 0;
	int temp;
	while (1)
	{
		if (cnt == n)
			break;
		x++;
		temp = x;
		while (temp != 0)
		{
			if (temp % 1000 == 666)
			{
				cnt++;
				break;
			}
			else
				temp /= 10;
		}
	}
	cout << x << '\n';
	return 0;
}