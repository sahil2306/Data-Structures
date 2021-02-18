#include<iostream>
using namespace std;

int knapsack(int value[], int wt[], int n, int W){
    if(n==0 || W==0){
        return 0;
    }
    if(wt[n-1]<W){
        return max(knapsack(value, wt, n-1, W), knapsack(value, wt, n-1, W-wt[n-1])+value[n-1]);}
    return knapsack(value, wt, n-1, W);
}

int pairFriends(int n){
    if(n==0 || n==1 || n==2){
        return n;
    }
    return pairFriends(n-1) + pairFriends(n-2)*(n-1);
}

int tilting(int n){
    if(n==0){
        return 0;
    }
    if(n==1){
        return 1;
    }
    return tilting(n-1)+tilting(n-2);
}

int main(){
    //Number of ways for tiling a 2xn by 2x1
    cout<<"\nNo of ways are : ";
    cout<<tilting(4);

    //Find the number of ways in which n friends can remain single or paired
    cout<<"\nNo of ways are : ";
    cout<<pairFriends(4); 

    //Knapsack
    int wt[3] = {10,20,30};
    int value[3] = {100,50,150};
    int W = 50;
    cout<<"Ans : ";
    cout<<knapsack(value,wt,3,W);
}