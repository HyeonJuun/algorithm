#include <iostream>
#include <set>

using namespace std;

int main()
{
    int n;
    int ans = 0;
    string str;
    multiset<string> s;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "ENTER")
            s.clear();
        else
        {
            if (s.find(str) == s.end())
            {
                ans++;
                s.insert(str);
            }
        }
    }
    cout << ans;
}