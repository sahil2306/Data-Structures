#include<iostream>
using namespace std;

void dnfsort(int arr[],int n){
    int low=0,mid=0;
    int high = n-1;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
            mid++;low++;
        }
        else if(arr[mid]==2){
            swap(arr[mid],arr[high]);
            high--;
        }
        else{
            mid++;
        }
    }
}

void printArray(int arr[],int n){
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int arr[] = {1,0,2,1,0,2,1,2};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    dnfsort(arr,size);
    
    printArray(arr,size);

    return 0;
}