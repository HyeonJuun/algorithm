#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<string> str_v;
    string ans;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        str_v.push_back(str);
    }
    if (n == 1)
        cout << str_v[0] << endl;
    else
    {
        for (int i = 0; i < str_v[0].length(); i++)
        {
            char c = str_v[0][i];
            for (int j = 0; j < str_v.size(); j++)
            {
                if (c != str_v[j][i])
                {
                    c = '?';
                }
            }
            ans += c;
        }
    }
    cout << ans << endl;
    return 0;
}
