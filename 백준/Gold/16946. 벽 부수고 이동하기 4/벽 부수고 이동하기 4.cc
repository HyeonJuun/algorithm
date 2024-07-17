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

int n, m, num = 1, mp[MAX][MAX], number[MAX][MAX], answer[MAX][MAX];
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

vector<int> zero_size;

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    int cnt = 0;
    q.push({x, y});
    number[x][y] = num;
    cnt++;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && number[nx][ny] == 0 && mp[nx][ny] == 0)
            {
                q.push({nx, ny});
                number[nx][ny] = num;
                cnt++;
            }
        }
    }
    zero_size.push_back(cnt);
    num++;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < m; j++)
            mp[i][j] = str[j] - '0';
    }
    zero_size.push_back(0);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 0 && number[i][j] == 0)
                bfs(i, j);
        }
    }

    set<int> s;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mp[i][j] == 0)
                continue;
            answer[i][j] = 1;
            for (int k = 0; k < 4; k++)
            {
                int x = i + dx[k];
                int y = j + dy[k];
                if (x >= 0 && x < n && y >= 0 && y < m && number[x][y] != 0)
                    s.insert(number[x][y]);
            }
            for (auto a : s)
                answer[i][j] += zero_size[a];
            s.clear();
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << answer[i][j] % 10;
        cout << '\n';
    }
    return 0;
}