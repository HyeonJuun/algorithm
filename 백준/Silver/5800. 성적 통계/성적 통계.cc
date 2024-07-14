#include <iostream>
#include <algorithm>
using namespace std;
int K, N, largestGap;
int grades[50];
int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> K;
    for (int i = 1; i <= K; ++i)
    {
        cin >> N;

        for (int j = 0; j < N; ++j)
        {
            cin >> grades[j];
        }

        sort(grades, grades + N);

        largestGap = 0;

        for (int j = 0; j < N - 1; ++j)
        {
            largestGap = max(largestGap, grades[j + 1] - grades[j]);
        }

        cout << "Class " << i << "\n";
        cout << "Max " << grades[N - 1] << ", Min " << grades[0] << ", Largest gap " << largestGap << "\n";
    }
    return 0;
}