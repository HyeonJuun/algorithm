#include <iostream>
#include <string>
#include <stack>
using namespace std;

string str;
int ans, temp;
stack<int> st;

int main() {
	cin >> str;
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '(') {
			st.push(-1);
		}
		else if (str[i] == 'H') {
			st.push(1);
		}
		else if (str[i] == 'C') {
			st.push(12);
		}
		else if (str[i] == 'O') {
			st.push(16);
		}
		else if (str[i] >= '2' && str[i] <= '9') {
			temp = st.top() * (str[i] - '0');
			st.pop();
			st.push(temp);
		}
		else if (str[i] == ')') {
			int num = 0;
			while (st.top() != -1) {
				num += st.top();
				st.pop();
			}
			st.pop();
			st.push(num);
		}
	}
	while (!st.empty()) {
		ans += st.top();
		st.pop();
	}
	cout << ans << '\n';
}