#include <iostream>
#include <cstring>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

#define fast ios_base::sync_with_stdio(false); cin.tie(0), cout.tie(0)
#define ll long long

ll dp[101][101];
int road[101][101][2];
int dy[2]={1,0},dx[2]={0,1};
int N, M, K;

ll sol(int y,int x){
    if(y == N && x == M) return 1;
    ll& ret = dp[y][x];
    if (ret != -1) return ret;
    ret = 0;
    for (int i = 0; i < 2; i++){
        if (!road[y][x][i]){
            int ny = y + dy[i], nx = x + dx[i];
            if (ny <= N && nx <= M) ret += sol(ny, nx);
        }
    }
    return ret;
}

int main() {
    fast;
    cin >> N >> M >> K;
    int cnt = 1;
    while (K--) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        if (a > c) swap(a, c);
        else if (b > d) swap(b, d);
        if (a < c) road[a][b][0] = 1;
        else if (b < d) road[a][b][1] = 1;
    }
    memset(dp, -1, sizeof(dp));
    cout << sol(0, 0);
    return 0;
}
