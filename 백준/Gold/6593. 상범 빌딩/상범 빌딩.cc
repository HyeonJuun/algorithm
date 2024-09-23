#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

const int MAX = 31;

int l, r, c;
int sl, sr, sc;
int el, er, ec;

char map[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];

int dl[] = {0, 0, 0, 0, 1, -1};
int dr[] = {1, -1, 0, 0, 0, 0};
int dc[] = {0, 0, -1, 1, 0, 0};
int main(void) {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
   
    while (true)
    {
        int answer = 0;
        cin >> l >> r >> c;
        if (l == 0 && r == 0 && c == 0)
            break;

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                for (int k = 0; k < c; k++)
                {
                    map[i][j][k] = ' ';
                    visited[i][j][k] = false;
                }
            }
        }

        for (int i = 0; i < l; i++)
        {
            for (int j = 0; j < r; j++)
            {
                string s;
                cin >> s;
                for (int k = 0; k < c; k++)
                {
                    map[i][j][k] = s[k];
                    if (map[i][j][k] == 'S')
                    {
                        sl = i, sr = j, sc = k;
                    }
                    
                    if (map[i][j][k] == 'E')
                    {
                        el = i, er = j, ec = k;
                    }
                }
            }
        }
        queue<pair<pair<int, int>, pair<int,  int>>> q;

        q.push({ {sl, sr}, {sc, 0}});
        visited[sl][sr][sc] = true;
        int cnt = 0;
        while (!q.empty())
        {
            int cur_l = q.front().first.first;
            int cur_r = q.front().first.second;
            int cur_c = q.front().second.first;
            int cnt = q.front().second.second;
            q.pop();

            if (cur_l == el && cur_r == er && cur_c == ec)
            {
                answer = cnt;
                break;
            }
            for (int i = 0; i < 6; i++)
            {
                int nl = cur_l + dl[i];
                int nr = cur_r + dr[i];
                int nc = cur_c + dc[i];

                if (nl < 0 || nr < 0 || nc < 0 || nl >= l || nr >= r || nc >= c || map[nl][nr][nc] == '#')
                    continue;

                if (!visited[nl][nr][nc])
                {
                    visited[nl][nr][nc] = true;
                    q.push({ {nl, nr}, {nc, cnt + 1} });
                }
            }
        }
        if (answer != 0)
            cout << "Escaped in " << answer << " minute(s)." << endl;
        else
            cout << "Trapped!" << endl;
    }
    return 0;
}
