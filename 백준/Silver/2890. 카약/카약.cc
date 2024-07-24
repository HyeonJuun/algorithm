#include <iostream>
#include <vector>
using namespace std;

int main() {
	int R, C;
	int rank[10] = { 0, };
	int cnt = 1;
	bool is_rank = false;
	vector<string> v;
	
	cin >> R >> C;

	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		v.push_back(s);
	}

	for (int i = C - 2; i >= 1; i--) {
		for (int j = 0; j < R; j++) {
			int kayak = v[j][i] - '0';
			if (!rank[kayak] && kayak > 0 && kayak <= 9) {
				rank[kayak] = cnt;
				is_rank = true;
			}
		}
		if(is_rank) cnt++;
		is_rank = false;
	}

	for (int i = 1; i <= 9; i++) cout << rank[i] << '\n';

}