#include<iostream>
using namespace std;

int partition(int arr[],int l, int r){
    
    int p = arr[r];

    int i=l;

    for(int j=l;j<r;j++){
        if(arr[j]<p){
            swap(arr[i++],arr[j]);
        }
    }

    swap(arr[i],arr[r]);
    return i;

}

void quicksort(int arr[],int l, int r){

    if(l>=r){
        return;
    }

    int p = partition(arr,l,r);

    quicksort(arr,l,p-1);
    quicksort(arr,p+1,r);

}

int main(){
    
    int n=6;
    int arr[] = {1,3,7,6,2,4,0};
    
    quicksort(arr,0,n);
    
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
    
    return 0;
}