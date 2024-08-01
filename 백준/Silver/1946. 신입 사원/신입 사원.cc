#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 1000 + 10
#define INF 987654321

int t, n;
int a, b;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        cin >> n;
        vector<pair<int, int>> v;
        for (int i = 0; i < n; i++)
        {
            cin >> a >> b;
            v.push_back({a, b});
        }
        sort(v.begin(), v.end());

        int tmp = 0;
        int answer = 1;
        for (int i = 1; i < n; i++)
        {
            if (v[i].second < v[tmp].second)
            {
                answer++;
                tmp = i;
            }
        }
        cout << answer << endl;
    }

    return 0;
}