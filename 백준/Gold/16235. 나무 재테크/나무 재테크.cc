#include <iostream>
#include <cstring>
#include <cmath>
#include <vector>
#include <algorithm>
#include <queue>

#define MAX 10 + 1

using namespace std;
// 문제
// 부동산 투자로 억대의 돈을 번 상도는 최근 N×N 크기의 땅을 구매했다.
// 상도는 손쉬운 땅 관리를 위해 땅을 1×1 크기의 칸으로 나누어 놓았다.
// -> map은 n x n 크기
// 각각의 칸은 (r, c)로 나타내며, r은 가장 위에서부터 떨어진 칸의 개수, c는 가장 왼쪽으로부터 떨어진 칸의 개수이다. r과 c는 1부터 시작한다.
// 상도는 전자통신공학과 출신답게 땅의 양분을 조사하는 로봇 S2D2를 만들었다.
// S2D2는 1×1 크기의 칸에 들어있는 양분을 조사해 상도에게 전송하고, 모든 칸에 대해서 조사를 한다. 가장 처음에 양분은 모든 칸에 5만큼 들어있다.
// 상도는 나무 재테크로 더 큰 돈을 벌기 위해 M개의 나무를 구매해 땅에 심었다. 같은 1×1 크기의 칸에 여러 개의 나무가 심어져 있을 수도 있다.
// -> 나무는 m개 있음
// 이 나무는 사계절을 보내며, 아래와 같은 과정을 반복한다.
// 봄에는 나무가 자신의 나이만큼 양분을 먹고, 나이가 1 증가한다. 각각의 나무는 나무가 있는 1×1 크기의 칸에 있는 양분만 먹을 수 있다.
// 하나의 칸에 여러 개의 나무가 있다면, 나이가 어린 나무부터 양분을 먹는다.
// 만약, 땅에 양분이 부족해 자신의 나이만큼 양분을 먹을 수 없는 나무는 양분을 먹지 못하고 즉시 죽는다.
// -> 봄에는 양분 먹어야 한다, 어린 나무부터 각 칸에 있는 양분을 자기 나이만큼 먹는데 못먹으면 죽음
// 여름에는 봄에 죽은 나무가 양분으로 변하게 된다. 각각의 죽은 나무마다 나이를 2로 나눈 값이 나무가 있던 칸에 양분으로 추가된다. 소수점 아래는 버린다.
// -> 봄에 죽은 나무의 나이/2 만큼의 양분이 생김
// 가을에는 나무가 번식한다. 번식하는 나무는 나이가 5의 배수이어야 하며, 인접한 8개의 칸에 나이가 1인 나무가 생긴다.
// 어떤 칸 (r, c)와 인접한 칸은 (r-1, c-1), (r-1, c), (r-1, c+1), (r, c-1), (r, c+1), (r+1, c-1), (r+1, c), (r+1, c+1) 이다.
// -> 나이가 5의 배수인 나무가 번식해서 8칸에 나이가 1인 나무 생김
// 상도의 땅을 벗어나는 칸에는 나무가 생기지 않는다.
// 겨울에는 S2D2가 땅을 돌아다니면서 땅에 양분을 추가한다. 각 칸에 추가되는 양분의 양은 A[r][c]이고, 입력으로 주어진다.
// K년이 지난 후 상도의 땅에 살아있는 나무의 개수를 구하는 프로그램을 작성하시오.
// -> K년 지난 후 살아있는 나무 개수 구하면 되고, 겨울에는 양분을 추가한다
// -----------------------------------------------------------
// 입력
// 첫째 줄에 N, M, K가 주어진다.
// 둘째 줄부터 N개의 줄에 A배열의 값이 주어진다. r번째 줄의 c번째 값은 A[r][c]이다.
// 다음 M개의 줄에는 상도가 심은 나무의 정보를 나타내는 세 정수 x, y, z가 주어진다.
// 처음 두 개의 정수는 나무의 위치 (x, y)를 의미하고, 마지막 정수는 그 나무의 나이를 의미한다.
// -----------------------------------------------------------
// 출력
// 첫째 줄에 K년이 지난 후 살아남은 나무의 수를 출력한다.
// -----------------------------------------------------------
int n, m, k, answer;
vector<int> map[MAX][MAX];
int cost[MAX][MAX];
int plus_cost[MAX][MAX];
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {1, 0, -1, 1, -1, 1, 0, -1};
int x, y, z;

void spring_summer()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].size() == 0)
                continue;
            int die_cost = 0;
            vector<int> tmp;
            sort(map[i][j].begin(), map[i][j].end());
            for (int k = 0; k < map[i][j].size(); k++)
            {
                int age = map[i][j][k];

                if (age <= cost[i][j])
                {
                    cost[i][j] -= age;
                    tmp.push_back(age + 1);
                }
                else
                {
                    die_cost += age / 2;
                }
            }
            map[i][j].clear();
            for (int k = 0; k < tmp.size(); k++)
            {
                map[i][j].push_back(tmp[k]);
            }
            cost[i][j] += die_cost;
        }
    }
}
void fall()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (map[i][j].size() == 0)
                continue;

            for (int k = 0; k < map[i][j].size(); k++)
            {
                if (map[i][j][k] % 5 == 0)
                {
                    for (int l = 0; l < 8; l++)
                    {
                        int nx = i + dx[l];
                        int ny = j + dy[l];

                        if (nx >= 1 && ny >= 1 && nx <= n && ny <= n)
                        {
                            map[nx][ny].push_back(1);
                        }
                    }
                }
            }
        }
    }
}
void winter()
{
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cost[i][j] += plus_cost[i][j];
        }
    }
}
int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> plus_cost[i][j];
            cost[i][j] = 5;
        }
    }
    for (int i = 0; i < m; i++)
    {
        cin >> x >> y >> z;
        map[x][y].push_back(z);
    }

    for (int i = 0; i < k; i++)
    {
        spring_summer();
        fall();
        winter();
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            answer += map[i][j].size();
        }
    }
    cout << answer << endl;
    return 0;
}