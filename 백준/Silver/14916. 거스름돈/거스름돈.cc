#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    int start = n / 5; // 최대한 5원짜리 사용
    int remain = (n - start * 5) % 2;
    while (remain != 0) { // 2원짜리로 나눴을 때 나머지가 0이면
        if (start == 0) {
            cout << -1;
            return 0;
        } // 거슬러 줄 수 없는 돈 (5원짜리가 음수가 됨)
        start -= 1; // 5원짜리 동전 한개 줄임
        remain = (n - start * 5) % 2; // 5원짜리 동전빼고 나머지를 2원으로 나눠줌
    }
    cout << start + (n - start * 5) / 2; // 5원짜리 + 2원짜리 개수
    return 0;
}
