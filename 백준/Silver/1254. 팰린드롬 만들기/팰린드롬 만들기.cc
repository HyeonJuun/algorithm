#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;

string s;
int len;
bool pal(int idx) {
    for (int i = 0; i + idx < len - i - 1; i++)
    {
        if (s[idx + i] != s[len - i - 1])
            return false;
    }
    return true;
}
int main() {
    cin >> s;
    len = s.size();
    int ans = 0;

    for (int i = 0; i < len; i++)
    {
        if (pal(i))
        {
            ans = len + i;
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
