#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int alpha[26] = { 0, };
vector<string> v;
int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        v.push_back(str);
    }
    for (int i = 0; i < n; i++)
    {
        string s = v[i];
        int len = s.length();
        int p = 1;
        for (int j = len - 1; j >= 0; j -- )
        {
            int temp = s[j] - 'A';
            alpha[temp] = alpha[temp] + p;
            p = p * 10;
        }
    }
    sort(alpha, alpha + 26, greater<>());
    int ans = 0;
    int num = 9;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] == 0) break;
        ans += alpha[i] * num;
        num--;
    }
    cout << ans << endl;
    return 0;
}
