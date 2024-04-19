#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 101;

// 문제
// 낚시왕이 상어 낚시를 하는 곳은 크기가 R×C인 격자판으로 나타낼 수 있다. 격자판의 각 칸은 (r, c)로 나타낼 수 있다.
// r은 행, c는 열이고, (R, C)는 아래 그림에서 가장 오른쪽 아래에 있는 칸이다.
// 칸에는 상어가 최대 한 마리 들어있을 수 있다. 상어는 크기와 속도를 가지고 있다.
// 낚시왕은 처음에 1번 열의 한 칸 왼쪽에 있다. 다음은 1초 동안 일어나는 일이며, 아래 적힌 순서대로 일어난다. 낚시왕은 가장 오른쪽 열의 오른쪽 칸에 이동하면 이동을 멈춘다.
// 낚시왕이 오른쪽으로 한 칸 이동한다.
// 낚시왕이 있는 열에 있는 상어 중에서 땅과 제일 가까운 상어를 잡는다. 상어를 잡으면 격자판에서 잡은 상어가 사라진다.
// 상어가 이동한다.
// 상어는 입력으로 주어진 속도로 이동하고, 속도의 단위는 칸/초이다. 상어가 이동하려고 하는 칸이 격자판의 경계를 넘는 경우에는 방향을 반대로 바꿔서 속력을 유지한채로 이동한다.
// 왼쪽 그림의 상태에서 1초가 지나면 오른쪽 상태가 된다. 상어가 보고 있는 방향이 속도의 방향, 왼쪽 아래에 적힌 정수는 속력이다. 왼쪽 위에 상어를 구분하기 위해 문자를 적었다.
// 상어가 이동을 마친 후에 한 칸에 상어가 두 마리 이상 있을 수 있다. 이때는 크기가 가장 큰 상어가 나머지 상어를 모두 잡아먹는다.
// 낚시왕이 상어 낚시를 하는 격자판의 상태가 주어졌을 때, 낚시왕이 잡은 상어 크기의 합을 구해보자.
// -----------------------------------------------------------------------------------
// 입력
// 첫째 줄에 격자판의 크기 R, C와 상어의 수 M이 주어진다. (2 ≤ R, C ≤ 100, 0 ≤ M ≤ R×C)
// 둘째 줄부터 M개의 줄에 상어의 정보가 주어진다. 상어의 정보는 다섯 정수 r, c, s, d, z (1 ≤ r ≤ R, 1 ≤ c ≤ C, 0 ≤ s ≤ 1000, 1 ≤ d ≤ 4, 1 ≤ z ≤ 10000) 로 이루어져 있다.
// (r, c)는 상어의 위치, s는 속력, d는 이동 방향, z는 크기이다. d가 1인 경우는 위, 2인 경우는 아래, 3인 경우는 오른쪽, 4인 경우는 왼쪽을 의미한다.
// 두 상어가 같은 크기를 갖는 경우는 없고, 하나의 칸에 둘 이상의 상어가 있는 경우는 없다.
// -----------------------------------------------------------------------------------
// 출력
// 낚시왕이 잡은 상어 크기의 합을 출력한다.
// -----------------------------------------------------------------------------------
// 2차원 맵에 상어가 존재
// 각 상어들은 (방향/속도/크기) 를 가지고 있음
// 매 초 사람이 상어를 잡고 나머지 상어들은 움직임
// 상어 방향은 1 -> 2 -> 1 or 3 -> 4 -> 3
// 또한, 상어는 겁나 많이 움직여도 (R -1) * 2 의 단위로 같은 위치에 있음 -> 실제로 매 초 움직이는 정도는 Speed % ((R-1) * 2) 만큼 움직인다.
// 1. 상어를 나타내는 구조체 생성 (r, c, s, d, z) 후 map에 위치하게 하기
// 2. 이때 map에는 몇번 상어가 있는지만 확인할 수 있음
// 3. 매 순간, 사람이 움직이고 낚시
// 4. 낚시 후 상어 한마리씩 움직이기
// 5. 만약 상어가 움직인 자리에 다른 상어가 미리 존재한다면 크기를 비교하고 먹어버려

struct Shark
{
    int r, c, s, d, z;
    bool isLive = true;
};

int dirR[5] = {0, -1, 1, 0, 0};
int dirC[5] = {0, 0, 0, 1, -1};

int R, C, m;
int r, c, s, d, z;
int answer;

int map[MAX][MAX];
vector<Shark> shark;

void fishing(int cur)
{

    for (int i = 1; i <= R; i++)
    {

        if (map[i][cur] >= 1)
        {
            for (int j = 1; j <= m; j++)
            {
                if (shark[j].r == i && shark[j].c == cur && shark[j].isLive)
                {
                    // cout << shark[j].z << endl;
                    answer += shark[j].z;
                    shark[j].isLive = false;
                    return;
                }
            }
        }
    }
}

void shark_moving()
{
    for (int i = 1; i <= m; i++)
    {
        if (!shark[i].isLive)
        {
            continue;
        }
        map[shark[i].r][shark[i].c]--;

        for (int j = 0; j < shark[i].s; j++)
        {
            // 위
            if (shark[i].d == 1)
            {
                shark[i].r--;
                if (shark[i].r <= 0)
                {
                    shark[i].r = 2;
                    shark[i].d = 2;
                }
            }
            // 아래
            else if (shark[i].d == 2)
            {
                shark[i].r++;
                if (shark[i].r > R)
                {
                    shark[i].r = R - 1;
                    shark[i].d = 1;
                }
            }
            // 오
            else if (shark[i].d == 3)
            {
                shark[i].c++;
                if (shark[i].c > C)
                {
                    shark[i].c = C - 1;
                    shark[i].d = 4;
                }
            }
            // 왼
            else
            {
                shark[i].c--;
                if (shark[i].c <= 0)
                {
                    shark[i].c = 2;
                    shark[i].d = 3;
                }
            }
        }
        map[shark[i].r][shark[i].c]++;
    }
}

void shark_eating()
{
    for (int r = 1; r <= R; r++)
    {
        for (int c = 1; c <= C; c++)
        {
            if (map[r][c] >= 2)
            {
                vector<int> s_info;
                int mx = -1, mx_idx = 0;
                for (int i = 1; i <= m; i++)
                {
                    if (shark[i].r == r && shark[i].c == c && shark[i].isLive)
                    {
                        s_info.push_back(i);
                        if (shark[i].z >= mx)
                        {
                            mx = shark[i].z;
                            mx_idx = i;
                        }
                    }
                }

                for (int i = 0; i < s_info.size(); i++)
                {
                    if (s_info[i] == mx_idx)
                    {
                        continue;
                    }
                    else
                    {
                        mx += shark[s_info[i]].z;
                        shark[s_info[i]].isLive = false;
                        map[r][c]--;
                    }
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);

    cin >> R >> C >> m;
    shark.resize(m + 1);

    for (int i = 1; i <= m; i++)
    {
        cin >> shark[i].r >> shark[i].c >> shark[i].s >> shark[i].d >> shark[i].z;
        map[shark[i].r][shark[i].c]++;
        if (shark[i].d == 1 || shark[i].d == 2)
        {
            shark[i].s %= (R - 1) * 2;
        }
        if (shark[i].d == 3 || shark[i].d == 4)
        {
            shark[i].s %= (C - 1) * 2;
        }
    }

    for (int cur = 1; cur <= C; cur++)
    {
        fishing(cur);
        shark_moving();
        shark_eating();
    }
    cout << answer << endl;
    return 0;
}