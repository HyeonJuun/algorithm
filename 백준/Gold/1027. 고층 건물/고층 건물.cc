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

int n, answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<int> building(n);
    vector<int> cnt(n);

    for (int i = 0; i < n; i++)
        cin >> building[i];

    for (int i = 0; i < n; i++)
    {
        double mx = -9999999999;
        for (int j = i + 1; j < n; j++)
        {
            double cur = (double)(building[j] - building[i]) / (j - i);

            if (cur > mx)
            {
                cnt[i]++;
                cnt[j]++;
                mx = cur;
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        answer = max(answer, cnt[i]);
    }
    cout << answer << '\n';
    return 0;
}