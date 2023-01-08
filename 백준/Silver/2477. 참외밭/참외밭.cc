#include <bits/stdc++.h>
using namespace std;


int main(){
	int n,di,l,maxi,minis,maxis,ans;
	int len[6];
	vector<int> tok;
	
	cin >> n;

	for(int i = 0; i < 6; i++){
		cin >> di >> l;
		len[i] = l;
	}
	
	for(int i = 0; i <= 4; i++){
		tok.emplace_back(len[i] * len[i+1]);
	}
    
	tok.emplace_back(len[0] * len[5]);
	maxi = max_element(tok.begin(), tok.end())-tok.begin();
	maxis = *max_element(tok.begin(), tok.end());
	minis = tok[(maxi + 3)%6];
	
	ans = n*(maxis - minis);
	
	cout << ans << "\n";
	
	return 0;
}