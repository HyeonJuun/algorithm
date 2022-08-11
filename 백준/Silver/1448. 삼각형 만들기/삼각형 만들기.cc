#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int main(void)
{
    int n;
    vector<int> x;
    vector<int> triangle;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x.push_back(a);
    }
    sort(x.begin(), x.end());
    for (int i = 0; i <= x.size() - 3; i++)
    {
        if (x[i] + x[i + 1] > x[i + 2])
        {
            triangle.push_back(x[i] + x[i + 1] + x[i + 2]);
        }
        else
            continue;
    }
    if (triangle.size() == 0)
    {
        cout << "-1" << endl;
        return 0;
    }
    sort(triangle.begin(), triangle.end());
    
    cout << triangle[triangle.size() - 1] << endl;
    return 0;
}