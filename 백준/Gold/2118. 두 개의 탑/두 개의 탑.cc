#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 50000 + 1

using namespace std;

int n, total;
int arr[MAX];

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        total += arr[i];
    }
    int l = 0, r = 1;
    int lsum = arr[0], rsum = total - arr[0];
    int answer = 0;

    while (l < n)
    {
        answer = max(answer, min(lsum, rsum));

        if (lsum >= rsum)
        {
            lsum -= arr[l];
            rsum += arr[l];
            l++;
            continue;
        }
        lsum += arr[r];
        rsum -= arr[r];
        r++;
        r %= n;
    }
    cout << answer;
    return 0;
}