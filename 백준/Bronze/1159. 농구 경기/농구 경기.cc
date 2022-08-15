#include <vector>
#include <algorithm>
#include <string>
#include <iostream>

using namespace std;

int alpha[26] = { 0, };

int main() {
    int n;
    cin >> n;
    string a = "abcdefghijklmnopqrstuvwxyz";
    for (int i = 0; i < n; i++)
    {
        string str1;
        cin >> str1;
        alpha[str1[0] - 'a']++;
    }
    bool f = true;
    for (int i = 0; i < 26; i++)
    {
        if (alpha[i] >= 5)
        {
            cout << a[i];
            f = false;
        }
    }
    if (f)
        cout << "PREDAJA" << endl;
    return 0;
}
