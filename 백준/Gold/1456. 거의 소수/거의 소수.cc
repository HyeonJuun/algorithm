#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <string>

using namespace std;

#define MAX 10000000 + 1

long long a, b, answer;
bool isPrime[MAX];

void solve()
{
    for (int i = 2; i < MAX; i++)
    {
        isPrime[i] = true;
    }
    for (int i = 2; i * i <= MAX; i++)
    {
        if (isPrime[i])
        {
            for (int j = i * i; j < MAX; j += i)
            {
                isPrime[j] = false;
            }
        }
    }

    for (int i = 2; i <= MAX; i++)
    {
        if (isPrime[i])
        {
            long long num = i;
            while (num <= b / i)
            {
                if (num * i >= a)
                {
                    answer++;
                }
                num *= i;
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> a >> b;
    solve();
    cout << answer << endl;
}
