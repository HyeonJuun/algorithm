// 16960. 스위치와 램프
#include <iostream>
#include <vector>
 
using namespace std;
 
int n, m;
vector<vector<int>> vec;
int lamp[2010];
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
 
    cin >> n >> m;
    vec.push_back(vector<int>(0));
 
    int a, b;
    for (int i = 1; i < n + 1; i++)
    {
        cin >> a;
        vector<int> temp;
        for (int j = 0; j < a; j++)
        {
            cin >> b;
            lamp[b]++;
            temp.push_back(b);
        }
        vec.push_back(temp);
    }
 
    for (int i = 1; i < n + 1; i++)
    {
        bool flag = 1;
        for (int j = 0; j < vec[i].size(); j++)
        {
            if (lamp[vec[i][j]] - 1 <= 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            cout << 1;
            return 0;
        }
    }
 
    cout << 0;
    return 0;
}