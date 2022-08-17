#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <set>

using namespace std;


int main() {
    int n;
    cin >> n;
    vector<string> str;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        reverse(s.begin(), s.end());
        str.push_back(s);
    }
    int ans = 1;
    while (true)
    {
        set<string> s;
        for (int i = 0; i < str.size(); i++)
        {
            s.insert(str[i].substr(0, ans));
        }
        if (s.size() == str.size())
            break;
        else
            ans++;
    }
    cout << ans;
    return 0;
}
