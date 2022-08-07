#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int n;
	long long ans = 0;
	cin >> n;
	vector <int> m;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		m.push_back(a);
	}
	sort(m.begin(), m.end(), greater<int>());
	for (int i = 0; i < n; i++)
	{
		if (m[i] - (i - 1) <= 0)
			break;
		ans += m[i] - i ;
	}
	cout << ans << endl;
	return 0;
}
