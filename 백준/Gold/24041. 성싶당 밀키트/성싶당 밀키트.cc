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

#define MAX 200000 + 10
#define INF 2100000000
#define ll long long int
#define pii pair<int, int>

struct NODE
{
    ll s;
    ll l;
    ll o;
};
bool cmp(NODE a, NODE b)
{
    if (a.o == b.o)
    {
        if (a.l == b.l)
        {
            return a.s < b.s;
        }
        return a.l > b.l;
    }
    return a.o < b.o;
}
ll n, g, k;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> g >> k;

    vector<NODE> v(n);
    int pos_cnt = 0;
    ll le = 0, ri = INF;

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].s >> v[i].l >> v[i].o;
        if (v[i].o == 1)
        {
            pos_cnt++;
        }
    }
    ll answer = 0;
    while (le <= ri)
    {
        ll mid = (le + ri) / 2;
        ll sum = 0;
        vector<ll> sums;
        for (int i = 0; i < v.size(); i++)
        {
            ll tmp = v[i].s * max(1LL, mid - v[i].l);
            sum += tmp;
            if (v[i].o == 1)
            {
                sums.push_back(tmp);
            }
        }
        sort(sums.begin(), sums.end(), greater<ll>());

        int len = k > sums.size() ? sums.size() : k;
        for (int i = 0; i < len; i++)
        {
            sum -= sums[i];
        }

        if (sum <= g)
        {
            answer = max(answer, mid);
            le = mid + 1;
        }
        else
            ri = mid - 1;
    }
    cout << answer << endl;
    return 0;
}