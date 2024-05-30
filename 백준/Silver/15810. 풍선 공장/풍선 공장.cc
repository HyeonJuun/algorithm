#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> v;

bool is_possible(long long mid) {
	long long cnt = 0;
	for (int i = 0; i < N; i++) cnt += mid / v[i];

	if (cnt >= M) return true;
	return false;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		v.push_back(a);
	}

	long long left = 1, right = 1e15, ret = -1;

	while (left <= right) {
		long long mid = (left + right) / 2;
		if (is_possible(mid)) {
			ret = mid;
			right = mid - 1;
		}
		else left = mid + 1;
	}

	cout << ret;
}