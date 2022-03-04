#include <cstdio>
#include <iostream>
#include <cmath>

using namespace std;


int N;
int i, j;

int result;


// x, y는 섹션 시작 좌표, n은 한 변의 길이
void divide(int x, int y, int n) {
    
    if(x == i && y == j) {
        printf("%d", result);
        exit(0); // 찾았으므로 끝
    }
    
    // 현재 영역에서 해당 좌표를 포함하고 있다면
    if(i <= x + n - 1 && j <= y + n - 1)
        ;// 아무작업도 안함.
    else {
        //현재 들어온 영역은 해당되지 않는다는 것이므로, 해당 영역의 자리크기만큼 스킵하기 위해 연산.
        result += n * n;
        return;
    }
    
    divide(x, y, n / 2); // SECTION A
    divide(x, y + n / 2, n / 2); // SECTION B
    divide(x + n / 2, y, n / 2); // SECTION C
    divide(x + n / 2, y + n / 2, n / 2); // SECTION D
    
}

int main() {
    
    scanf("%d", &N);
    scanf("%d %d", &i, &j);
    
    divide(0, 0, pow(2, N));
}