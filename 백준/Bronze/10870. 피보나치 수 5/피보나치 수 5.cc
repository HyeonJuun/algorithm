#include <iostream>


using namespace std;

long long PN[1500050];
int inf = 1000000;

long long Pnum(int n)
{
	if (n == 0) return 0;
	if (n == 1) return 1;
	if (PN[n] != 0) return PN[n];
	return PN[n] = (Pnum(n - 1) + Pnum(n - 2)) % inf;
}

int main() {
	long long n;
	cin >> n;
	cout << Pnum(n) << endl;
	return 0;
}