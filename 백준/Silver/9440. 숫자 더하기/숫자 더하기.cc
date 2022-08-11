#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;


int main(void)
{
    int n, l;
    while (true)
    {
        int zero = 0;

        cin >> n;
        if (n == 0)
            break;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int a; cin >> a;
            if (a == 0) zero++;
            v.push_back(a);
        }
        sort(v.begin(), v.end());

        if (zero == 1)
            swap(v[0], v[2]);
        if (zero >= 2) 
        {
            swap(v[0], v[zero]);
            swap(v[1], v[zero + 1]);
        }
        string l = "", r = "";
        for (int i = 0; i < v.size(); i++)
        {
            string now = to_string(v[i]);
            if (i % 2 == 0) l += now;
            else r += now;
        }
        cout << stoi(l) + stoi(r) << endl;
    }

    return 0;
}