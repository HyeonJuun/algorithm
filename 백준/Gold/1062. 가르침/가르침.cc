#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 50 + 1;

int n, k;
string arr[MAX];
bool learn[30];
int ans = -1;

void solve(int dep, int cnt)
{
    if (dep == 26)
    {
        if (cnt == k)
        {
            int cnt2 = 0;
            for (int i = 0; i < n; i++)
            {
                bool flag = true;
                for (int j = 0; j < arr[i].length(); j++)
                {
                    if (learn[arr[i][j] - 'a'] == false)
                        flag = false;
                }
                if (flag)
                    cnt2++;
            }
            ans = max(ans, cnt2);
        }
        return;
    }
    
    if (learn[dep])
    {
        solve(dep + 1, cnt);
    }
    else
    {
        learn[dep] = true;
        solve(dep + 1, cnt + 1);
        learn[dep] = false;
        solve(dep + 1, cnt);
    }
}
int main() {
    
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    if (k < 5)
    {
        cout << 0;
    }
    else
    {
        learn['a' - 'a'] = true;
        learn['n' - 'a'] = true;
        learn['t' - 'a'] = true;
        learn['i' - 'a'] = true;
        learn['c' - 'a'] = true;
        solve(0, 5);
        cout << ans;
    }
   
    return 0;
}