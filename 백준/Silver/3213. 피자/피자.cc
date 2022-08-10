#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n; 
	cin >> n;
	vector<int>arr(3, 0);
	for (int i = 0; i < n; i++) {
		char a, b, c; cin >> a >> b >> c;
		if (a == '1') {
			if (c == '4')
				arr[0]++;
			else
				arr[1]++;
		}
		else
			arr[2]++;
	}
	int sum = arr[1] / 2;
	arr[1] -= sum * 2;

	int tmp = min(arr[0], arr[2]);
	arr[0] -= tmp; arr[2] -= tmp;
	sum += tmp;

	tmp = min(arr[0], arr[1]);
	arr[0] -= tmp; arr[1] -= tmp;
	sum += tmp;

	tmp = arr[0] / 4;
	sum += tmp;
	arr[0] -= tmp * 4;
	if (arr[0])
		sum++;
	sum += (arr[2] + arr[1]);
	cout << sum;
	return 0;
}