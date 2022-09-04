#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

int n, k, ans = 0, x;
int dp[MAX];
int arr[MAX];
vector<int> v;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		cin >> x;
		v.push_back(x);
	}
	sort(v.begin(), v.end(), greater<>());

	for (int i = 0; i < n; i++)
	{
		ans += k / v[i];
		k = k % v[i];
	}
	cout << ans << endl;
	return 0;
}