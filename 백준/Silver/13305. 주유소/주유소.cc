#include <iostream>

using namespace std;

#define MAX 100000

int n;
//first == 도로 길이 second == 주유소 가격
pair<long long,long long> input[MAX];
long long answer;
int main() {

	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> input[i].first;
	}
	for (int i = 0; i < n; i++) {
		cin >> input[i].second;
	}
	int cur = 0;
	answer = input[cur].first*input[cur].second;
	for (int i = 1; i < n; i++) {
		if (input[cur].second > input[i].second) {
			cur = i;
		}
		answer += input[i].first*input[cur].second;
	}
	cout << answer;
	return 0;
}