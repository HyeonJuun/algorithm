#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 2500 + 10
#define INF 987654321

int dice[10];
int piece[4];

int arr[34];
int score[34];
int turn[34];
bool check[34];

int answer = -1;

void solve(int cur, int sum)
{
    if (cur == 10)
    {
        answer = max(answer, sum);
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int prev = piece[i];
        int nxt = prev;
        int move = dice[cur];

        if (turn[nxt] > 0)
        {
            nxt = turn[nxt];
            move--;
        }

        while (move--)
        {
            nxt = arr[nxt];
        }
        if (nxt != 21 && check[nxt])
            continue;

        check[prev] = false;
        check[nxt] = true;
        piece[i] = nxt;

        solve(cur + 1, sum + score[nxt]);

        piece[i] = prev;
        check[prev] = true;
        check[nxt] = false;
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i < 21; i++)
        arr[i] = i + 1;
    arr[21] = 21;
    for (int i = 22; i < 27; i++)
        arr[i] = i + 1;
    arr[27] = 20;
    arr[28] = 29;
    arr[29] = 30;
    arr[30] = 25;
    arr[31] = 32;
    arr[32] = 25;

    turn[5] = 22;
    turn[10] = 31;
    turn[15] = 28;

    for (int i = 0; i < 21; i++)
        score[i] = 2 * i;

    score[22] = 13;
    score[23] = 16;
    score[24] = 19;
    score[25] = 25;
    score[26] = 30;
    score[27] = 35;
    score[28] = 28;
    score[29] = 27;
    score[30] = 26;
    score[31] = 22;
    score[32] = 24;

    for (int i = 0; i < 10; i++)
        cin >> dice[i];

    solve(0, 0);
    cout << answer << endl;
    return 0;
}