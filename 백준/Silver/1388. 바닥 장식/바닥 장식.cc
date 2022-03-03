#include <iostream>
using namespace std;
int n, m, i, t, c; string s[105];
int main() {
	cin >> n >> m;
	for (; i < n; i++)	cin >> s[i];
	for (i = 0; i < n; i++)
		for (t = 0; t < m; t++) {
			if (s[i][t] == '-')if (t == m - 1 || s[i][t + 1] == '|')c++;
			if (s[i][t] == '|')if (i == n - 1 || s[i + 1][t] == '-')c++;
		}
	cout << c << endl;
}