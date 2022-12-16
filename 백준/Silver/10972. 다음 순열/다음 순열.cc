#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;

	vector<int> v(n);
	for (int i = 0; i < n; i++)
		cin >> v[i];

	if (!next_permutation(v.begin(), v.end()))
		cout << -1;
	else
		for (auto& i : v)
			cout << i << ' ';
	return 0;
}