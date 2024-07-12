#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <algorithm>
#define FASTIO cin.tie(0); cout.tie(0); ios::sync_with_stdio(false);

using namespace std;
int N, C, X;
deque<int> DQ;

void input() {
    cin >> N;
    while (N--) {
        cin >> C;
        if (C == 1) {
            cin >> X;
            DQ.push_front(X);
        }
        else if (C == 2) {
            cin >> X;
            DQ.push_back(X);
        }
        else if (C == 3) {
            if (DQ.empty()) {
                cout << "-1\n";
            }
            else {
                cout << DQ.front() << "\n";
                DQ.pop_front();
            }
        }
        else if (C == 4) {
            if (DQ.empty()) {
                cout << "-1\n";
            }
            else {
                cout << DQ.back() << "\n";
                DQ.pop_back();
            }
        }
        else if (C == 5) {
            cout << (int)DQ.size() << "\n";
        }
        else if (C == 6) {
            if (DQ.empty()) {
                cout << "1\n";
            }
            else {
                cout << "0\n";
            }
        }
        else if (C == 7) {
            if (DQ.empty()) {
                cout << "-1\n";
            }
            else {
                cout << DQ.front() << "\n";
            }
        }
        else if (C == 8) {
            if (DQ.empty()) {
                cout << "-1\n";
            }
            else {
                cout << DQ.back() << "\n";
            }
        }
    };
}

int main() {
    FASTIO
    input();

    return 0;
}