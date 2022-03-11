#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void makebit(int num) 
{
    while (num != 0)
    {
        a.push_back(num % 2);
        num = num / 2;
    }
}

int main() {
    
    int n, k, count, i=0;

    cin >> n >> k;

    while (1)
    {
        int count = 0;
        a.clear();
        makebit(n+i);
        for (int i = 0; i < a.size(); i++)
        {
            if (a[i] == 1)
            {
                count++;
            }
        }
        if (count <= k)
        {
            break;
        }
        i++;
    }

    cout << i;
    return 0;
}