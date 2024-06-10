#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ld = long double;

int t, n, arr[109];
int main()
{
	scanf("%d", &t);
	for(int i = 1; i <= t; i ++){
		scanf("%d", &n);
		for(int j = 1; j <= n; j ++){
			scanf("%d", arr + j);
		}
		vector <int> od, ev;
		for(int j = 1;j  <= n; j ++){
			if(arr[j] % 2) od.push_back(arr[j]);
			else ev.push_back(arr[j]);
		}
		sort(od.begin(), od.end());
		sort(ev.begin(), ev.end());
		reverse(ev.begin(), ev.end());
		int oi = 0, ei = 0;
		printf("Case #%d: ", i);
		for(int j = 1; j <= n; j ++){
			if(arr[j] % 2) printf("%d ", od[oi++]);
			else printf("%d ", ev[ei++]);
		}
		printf("\n");
	}
    return 0;
}