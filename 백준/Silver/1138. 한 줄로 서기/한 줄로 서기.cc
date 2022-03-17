#include <iostream>

using namespace std;

int MAX = 10;

int N;

int line[10];

int main(void)
{
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int left;
        cin >> left;
        for (int j = 0; j < N; j++)
            if (left == 0 && line[j] == 0)
            {
                line[j] = i + 1;
                break;
            }
            else if (line[j] == 0)
                left--;
    }
    for (int i = 0; i < N; i++)
        cout << line[i] << " ";
    cout << "\n";
    return 0;
}