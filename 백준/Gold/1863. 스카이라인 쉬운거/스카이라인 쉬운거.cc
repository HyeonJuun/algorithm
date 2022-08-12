#include <iostream>
#include <stack>
using namespace std;
int n, t, ans;
int m[55555];
static const auto fastio = []() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> t >> m[i];
    stack<int> s;
    for (int i = 0; i < n; i++) {
        if (m[i] != 0) { // 높이가 0이 아닐 때
            bool exist = false;
            while (!s.empty()) {
                if (s.top() == m[i]) { // 동일한 높이가 스택에 존재한다면 
                    exist = true;
                    break;
                }
                if (s.top() < m[i]) { // 스택에 있는 값 보다 크다면
                    break;
                }
                s.pop();
            }
            if (exist) continue;
            else { // 스택이 다 비워졌거나, 스택에 있는 값보다 크다면
                s.push(m[i]);
                ans++;
            }
        }
        else while (!s.empty()) s.pop(); // 높이가 0이면 스택을 비운다.
    }    
    cout << ans;
    return 0;
}