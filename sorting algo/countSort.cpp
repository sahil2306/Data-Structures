#include<iostream>
using namespace std;
#define range 100

void countsort(int arr[], int n){
    int count[range]={0};
    int output[n];

    for(int i=0;i<n;i++){
        ++count[arr[i]];
    }
    for(int i=1;i<range;i++){
        count[i]+=count[i-1]; 
    }

    for(int i=0;i<n;i++){
        output[--count[arr[i]]] = arr[i];
        
    }
    for(int i=0;i<n;i++){
        cout<<output[i]<<" ";
    }
}

int main(){
    
    int n=7;
    int arr[] = {1,3,7,6,2,4,8};
    
    countsort(arr,n);
    
    return 0;
}