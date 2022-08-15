#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int alpha[26] = { 0, };

int main() {
    string str, a, b, c;
    string ans = "";
    cin >> str;
    for (int i = 1; i < str.length() - 1; ++i)
    {
        for (int j = 1; j < str.length() - i; ++j)
        {
            a = str.substr(0, i);
            b = str.substr(i, j);
            c = str.substr(i + j);
            reverse(a.begin(), a.end());
            reverse(b.begin(), b.end());
            reverse(c.begin(), c.end());
            if (ans == "")
            {
                ans = a + b + c;
            }
            else
            {
                if (ans > a + b + c)
                {
                    ans = a + b + c;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}
