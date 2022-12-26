#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 100 + 1;

int n;
int arr[MAX];
int ans_min = 1000000001, ans_max = -1000000001;

int Plus, Minus, mul, Div;

void solve(int p, int mi, int mu, int di, int sum, int cnt)
{
	if (cnt == n)
	{
		ans_max = max(ans_max, sum);
		ans_min = min(ans_min, sum);
		return;
	}

	if (p < Plus)
		solve(p + 1, mi, mu, di, sum + arr[cnt], cnt + 1);
	if (mi < Minus)
		solve(p, mi + 1, mu, di, sum - arr[cnt], cnt + 1);
	if (mu < mul)
		solve(p, mi, mu + 1, di, sum * arr[cnt], cnt + 1);
	if (di < Div)
		solve(p, mi, mu, di + 1, sum / arr[cnt], cnt + 1);
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	cin >> Plus >> Minus >> mul >> Div;
	solve(0, 0, 0, 0, arr[0], 1);
	cout << ans_max << endl << ans_min << endl;
	return 0;
}