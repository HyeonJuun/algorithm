#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;


int n, m;

void hanoi(int num, int start, int mid, int end)
{
    if (num == 1)
        cout << start << " " << end << "\n";
    else
    {
        hanoi(num - 1, start, end, mid);
        cout << start << " " << end << "\n";
        hanoi(num - 1, mid, start, end);
    }
}
int main(void) 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> n;
    cout << (int)pow(2, n) - 1 << "\n";
    hanoi(n, 1, 2, 3);
    return 0;
}