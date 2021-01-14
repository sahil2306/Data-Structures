#include<iostream>
using namespace std;

int kadane(int a[], int n){
    //Kadane's Solution : 
    int currsum = 0;
    int maxsum=INT8_MIN;
    for(int i=0;i<n;i++){
        currsum+=a[i];
        if(currsum<0){currsum=0;}
        maxsum = max(maxsum,currsum);
    }
    return(maxsum);
}

int main(){
    //Problem 1 : Maximum Sum Subarray Array
    
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int a[n];
    cout<<"\nEnter Elememts : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int wrapsum,nonwrap;

    nonwrap = kadane(a,n);
    int totalsum=0;

    for(int i=0;i<n;i++){
        totalsum+=a[i];
        a[i] = -a[i];
    }   

    wrapsum = totalsum + kadane(a,n);

    cout<<"\n MaxSum : "<<wrapsum;
}