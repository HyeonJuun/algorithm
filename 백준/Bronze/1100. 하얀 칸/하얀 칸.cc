#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str;
    vector<string> str_v;
    for (int i = 0; i < 8; i++)
    {
        getline(cin, str);
        str_v.push_back(str);
    }
    int cnt = 0;
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            if ((i + j) % 2 == 0 && str_v[i][j] == 'F')
            {
                cnt++;
            }
        }
    }
    cout << cnt << endl;
    return 0;
}
