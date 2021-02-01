#include<iostream>
using namespace std;

int power(int n, int p){
    
    if(p==0){
        return 1;
    }
    
    return (n*power(n, p-1));
}

bool sorted(int arr[], int n){
    if(n==1){
        return true;
    }
    if(arr[0]<arr[1])
        return sorted(arr+1, n-1);
    return false;
}

int find(int arr[], int k, int i, int n){
    if(n==i){return -1;}
    if(arr[i]==k){
        cout<<" "<<i;
    }
    return find(arr,k,i+1,n);
}

int main(){
    //Find power of n^p
    cout<<"\nAns : "<<power(5,3);
    
    //Check if array is sorted or not
    int arr1[]={1,2,3,4,5};
    cout<<"\nIs sorted? "<<sorted(arr1,5);
    
    int arr2[]={1,2,3,7,5};
    cout<<"\nIs sorted? "<<sorted(arr2,5);
    
    //Find the occurrence of an element using recursion
    int arr3[]={1,7,3,7,5};
    cout<<"Position of occurunces are :";
    find(arr3,7,0,5);
}