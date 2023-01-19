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

int n;
long long arr[MAX];
long long prefix[MAX];
long long ans = 0, sum = 0;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
		prefix[i] = prefix[i - 1] + arr[i];
	}
	for (int i = 0; i < n ; i++)
	{
		ans += arr[i] * (prefix[n] - prefix[i]);
	}
	cout << ans;
	return 0;
}