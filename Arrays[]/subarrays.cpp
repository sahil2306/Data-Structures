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
    
    //-----------All Subarrays -------------

    cout<<"All SubArrays : \n"<<endl;
    for (int i=0; i <n; i++) 
    { 
        for (int j=i; j<n; j++) 
        {
            for (int k=i; k<=j; k++){
                cout << a[k] << " ";
            }
            cout << endl; 
        } 
    } 

    //-------------Maximum Arithmetic Subarray(same difference)-----------------

    cout<<"\nMax Arithmetic Subarray : ";
    int diff,pdiff,prev_no;
    int count=1,maxc=0;
    
    prev_no = a[0];
    pdiff=a[1]-a[0];

    for (int i=1;i<n;i++) 
    {
        //cout<<" "<<a[i];
        diff = abs(a[i]-prev_no);
        if(diff==pdiff)count++;
        else {count=1;}

        pdiff = diff;
        prev_no = a[i];
        
        maxc = max(count,maxc);    
    }
    cout<<"\nMax Count : "<<maxc;

}