#include<bits/stdc++.h>
using namespace std;

void sieve(int n){
    
    int arr[n+1]={0};
    
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<n;j+=i){
                arr[j] = 1;
            }
        }
    }
    for(int i=2;i<n;i++){
        if(!arr[i]){
            cout<<" "<<i;
        }
    }
}

int main(){
    //Find the prime numbers till n
    int n;
    cout<<"Enter n : ";
    cin>>n;

    sieve(n);
}