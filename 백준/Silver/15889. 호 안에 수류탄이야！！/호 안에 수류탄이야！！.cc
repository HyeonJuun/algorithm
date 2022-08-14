#include <stdio.h>
int r[30001];
int ds[1000001];
int main() {
    int n, i, j, d, cnt = 0, sum = 0;
    scanf("%d", &n);
    for (i = 0; i < n; i++) 
        scanf("%d", &r[i]);
    if (n != 1) {
        for (i = 0; i < n - 1; i++) {
            scanf("%d", &d);
            if (ds[r[i]] < d) ds[r[i]] = d;
        }
        for (i = 0; i < n - 1; i++) {
            if (r[i] == r[i + 1]) continue;
            for (j = 0; j <= i; j++) {
                if (r[j] == r[j + 1]) continue;
                if (r[j] + ds[r[j]] >= r[i + 1]) { cnt = 1; break; }
            }
            if (!cnt) { printf("엄마 나 전역 늦어질 것 같아"); return 0; }
            cnt = 0;
        }
    }
    printf("권병장님, 중대장님이 찾으십니다");
    return 0;
}
