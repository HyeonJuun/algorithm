#include <iostream>
using namespace std;

#define RED 1
#define BLUE 2

int main()
{
    int len, red = 0, blue = 0;
    int state = 0;
    char input;

    cin >> len;

    for (int i = 0; i < len; i++)
    {
        cin >> input;

        if (input == 'R')
        {
            if (state != RED)
                red++;
            state = RED;
        }
        else
        {
            if (state != BLUE)
                blue++;
            state = BLUE;
        }
    }

    if (red >= blue)
        cout << 1 + blue;
    else
        cout << 1 + red;
}