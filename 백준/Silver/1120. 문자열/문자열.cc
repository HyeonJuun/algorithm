#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int main() {
    string str1, str2;
    cin >> str1 >> str2;
    int m = 50;
    for (int i = 0; i <= str2.length() - str1.length(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < str1.length(); j++)
        {
            if (str1[j] != str2[i + j])
                cnt++;
        }
        m = min(m, cnt);
    }
    cout << m << endl;
    return 0;
}
