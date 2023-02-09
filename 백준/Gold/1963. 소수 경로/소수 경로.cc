#include <iostream>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int t;
int num1, num2;
int is_prime[10000];
bool visited[10000];
queue<pair<int, int>> q;

void setPrime()
{
    for (int i = 2; i < 10000; i++)
        is_prime[i] = 1;
    for (int i = 2; i * i < 10000; i++)
    {
        if (is_prime[i] == 0)
            continue;
        for (int j = i * i; j < 10000; j += i)
        {
            is_prime[j] = 0;
        }
    }
}
int bfs(int n1, int n2)
{
    int res = 0;
    q.push({ n1, res });
    visited[n1] = true;
    while (!q.empty())
    {
        int x = q.front().first;
        res = q.front().second;
        q.pop();
        if (x == n2)
            return res;

        string str = to_string(x);
        // 각 자리수 바꾸자
        for (int i = 0; i < 4; i++)
        {
            // 0~9 까지의 숫자로 바꿀꺼다.
            char c = str[i];
            for (int j = '0'; j <= '9'; j++)
            {
                if (c == j)
                    continue;

                str[i] = j;
                int nx = stoi(str);
                if (!visited[nx] && nx > 1000 && is_prime[nx] && nx < 10000)
                {
                    q.push({ nx, res + 1 });
                    visited[nx] = true;
                }
            }
            str[i] = c;
        }
    }
    return -1;
}
void reset()
{
    memset(visited, false, sizeof(visited));
    while (!q.empty())
        q.pop();
}
int main() {

    setPrime();
    cin >> t;
    while (t--)
    {
        cin >> num1 >> num2;
        int ans = bfs(num1, num2);
        if (ans == -1)
            cout << "Impossible" << "\n";
        else
            cout << ans << '\n';
        reset();
    }
    return 0;
}