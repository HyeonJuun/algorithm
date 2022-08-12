#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    string str;

    getline(cin, str);
    int cnt = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == 'U' && cnt == 0) 
        {
            cnt = 1;
        }
        else if (str[i] == 'C' && cnt == 1)
        {
            cnt = 2;
        }
        else if (str[i] == 'C' && cnt == 3)
        {
            cnt = 4;
            break;
        }
        else if(str[i] == 'P' && cnt == 2)
        {
            cnt = 3;
        }
    }
    if (cnt == 4)
    {
        cout << "I love UCPC" << endl;
    }
    else
    {
        cout << "I hate UCPC" << endl;

    }
    return 0;
}
