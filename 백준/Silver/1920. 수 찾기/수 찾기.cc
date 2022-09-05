#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int n, m, num;
	cin >> n;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}
	sort(v.begin(), v.end());

	cin >> m;
	for(int i = 0; i < m; i++) {
		cin >> num;
		if (binary_search(v.begin(), v.end(), num)) {
			cout << "1" << "\n";
		}
		else cout << "0" << "\n";
	}
	return 0;
}