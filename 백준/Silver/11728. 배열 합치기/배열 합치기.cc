#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <map>

using namespace std;

const int MAX = 2000000 + 1;

int n, m;
int arr_A[MAX], arr_B[MAX];

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr_A[i];
	for (int i = 0; i < m; i++)
		cin >> arr_B[i];
	int ans[MAX];
	int i = 0, j = 0, k = 0;
	while (i < n && j < m)
	{
		if (arr_A[i] > arr_B[j])
			ans[k++] = arr_B[j++];
		else
			ans[k++] = arr_A[i++];
	}
	if (i >= n)
	{
		while (j < m)
		{
			ans[k++] = arr_B[j++];
		}
	}
	else
	{
		while (i < n)
		{
			ans[k++] = arr_A[i++];
		}
	}
	for (int a = 0; a < n + m; a++)
	{
		cout << ans[a] << " ";
	}
	return 0;
}