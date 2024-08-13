#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 100000 + 10
#define INF 987654321

int arr[MAX];
int x[MAX];
int y[MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, anim, len;
    cin >> n >> anim >> len;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort(arr, arr + n);
    for (int i = 0; i < anim; i++)
        cin >> x[i] >> y[i];

    int answer = 0;
    for (int k = 0; k < anim; k++)
    {
        int l = 0, r = n - 1, mid;
        while (l <= r)
        {
            mid = (l + r) / 2;
            int cal = abs(arr[mid] - x[k]) + y[k];

            if (cal <= len)
            {
                answer++;
                break;
            }
            else
            {
                if (x[k] >= arr[mid])
                {
                    l = mid + 1;
                }
                else
                    r = mid - 1;
            }
        }
    }
    cout << answer << endl;
    return 0;
}