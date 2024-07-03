#include <bits/stdc++.h>

using namespace std;

struct Edge {
	int v1, v2, flag;
};

const int MAX = 1001;
int n, m, parent[MAX];
vector<Edge> edges;

bool compare1(const Edge& a, const Edge& b) {
	return a.flag < b.flag;
}

bool compare2(const Edge& a, const Edge& b) {
	return a.flag > b.flag;
}


void init(void) {
	for (int i = 0; i < MAX; i++) parent[i] = i;
}

int Find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = Find(parent[a]);
}

void Union(int a, int b) {
	int pa = Find(a), pb = Find(b);
	parent[pa] = pb;
}

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edges.push_back({a, b, c});
	}

	init();

	sort(edges.begin(), edges.end(), compare1);

	int ans1 = 0, ans2 = 0;
	for (auto& edge : edges) {
		if (Find(edge.v1) != Find(edge.v2)) {
			Union(edge.v1, edge.v2);

			if (!edge.flag)
				ans1++;
		}
	}

	init();

	sort(edges.begin(), edges.end(), compare2);

	for (auto& edge : edges) {
		if (Find(edge.v1) != Find(edge.v2)) {
			Union(edge.v1, edge.v2);

			if (!edge.flag)
				ans2++;
		}
	}

	cout << (int)(pow(ans1, 2) - pow(ans2, 2)) << '\n';
	return 0;
}