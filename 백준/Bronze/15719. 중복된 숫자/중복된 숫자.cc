#include <iostream>
#include <vector>
using namespace std;

int main(){
	long long int n, a;
	cin >> n;
	long long int sum1=0 , sum2=0 , result=0 ;
	
	for(int i=0; i<n; i++)
	{
		scanf("%d", &a);
		sum1 += i;
		sum2 += a;
	}
	result = sum2 - sum1;
	cout << result << endl;
    return 0;
}