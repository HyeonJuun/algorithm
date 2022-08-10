#include<iostream>
#include<queue>

using namespace std;

priority_queue<int, vector<int>, greater<int> > pq;

int main(void)
{
    int n;
    int sum = 0;

    cin >> n;
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        pq.push(x);
    }

    while (pq.size() > 1) {
        int a, b;

        a = pq.top(), pq.pop();
        b = pq.top(), pq.pop();
        sum += (a + b);
        pq.push(a + b);
    }

    cout << sum << endl;
    return 0;
}