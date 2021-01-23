#include <bits/stdc++.h> 
using namespace std; 

 int singleNonDuplicate(vector<int>& nums) {
        int xorsum = 0;
        for(int i=0;i<nums.size();i++){
            xorsum^=nums[i];
        }
        return xorsum;
}

bool getBit(int n, int pos) {
    return ((n & (1 << pos)) != 0);
}

int setBit1(int n, int p){
    //Mask: 1 << i. Bitwise OR operation between n and mask sets the ith bit to one.
    return (n | (1<<p));
}

int setBit(int n, int p){
    //Mask: 1 << i. Bitwise OR operation between n and mask sets the ith bit to one.
    return ((n & (1 << p)) != 0);
}
void doubleNonDuplicate(vector<int>& arr) {
        int xorsum = 0;
        for (int i = 0; i < arr.size(); i++) {
            xorsum = xorsum ^ arr[i];
        }
        int tempxor = xorsum;
        int setbit = 0;
        int pos = 0;
        while (setbit != 1) {
            setbit = xorsum & 1;
            pos++;
            xorsum = xorsum >> 1;
        }
        int newxor = 0;
        for (int i = 0; i < arr.size(); i++) {
            if (setBit(arr[i], pos - 1)) {
            newxor = newxor ^ arr[i];
            }
        }
        cout << newxor << " ";
        cout << (tempxor ^ newxor) << " ";
}

int uniq(vector<int>& arr){
    int result = 0;
    for (int i = 0; i < 64; i++) {
        int sum = 0;
        for (int j = 0; j < arr.size(); j++) {
            if (getBit(arr[j], i)) {
            sum++;
        }
    }
    if (sum % 3 != 0) {
        result = setBit1(result, i);
    }
}
    return result;
}

int main(){
    /*
        Single Element in a Sorted Array

        You are given a sorted array consisting of only integers where every element appears exactly twice, 
        except for one element which appears exactly once. 
        
        Find this single element that appears only once.

        https://leetcode.com/problems/single-element-in-a-sorted-array/
    */  

    vector<int> nums;
    nums.push_back(0);
    nums.push_back(0);
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(2);

    cout<<"Single element is : "<<singleNonDuplicate(nums)<<endl;

    /*
    
    Q2. Write a program to find 2 unique numbers in an array where all numbers
        except two, are present twice.
    
    */

   vector<int> nums1;
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(1);
    nums1.push_back(2);
    nums1.push_back(3);
    nums1.push_back(5);
    nums1.push_back(7);

    cout<<"The elements are  : ";
    doubleNonDuplicate(nums1);
    cout<<endl;
    /*
        Q3. Write a program to find a unique number in an array where all numbers
        except one, are present thrice.
    */

   vector<int> nums2;
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(3);
    nums2.push_back(1);
    nums2.push_back(2);
    nums2.push_back(2);
    nums2.push_back(1);

    cout<<"Single element is : "<<uniq(nums2)<<endl;
}