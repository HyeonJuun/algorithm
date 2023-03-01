#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <string>
using namespace std;

int n;
map<string, int> mp;

int main() {
    string str;

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        mp[str]++;
    }
    for (int i = 0; i < n - 1; i++)
    {
        cin >> str;
        mp[str]--;
    }
    for (auto x : mp)
    {
        if (x.second != 0)
            cout << x.first;
    }
    return 0;
}