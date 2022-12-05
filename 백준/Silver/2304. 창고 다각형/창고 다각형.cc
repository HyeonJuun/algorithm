#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
#include<queue>

using namespace std;

const int MAX = 1000 + 1;

int n;
int max_pos, max_h;
int arr[1001];
int ans = 0;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int l, h;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> l >> h;
		arr[l] = h;
		if (max_h < h)
		{
			max_pos = l;
			max_h = h;
		}
	}
	int left_h = 0;
	for (int i = 1; i < max_pos; i++)
	{
		left_h = max(left_h, arr[i]);
		ans += left_h;
	}
	int right_h = 0;
	for (int i = 1000; i > max_pos; i--)
	{
		right_h = max(right_h, arr[i]);
		ans += right_h;
	}
	cout << ans + max_h << endl;
	return 0;
}