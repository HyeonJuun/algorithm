#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int check(vector<string>& a) {
    int n = a.size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 1;
        for (int j = 1; j < n; j++) {
            if (a[i][j] == a[i][j - 1]) {
                cnt += 1;
            }
            else cnt = 1;
            if (ans < cnt) ans = cnt;
        }
        cnt = 1;
        for (int j = 1; j < n; j++) {
            if (a[j][i] == a[j - 1][i]) {
                cnt += 1;
            }
            else cnt = 1;
            if (ans < cnt) ans = cnt;
        }
    }
    return ans;
}
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int n,ans=0;
    cin >> n;
    vector<string> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (j + 1 < n) {
                swap(v[i][j], v[i][j + 1]);
                int temp = check(v);
                if (ans < temp) ans = temp;
                swap(v[i][j + 1], v[i][j]);
            }
            if (i + 1 < n) {
                swap(v[i][j], v[i + 1][j]);
                int temp = check(v);
                if (ans < temp)ans = temp;
                swap(v[i + 1][j], v[i][j]);
            }
        }
    }
    cout << ans;
}