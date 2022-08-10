#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<pair<int, int>> lines;

int n, a, b, ans = 0;

bool comp(pair<int, int>& a, pair<int, int>& b) {
	if (a.first == b.first) return a.second < b.second;
	else return a.first < b.first;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		lines.push_back({ a, 1 });
		lines.push_back({ b, -1 });
	}
	sort(lines.begin(), lines.end(), comp);
	int cnt = 0;
	for (int i = 0; i < lines.size(); i++) {
		cnt += lines[i].second;
		ans = max(cnt, ans);
	}
	printf("%d", ans);
}