#include <iostream> 
#define mod 15746

using namespace std;

int main(){

	int n;
	cin >> n;
	int dp[n+1];
	
	// 타일은 00 , 1 
	
	dp[1] = 1 % mod; // 1
	dp[2] = 2 % mod; // 00 1+1
	// dp[3] = 3; // 00+1 1+00 1+1+1
	// dp[4] = 5; // 00+00 00+1+1 1+1+00 1+1+1+1 1+00+1
	// dp[5] = 8;// 00+00+1 00+1+00 1+00+00 1+1+1+00 1+1+00+1 1+00+1+1 00+1+1+1 1+1+1+1+1
	
	for(int i=3; i<=n; i++){
		dp[i] = (dp[i-2] + dp[i-1]) % mod ;
	}
	
	cout << dp[n] << "\n";
	
    return 0;
}