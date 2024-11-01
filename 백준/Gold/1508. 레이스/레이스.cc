#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>

#define MAX 10000 + 10
#define INF 2e9
using namespace std;

int n, m, k;
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;
    for (int i = 0; i < k; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    if (m == k)
    {
        for (int i = 0; i < m; i++)
            cout << "1";
        return 0;
    }

    int le = 0, ri = n * 2, answer = 0;
    while (le <= ri)
    {
        int mid = (le + ri) / 2;

        int res = 1, pre = v[0];
        for (int i = 1; i < k; i++)
        {
            if (mid <= v[i] - pre)
            {
                res++;
                pre = v[i];
            }
        }
        if (res >= m)
        {
            answer = mid;
            le = mid + 1;
        }
        else
        {
            ri = mid - 1;
        }
    }
    int cnt = 1, pre = v[0];
    cout << 1;
    for (int i = 1; i < k; i++)
    {
        if (v[i] - pre >= answer && cnt < m)
        {
            cout << 1;
            pre = v[i];
            cnt++;
        }
        else
            cout << 0;
    }

    return 0;
}