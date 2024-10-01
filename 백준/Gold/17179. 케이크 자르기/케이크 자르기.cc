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

#define MAX 400 + 10
#define INF 987654321

int n, m, l;
vector<int> cake;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m >> l;

    for (int i = 0; i < m; i++)
    {
        int x;
        cin >> x;
        cake.push_back(x);
    }
    cake.push_back(l);
    for (int i = 0; i < n; i++)
    {
        int cut = 0, answer = 0;
        int le = 0, ri = l * 2;
        cin >> cut;

        while (le <= ri)
        {
            int mid = (le + ri) / 2;
            int res = 0, c = 0;
            for (int j = 0; j < cake.size(); j++)
            {
                if (cake[j] - c > mid)
                {
                    c = cake[j];
                    res++;
                }
            }
            // cout << res << " " << mid << endl;
            if (res <= cut)
            {
                answer = mid;
                ri = mid - 1;
            }
            else
                le = mid + 1;
        }
        cout << answer << endl;
    }
    return 0;
}