#include <iostream>
#include <algorithm>

using namespace std;
int main(void) {
	int N;
	double dp[10000], num[10000], maxi = -1;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> num[i];
		if (i == 0)
			dp[i] = num[i];
		else 
		{
			dp[i] = max(num[i], dp[i - 1] * num[i]);
		}
		maxi = max(maxi, dp[i]);
	}
	printf("%.3lf", maxi);

	return 0;
}