#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
#include <map>

using namespace std;


int main() {
    int n;
    cin >> n;
    map<string, int> book;
    string str;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        book[str]++;
    }
    int max = 0;
    string res;
    for (auto& i : book)
        if (i.second > max)
            res = i.first, max = i.second;

    cout << res;
    return 0;
}
