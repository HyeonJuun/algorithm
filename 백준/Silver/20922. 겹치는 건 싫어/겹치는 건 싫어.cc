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

#define MAX 50 + 10
#define INF 987654321

int n, k, answer = 1;
vector<int> v;
map<int, int> mp;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int le = 0, ri = 1;
    mp[v[le]]++;
    while (ri != n)
    {
        mp[v[ri]]++;
        if (mp[v[ri]] > k)
        {
            answer = max(answer, ri - le);
            while (mp[v[ri]] != k)
            {
                mp[v[le]]--;
                le++;
            }
        }
        ri++;
    }
    answer = max(answer, ri - le);
    cout << answer << endl;
    return 0;
}