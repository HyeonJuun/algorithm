#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string n;
    while(true)
    {
        bool f = true;
        cin >> n;
        if (stoi(n) == 0)
            break;
        for (int i = 0; i < n.length(); i++)
        {
            if (n[i] != n[n.length() - i - 1])
            {
                f = false;
                break;
            }
        }
        if (f)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
    return 0;
}