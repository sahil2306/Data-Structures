#include<iostream>
using namespace std;

int getBit(int n, int p){
    //Right shift n 'p' times, and check the first bit.
    return (n >> p) & 1;
}

int setBit(int n, int p){
    //Mask: 1 << i. Bitwise OR operation between n and mask sets the ith bit to one.
    return (n | (1<<p));
}

int clearBit(int  n, int p){
    //Mask: ~ (1 << i ) In the mask, all the bits would be one, except the ith bit. Taking bitwise AND with n would clear the ith bit.
    int x = ~(1<<p);
    return(n & x);
}

int updateBit(int n, int p, int v){
    //First Clear and then set Bit
    int x = clearBit(n,p);
    return(n | (v<<p));

}

int main(){
    //n = deciaml number for which we want to do the bit manipulation
    //p = position
    //v = value
    
    //GetBit
    int ansGet = getBit(5,2);
    cout<<ansGet<<endl;

    //setBit
    int ansSet = setBit(5,1);
    cout<<ansSet<<endl;

    //clearBit
    int ansCl = clearBit(5,0);
    cout<<ansCl<<endl;

    //updateBit
    int ansUp = updateBit(5,3,1);
    cout<<ansUp<<endl;
}