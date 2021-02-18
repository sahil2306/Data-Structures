#include<iostream>
using namespace std;

int countPath(int n, int i, int j){
    if(i==(n-1) && j==(n-1)){
        return 1;
    }
    if(i>=n || j>=n){
        return 0;
    }    
    
    return countPath(n,i+1,j) + countPath(n,i,j+1);
}

int board(int s, int e){
    if(s==e){
        return 1;
    }
    if(s>e){
        return 0;
    }
    int count=0;
    for(int i=1;i<=6;i++){
        count+=board(s+i,e);
    }
    return count;
}

void permutation(string s, string ans){
    if(s.length()==0){
        cout<<ans<<" ";
        return;
    }
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        string ros = s.substr(0,i)+s.substr(i+1);

        permutation(ros,ans+ch);
    }
}

int main(){
    //Print all possible permutations of a number
    cout<<"\n All possible permutations are : ";
    permutation("ABCD","");

    //Number of possible ways to reach from one starttin point to end point in board game with a dice
    cout<<"\n Number of possible paths are : ";
    cout<<board(0,5);

    //Number of possible ways to reach from top right to bottom left in a maze
    cout<<"\n Number of possible paths in maze are : ";
    cout<<countPath(4,0,0);
}