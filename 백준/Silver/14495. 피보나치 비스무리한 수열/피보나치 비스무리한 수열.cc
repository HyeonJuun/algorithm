#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 116 + 1;

long long p[MAX];
int n;

int main() {
	cin >> n;
	p[1] = p[2] = p[3] = 1;
	for (int i = 4; i <= n; i++)
	{
		p[i] = p[i - 1] + p[i - 3];
	}
	cout << p[n] << endl;
	return 0;
}