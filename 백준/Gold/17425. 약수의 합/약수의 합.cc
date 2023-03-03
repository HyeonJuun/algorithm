#include <iostream>

long long dp[1000001];

using namespace std;

int main() {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int T, n;
    long long sum = 0;
    cin >> T;

    for (int i = 1; i <= 1000001; i++) {
        for (int j = i; j <= 1000001; j += i) {
            dp[j] += i;
        }
    }

    for (int i = 2; i <= 1000001; i++) {
        dp[i] += dp[i - 1];
    }

    for (int j = 0; j < T; j++) {
        cin >> n;
        cout << dp[n] << '\n';
    }

    return 0;
}