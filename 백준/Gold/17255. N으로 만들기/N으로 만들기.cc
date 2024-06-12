#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cstring>

using namespace std;

string str;
map<set<string>, int> mp;
set<string> st;

void solve(int le, int ri, string cur, set<string> st)
{
    if (cur.length() >= str.length())
    {
        if (cur == str)
        {
            mp[st]++;
        }
        return;
    }
    if (le > 0)
    {
        st.insert(str[le - 1] + cur);
        solve(le - 1, ri, str[le - 1] + cur, st);
        st.erase(str[le - 1] + cur);
    }
    if (ri < str.length())
    {
        st.insert(cur + str[ri + 1]);
        solve(le, ri + 1, cur + str[ri + 1], st);
        st.erase(cur + str[ri + 1]);
    }
    return;
}
int main()
{
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        string tmp = "";
        st.clear();
        st.insert(tmp + str[i]);
        solve(i, i, tmp + str[i], st);
    }
    cout << mp.size() << endl;
    return 0;
}