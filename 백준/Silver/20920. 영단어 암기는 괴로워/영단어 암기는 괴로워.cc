#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

map<string, int> mp;

bool cmp(string a, string b)
{
    if (a.length() == b.length() && mp[a] == mp[b])
        return a < b;
    else if (mp[a] == mp[b])
        return a.length() > b.length();
    return mp[a] > mp[b];
}
int main()
{
    int n, m;
    int ans = 0;
    string str;
    cin >> n >> m;
    vector<string> voca;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str.length() < m)
            continue;
        if (mp.find(str) == mp.end())
        {
            mp[str] = 0;
            voca.push_back(str);
        }
        mp[str]++;
    }
    sort(voca.begin(), voca.end(), cmp);

    for (int i = 0; i < voca.size(); i++)
        cout << voca[i] << "\n";
}