#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <map>
using namespace std;


int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
    int n;
    cin >> n;
    while (n--)
    {
        map<long long, int> mp;
        long long mx = -1, idx = -1;
        int num;
        cin >> num;
        for (int i = 0; i < num; i++)
        {
            long long x;
            cin >> x;
            if (mp[x] == 0)
            {
                mp[x] = 1;
            }
            else
            {
                mp[x]++;
            }
            if (mp[x] > mx)
            {
                idx = x;
                mx = mp[x];
            }
        }
        if (mx > num / 2)
            cout << idx << '\n';
        else
            cout << "SYJKGW\n";
    }
    return 0;
}