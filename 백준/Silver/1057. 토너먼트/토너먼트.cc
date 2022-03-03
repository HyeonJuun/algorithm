#include <iostream>
#include <cmath>

using namespace std;

int main() {
	int n;
	double kim, im;
	cin >> n >> kim >> im;
	
	int cnt = 0;

	while(kim != im){
		kim = ceil(kim/2);
		im = ceil(im/2);
		cnt++;
	}
	
	cout << cnt;
	
	return 0;
}