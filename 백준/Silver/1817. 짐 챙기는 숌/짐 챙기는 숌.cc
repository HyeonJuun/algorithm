#include <cstdio>
int main(void) {
	int N, M, book, weight = 0, ans = 0;

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		scanf("%d", &book);
		if (weight + book > M) {
			weight = book;
			ans++;
		}
		else
			weight += book;
	}
	if (weight)
		ans++;
	printf("%d", ans);
}