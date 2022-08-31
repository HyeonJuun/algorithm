#include <bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
long long dp[1010][1010]={0};

int main(){
	dp[1][1]=1;
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i=1; i<=n; i++){
		for(int j=1; j<=m; j++){
			if(i*j!=1) dp[i][j] = (dp[i][j-1]%mod + dp[i-1][j]%mod + dp[i-1][j-1]%mod)%mod;
		}
	}
	printf("%lld", dp[n][m]%mod);
}