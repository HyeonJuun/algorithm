#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 9;

// n(n-3)/2
// 0 2 5 9
// 0 1   15
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int n;	cin >> n;

	cout << n * (n - 1) * (n - 2) * (n - 3) / 24 << '\n';
	
	return 0;
}