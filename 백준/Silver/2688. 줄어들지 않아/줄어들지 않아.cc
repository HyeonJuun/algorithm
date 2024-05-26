#include <iostream>
#include <vector>
using namespace std;
// 줄어들지 않아
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0);
	int t, n;
	cin >> t;
	vector<vector<long long>> dp(66, vector<long long>(10, 1));
	for (int i=2; i<=65; i++) {
		for (int j=1; j<10; j++) {
			dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	while (t--) {
		cin >> n;
		cout << dp[n+1][9] << "\n";
	}
}