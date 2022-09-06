#include <iostream>
#include <vector>
#include <algorithm>
#include<stack>
#include<deque>
#include<queue>

using namespace std;

const int MAX = 500000 + 1;

int n, m, x;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n;
	vector<long long> v(n);
	for (int i = 0; i < n; i++)
	{
		cin >> v[i];
	}
	sort(v.begin(), v.end());
	cin >> m;
	for (int i = 0; i < m; i++)
	{
		cin >> x;
		if (binary_search(v.begin(), v.end(), x))
			cout << 1 << " ";
		else
			cout << 0 << " ";
	}
	cout << endl;
	return 0;
}