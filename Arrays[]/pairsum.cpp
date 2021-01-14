#include<iostream>
using namespace std;

int main(){
    //-----Find 2 numbers in array whose sum equals k-------------
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter Elememts : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int k;
    cout<<"\nEnter K : ";
    cin>>k;

    int st=0,en=n-1;
    int sum=0;
    for(int i=0;i<n;i++){
        sum = a[st] + a[en];
        if(sum==k){break;}
        else if(sum<k){
            st++;
        }
        else{
            en--;
        } 
    }
    cout<<" "<<st<<" "<<en;
}