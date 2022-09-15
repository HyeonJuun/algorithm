#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 100000 + 1;

long long arr[MAX];

int n, k;

int main() {
	cin.sync_with_stdio(false);
	cin.tie(NULL);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);

	long long ans;
	long long max = 1;
	int cnt = 1;

	ans = arr[0];
	for (int i = 1; i < n; i++)
	{
		if (arr[i] == arr[i - 1])
			cnt++;
		else
			cnt = 1;

		if (max < cnt)
		{
			max = cnt;
			ans = arr[i];
		}
	}
	cout << ans << endl;
	return 0;
}