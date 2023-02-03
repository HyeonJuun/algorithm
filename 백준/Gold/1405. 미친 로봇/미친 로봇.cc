#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 30 + 1;

int n;
double per[4];

bool arr[MAX][MAX];

int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

double solve(int x, int y, int cnt)
{
    if (cnt == n)
        return 1.0;
    arr[x][y] = true;
    double res = 0.0;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (!arr[nx][ny])
        {
            res = res + per[i] * solve(nx, ny, cnt + 1);
        }
    }
    arr[x][y] = false;
    return res;
}
int main() {
    
    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        int a;
        cin >> a;
        per[i] = a / 100.0;
    }
    double R = solve(14, 14, 0);
    cout.precision(10);
    cout << fixed;
    cout << R;
    return 0;
}