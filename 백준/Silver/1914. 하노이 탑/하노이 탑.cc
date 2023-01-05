#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

using namespace std;

const int MAX = 1000 + 1;

int n;
void hanoi(int start, int mid, int end, int n)
{
	if (n == 1)
	{
		cout << start << " " << end << '\n';
	}
	else
	{
		hanoi(start, end, mid, n - 1);
		cout << start << " " << end << "\n";
		hanoi(mid, start, end, n - 1);
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	string a = to_string(pow(2, n) );
	string ans = "";
	for (int i = 0; i < a.length(); i++)
	{
		if (a[i] == '.')
			break;
		else
			ans += a[i];
	}
	ans[ans.length() - 1] -= 1;

	cout << ans << '\n';
	if(n <= 20)
		hanoi(1, 2, 3, n);
	return 0;
}