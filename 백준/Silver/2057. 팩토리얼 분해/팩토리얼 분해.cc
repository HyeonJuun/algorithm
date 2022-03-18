#include<cstdio>
long long n, t = 2432902008176640000LL;
int main() {
    scanf("%lld", &n);
    if (!n) n = -1;
    for (int i = 20; i; i--) {
        t /= i;
        if (n >= t) n -= t;
    }
    puts(n ? "NO" : "YES");
    return 0;
}