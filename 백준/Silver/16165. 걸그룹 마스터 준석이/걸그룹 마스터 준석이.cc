#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
#include <map>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int n, m;
string team, name;
map<string, string> mp;

// 사람 -> 팀
// 팀 -> 사람

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        cin >> team;
        cin >> count;
        for (int j = 0; j < count; j++)
        {
            cin >> name;
            mp[name] = team;
        }
    }
    for (int i = 0; i < m; i++)
    {

        map<string, string>::iterator iter;
        string str;
        int qeustion;
        cin >> str;
        cin >> qeustion;
        if (qeustion == 1)
        {
            iter = mp.find(str);
            if (iter != mp.end())
            {
                cout << iter->second << endl;
            }
        }
        else
        {
            for (iter = mp.begin(); iter != mp.end(); iter++)
            {
                if (iter->second == str)
                {
                    cout << iter->first << endl;
                }
            }
        }
    }
    return 0;
}