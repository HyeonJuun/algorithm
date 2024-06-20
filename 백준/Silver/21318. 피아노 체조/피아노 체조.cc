#include <iostream>
#include <vector>
using namespace std;
vector<int> piano;
int cnt[101010];
int main(){
	int n, tmp, t;
	cin >> n;
	for(int i=0; i<n; i++){
		scanf("%d", &tmp);
		piano.push_back(tmp);
		if(i==0)	continue;
		if(piano[i-1] > tmp)	cnt[i] = cnt[i-1] + 1;
		else cnt[i] = cnt[i-1]; 
	}
	cin >> t;
	while(t--){
		int x, y, ans = 0;
		scanf("%d %d", &x, &y);
		ans = cnt[y-1] - cnt[x-1];
		printf("%d\n", ans);
	}
	return 0;
}
