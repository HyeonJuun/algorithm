#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	vector<int> m;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m.push_back(a);
	}
	sort(m.begin(), m.end());
	long long ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans += abs(i + 1 - m[i]);
	}
	cout << ans << endl;

}
