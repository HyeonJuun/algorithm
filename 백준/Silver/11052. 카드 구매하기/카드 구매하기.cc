#include <iostream>
#include <algorithm>
#include<queue>
#include<cstring>
#include<string>

using namespace std;

const int MAX = 1000 + 1;

// ( i-1개의 카드를 산거 + 1개자리 카드 사기 )
//    OR
// i개 카드 사기
// 둘중에 비싼 것으로 dp[i] 갱신

int n, k, ans = 0, x;
int dp[MAX];
int arr[MAX];
vector<int> v;

int main() {
	cin >> n ;
	for (int i = 1; i <= n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			dp[i] = max(dp[i - j] + arr[j], dp[i]);
		}
	}
	cout << dp[n] << endl;
	return 0;
}