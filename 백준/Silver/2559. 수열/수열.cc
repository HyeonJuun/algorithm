#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100000 + 1;

int n, k, x, ans =  -1 * MAX;

int arr[MAX];



int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++)
	{
		cin >> x;
		arr[i] = arr[i - 1] + x;
	}

	for (int i = k; i <= n; i++)
	{
		ans = max(ans, arr[i] - arr[i - k]);
	}

	cout << ans << '\n';
	
	return 0;
}