#include<iostream>
using namespace std;

int main(){
    
    int n;
    cout<<"Enter n : ";
    cin>>n;
    int a[n+1];
    cout<<"\nEnter Elememts : ";
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    
    //Problem1 : 
    /*Given an array arr[] of size N. The task is to find the first repeating element in an
     array of integers, i.e., an element that occurs more than once and whose index of
     first occurrence is smallest.*/

    const int N = 1000;
    int idx[N];
    int minindx;
    for(int i=0;i<N;i++){
        idx[i] = -1;
    }
    for(int i=0;i<n;i++){
        if(idx[a[i]]!=-1){minindx = min(minindx,idx[a[i]]);}
        else{idx[a[i]] = i;}
    }     
    for(int i=0;i<7;i++){
        cout<<" "<<idx[i];
    }
    if(minindx==INT16_MAX){cout<<"-1"<<endl;}
    else{
        cout<<"\n"<<minindx+1<<endl;
    }

    //Problem 2---------------------------------------------------------------
    /*Given an unsorted array A of size N of non-negative integers, find a continuous
        subarray which adds to a given number S.
        Constraints
        1 <= N <= 105
        0 <= Ai <= 1010
        Example
        Input:
        N = 5, S = 12
        A[] = {1,2,3,7,5}
    */
    int s;
    cout<<"Enter S : ";
    cin>>s;
    int st=0,en=0,sum=0;
    while(en<n && (sum+a[en]<=s)){
        sum+=a[en];
        en++;
    }
    cout<<"\n1st while sum : "<<sum<<endl;
    if(sum==s){cout<<(st+1)<<" ...  "<<(en);return 0;}
    while(en<n){
        sum+=a[en];
        while(sum>s){
            sum-=a[st];
            st++;
        }
        if(sum==s){
            cout<<(st+1)<<" "<<(en+1);
            return 0;
        }
        en++;
    }    
    
    return 0;    

    
}