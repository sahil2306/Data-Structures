#include<iostream>
using namespace std;

bool isSafe(int **arr, int x,int y,int n){
    if(x<n && y<n && arr[x][y]==1){
        return true;
    }
    return false;
}

bool maze(int **arr, int x,int y,int n,int** sol){

    if((x==(n-1)) && (y==(n-1))){
        sol[x][y] = 1;
        return true;
    }

    if(isSafe(arr,x,y,n)){
        sol[x][y] = 1;
        if(maze(arr,x+1,y,n,sol)){
            return true;
        }
        if(maze(arr,x,y+1,n,sol)){
            return true;
        }
        sol[x][y] = 0;
        return false;
    }
    return false;
}

int main(){
    int n;
    cout<<"Enter n : ";
    cin>>n;

    int** arr = new int*[n];
    for(int i=0;i<n;i++){
        arr[i] = new int[n];
        for(int j=0;j<n;j++){
            cin>>arr[i][j];
        }
    }

    int** sol = new int*[n];
    for(int i=0;i<n;i++){
        sol[i] = new int[n];
        for(int j=0;j<n;j++){
            sol[i][j] = 0;
        }
    }

    cout<<"\n";
    if(maze(arr,0,0,n,sol)){
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                cout<<sol[i][j];
            }
            cout<<"\n";
        }
    
        
        cout<<"\nAns : Yes";
    }

    delete [] arr;
    delete [] sol;
}