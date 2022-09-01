#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 35 + 1;

long long arr[MAX];
int n;

int main() {
	cin >> n;
	arr[0] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			arr[i] += arr[j - 1] * arr[i - j];
		}
	}
	cout << arr[n] << endl;
	return 0;
}