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
int prefix[MAX];
int answer;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
        prefix[i] = prefix[i - 1] + arr[i];
    }

    for (int i = 2; i < n; i++)
    {
        int cur = (prefix[i] - prefix[i - 1]) + (prefix[n - 1] - prefix[i - 1]);
        answer = max(answer, cur);
    }
    for (int i = 2; i < n; i++)
    {
        int cur = (prefix[n] - prefix[1] - arr[i]) + prefix[n] - prefix[i];
        answer = max(answer, cur);
    }
    for (int i = 2; i < n; i++)
    {
        int cur = prefix[n - 1] - arr[i] + prefix[i - 1];
        answer = max(answer, cur);
    }
    cout << answer << endl;
    return 0;
}