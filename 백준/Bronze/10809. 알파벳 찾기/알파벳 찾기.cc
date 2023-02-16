#include <stdio.h>

int main() {
	char s[100];
	scanf("%s", &s);

	int a[26];
	for (int i = 0; i < 26; ++i) {
		a[i] = -1;
	}

	int k = 0;
	int i;

	while (s[k]) {
		i = s[k] - 97;
		if (a[i] == -1) a[i] = k;
		++k;
	}

	for (int i = 0; i < 26; ++i) {
		printf("%d ", a[i]);
	}

	return 0;
}