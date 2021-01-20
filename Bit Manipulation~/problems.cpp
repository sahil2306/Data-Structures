#include<iostream>
#include<bitset>
#include<algorithm>
#include<vector>
using namespace std;

void countBits(int num) {
        
        vector<int> ans(num+1);
        int ev=1;
        int od=1;
        ans[0]=0;
        for(int i=1;i<=num;i++){
            if((i & (i-1) == 0)){ans[i]=1;}
            else if((i%2)==1){ans[i]=ans[i-1]+1;}
            else{ans[i]=ans[i/2];}
        }
        
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<" ";
        }
    }

bool isPowerOfFour(int n) {
        if(n<=0)return false;
        else if(n&(n-1))return false;
        else{
            int counter = 0;
            while(n>1){
                counter++;
                n=n>>1;
            }
            if(counter%2 ==0)return true;
            else return false;
        }
    }

int hammingDistance(int x, int y) {
        int c=0;
        int temp = x^y;
        string s = bitset<32> (temp).to_string();
        for(int i=0;i<32;i++){
            if(s[i]=='1'){
                c++;
            }
        }
        return c;
}
bool isPowerOfTwo(int n) {

        if(n<=0)
            return false;
        
        return ((n&(n-1))==0);
}

long long reversedBits(long long X) {
        // code here
        string s = bitset<32> (X).to_string();
        reverse(s.begin(),s.end());
        bitset<32> ans(s);
        return ans.to_ulong();
}

int main(){

    //https://leetcode.com/problems/hamming-distance/
    //The Hamming distance between two integers is the number of positions at which the corresponding bits are different.Given two integers x and y, calculate the Hamming distance.
    /*Explanation:
        1   (0 0 0 1)
        4   (0 1 0 0)
                ↑   ↑
        Ans : 2
       */
    cout<<"Hamming Distance between 1 and 4 : "<<hammingDistance(1,4)<<endl;

    /*
        https://leetcode.com/problems/power-of-two/
        Given an integer n, return true if it is a power of two. Otherwise, return false.
        An integer n is a power of two, if there exists an integer x such that n == 2x.
    */
    cout<<"Is 32 a power of 2? "<<isPowerOfTwo(32)<<endl;
    cout<<"Is 5 a power of 2? "<<isPowerOfTwo(5)<<endl;

    /*
        https://leetcode.com/problems/power-of-four/
        Given an integer n, return true if it is a power of four. Otherwise, return false.
        An integer n is a power of four, if there exists an integer x such that n == 4x.
    */
    cout<<"Is 16 a power of 4? :  "<<isPowerOfFour(16)<<endl;
    cout<<"Is 32 a power of 4? :  "<<isPowerOfFour(32)<<endl;

    
    /*
        https://practice.geeksforgeeks.org/problems/reverse-bits3556/1
        Given a 32 bit number X, reverse its binary form and print the answer in decimal.
    */
    cout<<"Reverse of 5 is :  "<<reversedBits(5)<<endl;

    /*
        https://leetcode.com/problems/counting-bits/
        Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num 
        calculate the number of 1's in their binary representation and return them as an array.

        Example 1:
        Input: 2
        Output: [0,1,1]
    */
    cout<<"For 6 : ";
    countBits(6);

    return 0;
}