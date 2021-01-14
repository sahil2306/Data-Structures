#include <iostream>
#include <queue>
using namespace std;

void maxSumSubarr(int A[], int N, int K){

	// Initialize num to 0
	queue<int> num;
    int j=0;

	// Calculate sum of first K elements
	for (int i = 0; i < K; i++) {
        if(A[i]<0){
            num.push(A[i]);
        }
	}
    cout<<num.front()<<" ";

	// Iterate over the array from
	// (K + 1)-th index
	for (int i = K; i < N; i++) {
        if(A[j]<0){
            num.pop();
        }
        j++;
        if(A[i]<0){
            num.push(A[i]);
        }
        if(num.size()>0)
        {cout<<num.front()<<" ";}
        else{cout<<"0 ";}
	}
}

// Driver Code
int main(){
	int arr[] = { 12,-1,-7,8,-15,30,16,28 };
	int K = 3;
	// Size of Array
	int N = sizeof(arr)/sizeof(arr[0]);

	// Function Call
	maxSumSubarr(arr, N, K);

	return 0;
}
