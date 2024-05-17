#include <iostream>
#include <cstring>
using namespace std;

int n = 0, result = 0,sum=0;
int arr[6] = { 0, };
long long dp[11][11][11][11][11][6][6] = { 0, };

long long solved(int prefer, int current,int cnt) {
	if (cnt == sum) {
		return 1;
	}
	
	long long &ret = dp[arr[1]][arr[2]][arr[3]][arr[4]][arr[5]][prefer][current];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 1; i <= n; i++) {
		if (prefer != i && current != i && arr[i]) {
			arr[i]--;
			ret += solved(current, i, cnt+1);
			arr[i]++;
		}

	}

	return ret;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	memset(dp, -1, sizeof(dp));
	cout << solved(0, 0, 0) << endl;

	return 0;
}