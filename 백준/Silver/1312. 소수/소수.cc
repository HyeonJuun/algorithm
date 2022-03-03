#include <iostream>

using namespace std;

int main(){
    int x, y, n;
    int res =0;
    
    cin >> x >> y >> n;
    if(x%y == 0)
    {
        cout << 0;
        return 0;
    }
    if(x>y)    x = x%y;
    for(int i=0; i<n; i++)
    {
        x *=10;
        res = (int)(x/y);
        x = x % y;
    }
    cout << res;
}