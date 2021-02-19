#include<iostream>
using namespace std;

void wavesort(int arr[],int n){
    for(int i=1;i<n;i+=2){
        if(arr[i]>arr[i-1]){
            swap(arr[i],arr[i-1]);
        }
        if(arr[i]>arr[i+1]  && i<=(n-2)){
            swap(arr[i],arr[i+1]);
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,3,5,6,2,4,0};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    wavesort(arr,size);
    
    printArray(arr,size);

    return 0;
}