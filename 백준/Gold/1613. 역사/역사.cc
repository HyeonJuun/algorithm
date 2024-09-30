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

int n, m, s;
int answer[MAX][MAX];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        answer[a][b] = -1;
        answer[b][a] = 1;
    }
    cin >> s;
    vector<pair<int, int>> question;
    for (int i = 0; i < s; i++)
    {
        int a, b;
        cin >> a >> b;
        question.push_back({a, b});
    }
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (answer[i][j] == 0)
                {
                    if (answer[i][k] == -1 && answer[k][j] == -1)
                    {
                        answer[i][j] = -1;
                    }
                    if (answer[i][k] == 1 && answer[k][j] == 1)
                    {
                        answer[i][j] = 1;
                    }
                }
            }
        }
    }
    for (int i = 0; i < question.size(); i++)
    {
        cout << answer[question[i].first][question[i].second] << '\n';
    }
    return 0;
}