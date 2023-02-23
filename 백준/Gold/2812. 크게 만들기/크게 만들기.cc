#include <iostream>
#include <string>
#include <deque>
using namespace std;

int n, k;
string val;
deque <char> deq;
int main() {
	iostream::sync_with_stdio(0);
	cin.tie(0);
	int n, k;
	cin >> n >> k;
	cin >> val;

	for (int i = 0; i < val.length(); i++) {

		while (k && !deq.empty() && deq.back() < val[i]) {
			deq.pop_back();
			k--;
		}
		deq.push_back(val[i]);
	}


	for (int i = 0; i < deq.size() - k; i++) 
		cout << deq[i];
	
	cout << "\n";

	return 0;
}