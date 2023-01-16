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
long long ans = 2000000000;
int answer[2];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr + n);
	
	int start = 0;
	int end = n - 1;
	while (start < end)
	{
		int sum = arr[start] + arr[end];
		if (ans > abs(sum))
		{
			ans = abs(sum);
			answer[0] = arr[start];
			answer[1] = arr[end];

			if (sum == 0)
				break;
		}
		if (sum > 0)
			end--;
		else
			start++;
	}
	cout << answer[0] << " " << answer[1];
	return 0;
}