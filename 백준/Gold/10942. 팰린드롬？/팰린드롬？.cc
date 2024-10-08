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

#define MAX 2000 + 10
#define INF 2100000000

int n, m;
int arr[MAX];
int answer[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> arr[i];
    }
    cin >> m;

    for (int i = 1; i <= n; i++)
    {
        answer[i][i] = 1;
        if (i != 1 && arr[i - 1] == arr[i])
            answer[i - 1][i] = 1;
    }
    for (int i = 2; i <= n - 1; i++)
    {
        for (int j = 1; i + j <= n; j++)
        {
            if (arr[j] == arr[i + j] && answer[j + 1][i + j - 1] == 1)
                answer[j][i + j] = 1;
        }
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        cout << answer[a][b] << '\n';
    }
    return 0;
}