#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long num[1000001];

int main() {
	long long min, max;
	int cnt = 0;
	cin >> min >> max;

	for(long long i=2; i * i <= max; i++)
	{
		long long n = min / (i * i);

		if (min % (i * i)) n++;
		while (n * i * i <= max)
		{
			num[n * i * i - min] = 1;
			n++;
		}
	}
	for (int i = 0; i <= max - min; i++)
	{
		if (num[i] == 0) cnt++;
	}
	cout << cnt << endl;
	return 0;
}