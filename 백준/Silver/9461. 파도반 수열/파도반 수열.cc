#include <iostream>
#include <vector>
#include<iostream>
#include<cstring>
#include <algorithm>
using namespace std;

const int MAX = 1000 + 1;
long long arr[MAX];

long long dp(int n) {

	if (n == 0 or n == 1 or n == 2) return 1;

	if (arr[n] != 0) return arr[n];

	else {
		arr[n] = dp(n - 2) + dp(n - 3);
		return arr[n];
	}
}

int main() {
	int t;
	int n;
	cin >> t;

	while(t--) 
	{
		cin >> n;
		cout << dp(n - 1) << endl;
	}

}