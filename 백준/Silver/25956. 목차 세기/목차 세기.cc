#include <cstdio>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;
stack<int> s;
vector<int> v;
int curSub[1000010];
int N;
int main()
{
	scanf("%d", &N);
	int a;
	for (int i = 0; i < N; ++i) {
		scanf("%d", &a);
		s.push(a);
	}
	int cur = s.top();
	int nxt;
	s.pop();
	v.push_back(0);
	while (!s.empty()) {
		nxt = s.top();
		s.pop();

		if (cur > nxt) {
			if (cur - nxt > 1) {
				puts("-1");
				goto END;
			} else if (cur - nxt == 1) {
				v.push_back(++curSub[cur]);
				curSub[cur] = 0;
			}
		} else if (cur == nxt) {
			v.push_back(0);
			if (cur != 1) {
				++curSub[cur];
			}
		} else if (cur < nxt) {
			v.push_back(0);
			if (cur != 1)
				++curSub[cur];
		}
		cur = nxt;
	}
	if (cur != 1) {
		puts("-1");
		goto END;
	}
	for (int i = 2; i < N; ++i) {
		if (curSub[i] != 0) {
			puts("-1");
			goto END;
		}
	}
	for (int i = N - 1; i >= 0; --i) {
		printf("%d\n", v[i]);
	}

END:
	return 0;
}