#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;

#define MAX 10000 + 10

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    set<int> s;
    int answer = 0;
    for (int i = 0; i < 10; i++)
    {
        int x;
        cin >> x;
        x %= 42;
        if (s.find(x) == s.end())
            answer++;
        s.insert(x);
    }

    cout << answer << endl;
    return 0;
}