#include <iostream>
#include <cmath>

using namespace std;

int main(){
	cin.tie(0);
	int t;
	cin >> t;
	
	long long x, y;
	
	for(int i=0; i<t; i++){
		cin >> x >> y;
		double distance = y-x; // 두 지점 사이의 거리
		double dpow = sqrt(distance); // 거리의 제곱근
		int pow = round(sqrt(distance)); // 거리의 제곱근을 반올림
		
		if(dpow <= pow) cout << pow * 2 - 1 << "\n"; 
		else cout << pow * 2 << "\n"; 
	}
		
	return 0;
}