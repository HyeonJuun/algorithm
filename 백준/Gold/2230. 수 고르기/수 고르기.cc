#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 100000 + 1;

int n, m;
int arr[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
	int s = 0, e = 0, mn = 2000000000;
	while (s <= e && e < n)
	{
		int sub = arr[e] - arr[s];
		if (sub >= m)
		{
			if (sub < mn)
				mn = sub;
			s++;
		}
		else
			e++;
	}
	cout << mn;
	return 0;
}