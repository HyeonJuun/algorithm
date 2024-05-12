#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int digit(int n) {
	int a = 0;
	while (1) {
		int b = n / pow(10, a);
		if (b < 10)
		{
			break;
		}
		a++;
	}
	return a + 1;
}

bool check소수(int n) {
	int a = 2;
	if (n == 1) {
		return false;
	}
	else {
		while (1) {
			int b = n % a;
			if (b == 0) {
				break;
			}
			a++;
		}
		if (n == a) {
			return true;
		}
		else {
			return false;
		}
	}
}

bool check이면수(int n) {
	int temp = n;
	int a = digit(n);
	vector<int> v;
	while (a>1) {
		int i = n / pow(10, a - 1);
		v.push_back(i);
		n = n - (i * pow(10, a - 1));
		a--;
	}
	v.push_back(n);
	int b = 0;
	for (int i = 0; i < v.size(); i++) {
		b += v[i];
	}
	if (temp >= 4 && temp!=5 && b % 2 == 1) {
		return true;
	}
	else {
		return false;
	}
}

bool check임현수(int n) {
	vector<int> v;
	if (n == 2 || n == 4) {
		return true;
	}

	else if (check소수(n) == true || n==1) {
		return false;
	}
	else {
		for (int i = 2; i < n; i++) {
			int a = n % i;
			if (a == 0 && check소수(i)==true) {
				v.push_back(i);
			}
		}
		if (v.size() % 2 == 0) {
			return true;
		}
		else {
			return false;
		}
	}
}

int main() {
	int n;
	cin >> n;
	if (check임현수(n) == true && check이면수(n) == true) {
		cout << 4;
	}
	else {
		if (check이면수(n) == true) {
			cout << 1;
		}
		else if(check임현수(n)==true) {
			cout << 2;
		}
		else {
			cout << 3;
		}
	}
}