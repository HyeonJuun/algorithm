#include <iostream>

#include <cstring>

using namespace std;



const int DEPTHMAX = 63 * 2 + 1; //63에서 63초 뒤까지

const int MAX = 63 + 1;

int k, n;

long long cache[DEPTHMAX][MAX];

long long isAlive(int depth, int seconds)

{
    if (!depth) //수심 도달하면 잡아먹힌다
        return 0;
    else if (!seconds) //시간 다 지나도 잡아먹히지 않아서 생존
        return 1;
    long long& result = cache[depth][seconds];
    if (result != -1)
        return result;
    //아래로 한칸, 혹은 위로 한칸
    result = isAlive(depth + 1, seconds - 1) + isAlive(depth - 1, seconds - 1);
    return result;
}



int main(void)

{
    cin >> k >> n;
    memset(cache, -1, sizeof(cache));
    cout << isAlive(k, n) << endl;
    return 0;

}