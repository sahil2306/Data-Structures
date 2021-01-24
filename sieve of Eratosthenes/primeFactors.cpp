#include <bits/stdc++.h> 
using namespace std; 

void factors(int n){
    int arr[n+1]={0};
    
    // for(int i=2;i<n;i++){
    //     arr[i] = i;
    // }

    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            for(int j=i*i;j<=n;j+=i){
                if(arr[j]==0){arr[j] = i;}
            }
        }
    }

    for(int i=2;i<=n;i++){
        if(arr[i]==0){
            arr[i] = i;
        }
        //cout<<arr[i]<<" ";
    }
    //cout<<endl;

    while(n!=1){
        cout<<arr[n]<<" ";
        n = n/arr[n];
    }
}

int main(){
    //Find Prime Factor using sieve of eratosthenes

    int n;
    cout<<"Enter n : ";
    cin>>n;

    factors(n);
}