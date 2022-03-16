#include <iostream>
#include <vector>
using namespace std;

int main(void){
    vector <int> a;
    int aa, result, sum=0;
    for(int i=0; i<5; i++)
    {
    	cin >> aa;
    	a.push_back(aa);
	}
	for(int i=0; i<5; i++)
	{
		sum += a[i] * a[i];
	}
	result = sum % 10;
	cout << result << endl;
	return 0;
}