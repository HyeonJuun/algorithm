#include <iostream>
#include <vector>
#include<algorithm>
#include <cstring>

using namespace std;

int main() {
    string l, r;
    int i = 0, cnt=0;
    cin >> l >> r;
    while (1) 
    {
        if (l.length() != r.length())
            break;
        if (l[i] ==  r[i] && l[i] == '8')
        {
            cnt++;
        }
        else if(l[i] == r[i])
        {
            i++;
            continue;
        }
        else
        {
            break;
        }
        if (l.length() == i + 1)
            break;
        i++;
    }
    cout << cnt << endl;
    return 0;
}