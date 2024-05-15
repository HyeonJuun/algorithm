#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int n;
double result = 0;
vector<pair<double, double>> A;
int root[100];
vector<pair<double, pair<double, double>>> v;

int findRoot(int a) {
    if (root[a] == a) return a;
    else return root[a] = findRoot(root[a]);
}

void unionRoot(int a, int b) {
    a = findRoot(a);
    b = findRoot(b);

    if (a != b) root[b] = a;
}

double dist(double x1, double y1, double x2, double y2) {
    return sqrt(pow((x1 - x2), 2) + pow((y1 - y2), 2));
}

void solution() {
    for (int i = 0; i < n; i++) {
        root[i] = i;
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            v.push_back({ dist(A[i].first,A[i].second,A[j].first,A[j].second),{i,j} });
        }
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < v.size(); i++) {
        double cost = v[i].first;
        int a = v[i].second.first;
        int b = v[i].second.second;

        if (findRoot(a) != findRoot(b)) {
            unionRoot(a, b);
            result += cost;
        }
    }

    cout << fixed;
    cout.precision(2);
    cout << result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    double a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        A.push_back({ a,b });
    }

    solution();

    return 0;
}