//Count number of smaller numbers after an element in an array using mergesort.

#include<iostream>
using namespace std;
int inversions = 0;

void merge(int arr[], int l, int mid, int r){
    
    int n1 = mid-l+1;
    int n2 = r-mid;
    int a[n1],b[n2];

    for(int i=0;i<n1;i++){
        a[i] = arr[l+i];
    }
    for(int i=0;i<n2;i++){
        b[i] = arr[mid+1+i];
    }

    int i=0,j=0,k=l;
    while(i!=n1 && j!=n2){
        if(a[i]<=b[j]){
            arr[k++] = a[i];
            i++;
        }
        else if(a[i]>b[j]){
            arr[k++] = b[j];
            j++;
            inversions+=(n1-i);
        }
    }
    while(i<n1){
        arr[k++] = a[i++];
    }
    while(j<n2){
        arr[k++] = b[j++];
    }
}

void mergesort(int arr[], int l, int r){
    if(l>=r){
        return;
    }
    
    int mid = l+ (r-l)/2;
        
    mergesort(arr,l,mid);
    mergesort(arr,mid+1,r);

    merge(arr,l,mid,r);
    
}

int main(){
    int n=6;
    int arr[] = {1,3,5,6,2,4,0};
    
    mergesort(arr,0,n);

    cout<<"inversions : "<<inversions<<endl;
    
    for(int i=0;i<=n;i++){
        cout<<arr[i]<<" ";
    }
}