#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

int n;
int arr[20][20];
bool fin;
bool check(int x, int y)
{
    bool visited[10] = { 0 };
    for (int i = 0; i < 9; i++)
    {
        if (arr[x][i] != 0 && visited[arr[x][i]])
            return false;
        visited[arr[x][i]] = true;
    }
    memset(visited, false, sizeof(visited));
    for (int i = 0; i < 9; i++)
    {
        if (arr[i][y] != 0 && visited[arr[i][y]])
            return false;
        visited[arr[i][y]] = true;
    }
    memset(visited, false, sizeof(visited));
    for (int i = (x / 3) * 3; i < (x / 3) * 3 + 3; i++)
    {
        for (int j = (y / 3) * 3; j < (y / 3) * 3 + 3; j++)
        {
            if (arr[i][j] != 0 && visited[arr[i][j]])
                return false;
            visited[arr[i][j]] = true;
        }
    }
    return true;
}
void solve(int x, int y)
{
    if (fin)
        return;
    if (y == 9)
    {
        x++;
        y = 0;
    }
    if (x == 9)
    {
        fin = true;
        for (int i = 0; i < 9; i++)
        {
            for (int j = 0; j < 9; j++)
            {
                cout << arr[i][j] << " ";
            }
            cout << '\n';
        }
        return;
    }
    if (arr[x][y] != 0)
    {
        solve(x, y + 1);
    }
    else
    {
        for (int i = 1; i <= 9; i++)
        {
            arr[x][y] = i;
            if (check(x, y))
                solve(x, y + 1);
        }
        arr[x][y] = 0;
    }
}
int main() {

    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    bool flag = true;
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (!check(i, j))
                flag = false;
            
        }
    }
    if (flag == false)
    {
        cout << -1;
    }
    else
    {
        solve(0, 0);
    }
    return 0;
}