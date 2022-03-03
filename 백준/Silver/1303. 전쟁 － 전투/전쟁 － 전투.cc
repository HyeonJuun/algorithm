#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

char map[101][101] = { 0, };
int visited[101][101] = {0,};
void checkMap(char a, int x, int y, int n, int m, int &c)
{
    if (a != map[x][y])  return;
    if (x < 0 || x >= n || y < 0 || y>= m) return;
    if (visited[x][y] == 1)  return;

    c++;
    visited[x][y] = 1;
    checkMap(a, x+1, y, n, m, c);
    checkMap(a, x-1, y, n, m, c);
    checkMap(a, x, y+1, n, m, c);
    checkMap(a, x, y-1, n, m, c);

}

int main() {
    int n, m;
    cin >> n >> m;


    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        for (int j = 0; j < n; j++)
        {
            map[j][i] = str[j];
        }
    }
    int total_w = 0, total_b =0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int w = 0, b =0;
            checkMap('W', i, j, n, m, w);
            checkMap('B', i, j, n, m, b);
            total_w += w * w;
            total_b += b * b;
        }
    }
    cout << total_w << " " << total_b << endl;
    return 0;
}