#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n,x;
    vector<int> a;
    vector<int> b;
    int sum=0;
    cin >> n;
    for(int i=0; i<n;i++)
    {
        cin >> x;
        a.push_back(x);
    }
    for(int i=0; i<n;i++)
    {
        cin >> x;
        b.push_back(x);
    } 
    sort(a.begin(), a.end());
    sort(b.begin(), b.end(), greater<>());
    for(int i=0; i<n; i++)
    {
        sum +=a[i]*b[i];
    }
    cout << sum << endl;
    return 0;
}