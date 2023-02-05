#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;

const int MAX = 50 + 1;

int n, m, k;
int parents[MAX];
vector<int> know;
vector<vector<int>> v(MAX);
int ans = 0;
int Find(int x)
{
    if (parents[x] == x)
        return x;
    return x = Find(parents[x]);
}
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);
    parents[x] = y;
}
int main() {

    cin >> n >> m >> k;
    while (k--)
    {
        int t;
        cin >> t;
        know.push_back(t);
    }
    for (int i = 1; i <= n; i++)
        parents[i] = i;
    int x = m;
    for(int j=0; j<m;j++)
    {
        int p;
        cin >> p;
        int num, prev;
        for (int i = 0; i < p; i++)
        {
            if (i >= 1)
            {
                prev = num;
                cin >> num;
                Union(prev, num);
            }
            else
                cin >> num;
            v[j].push_back(num);
        }
    }

    for (auto l : v)
    {
        bool flag = false;
        for (auto person : l)
        {
            if (flag)
                break;
            for (auto t : know)
            {
                if (Find(person) == Find(t))
                {
                    flag = true;
                    break;
                }
            }
        }
        if (flag)
            m--;
    }
    cout << m;
    return 0;
}