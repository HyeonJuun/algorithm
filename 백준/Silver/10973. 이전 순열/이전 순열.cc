#include <iostream>
using namespace std;


bool func(int arr[], int n){
    int i=n-1;
    while(i>0 && arr[i]>arr[i-1])
    i--;

    if(i<=0)
    return false;

    int j= n-1;
    while(arr[i-1]<arr[j])
    j--;

    swap(arr[i-1],arr[j]);
    j=n-1;
    while(i<j){
        swap(arr[i],arr[j]);
        i++;
        j--;
    }
    return true;


}


int arr[10001];

int main(){
    int n; 
    cin>>n;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    if(func(arr,n)){
        for(int i=0; i<n; i++){
            cout<<arr[i]<<" ";
        }
    }else{
        cout<<-1<<"\n";
    }
    
}