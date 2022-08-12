#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main(void)
{
    int n, a, b, c;
    cin >> n;
    cin >> a >> b;
    cin >> c;
    vector<int> t;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        t.push_back(x);
    }
    sort(t.begin(), t.end(), greater<>());
    int bestCal =  c / a; 

    int totalPrice = a; //총 가격
    int totalCal = c; //총 열량
    
    for (int i = 0; i < n; i++) {
        totalPrice += b;
        totalCal += t[i];
        if (bestCal < totalCal / totalPrice) {
            bestCal = totalCal / totalPrice;
        }
    }

    cout << bestCal;
    return 0;
}