#include <bits/stdc++.h>
using namespace std;

double n,y,k,a;
vector<pair<double, double>> v;
bool state;

int main(void) {

	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> y; v.push_back(make_pair(i + 1, y));
	}
	cin >> k;
	a = v[0].second / v[0].first;
	if (k == a) {
		cout << "T"; return 0;
	}
	else if (k < a) state = true;	
	else state = false;
	for (int i = 1; i < n; ++i) {
		a = v[i].second / v[i].first;
		if (k == a) {
			cout << "T"; return 0;
		}
		if (k>a and state) {
			cout << "T"; return 0;
		}
		if (k < a and !state) {
			cout << "T"; return 0;
		}
	}
	cout << "F";
}