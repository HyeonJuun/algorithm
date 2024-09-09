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

#define MAX 100 + 10
#define INF 987654321

int n, l, answer;
int mp[MAX][MAX];
int mp2[MAX][MAX];
bool check_road(int mp[][MAX], int x, int y)
{
    int num = mp[x][y + 1];
    for (int i = y + 1; i < y + 1 + l; i++)
    {
        if (mp[x][i] != num)
            return false;
    }
    return true;
}
int solve(int mp[][MAX])
{
    int res = 0;

    for (int i = 0; i < n; i++)
    {
        bool flag = true;
        int before_road = 1;

        for (int j = 0; j < n - 1; j++)
        {
            if (mp[i][j] == mp[i][j + 1])
                before_road++;
            else if (mp[i][j] == mp[i][j + 1] + 1)
            {
                if (check_road(mp, i, j) == true)
                {
                    j = j + l - 1;
                    before_road = 0;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (mp[i][j] + 1 == mp[i][j + 1])
            {
                if (before_road >= l)
                {
                    before_road = 1;
                }
                else
                {
                    flag = false;
                    break;
                }
            }
            else if (abs(mp[i][j] - mp[i][j + 1]) >= 2)
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            res++;
        }
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> mp[i][j];
            mp2[j][i] = mp[i][j];
        }
    }

    int a = solve(mp);
    int b = solve(mp2);
    cout << a + b << endl;
    return 0;
}