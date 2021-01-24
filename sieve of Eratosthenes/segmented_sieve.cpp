#include<bits/stdc++.h>
using namespace std;

void sieve(int n, vector<int>& prime){
    
    int arr[n+1]={0};
    
    for(int i=2;i<n;i++){
        if(arr[i]==0){
            prime.push_back(i);
            for(int j=i*i;j<n;j+=i){
                arr[j] = 1;
            }
        }
    }
}

void segmented(int low, int high){
    int lim = floor(sqrt(high)) + 1;
    vector<int> prime;
    sieve(lim,prime);

    int n = high+1-low;
    int arr[n];
    for(int i=0;i<n;i++){arr[i] = 1;}
    
    for(int i=0;i<prime.size();i++){
        int rm = floor(low / prime[i]) * prime[i];
        if (rm < low){rm += prime[i];}
        for (int j=rm; j<=high; j+=prime[i]){
            arr[j-low] = 0;
        }
    }

    for(int k=low;k<=high;k++)
        if (arr[k - low]==1){
            cout << k << "  ";
        }
}

int main(){
    //Find the prime numbers between low and high
    int low,high;
    cout<<"Enter low & high : ";
    cin>>low>>high;

    segmented(low,high);
}