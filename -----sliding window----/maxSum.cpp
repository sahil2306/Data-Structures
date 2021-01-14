//Find maximum (or minimum) sum of a subarray of size k


#include <iostream>
using namespace std;

// Function to calculate maximum sum
// among all subarrays of size K

void maxSumSubarr(int A[], int N, int K){

	// Initialize fsum to 0
	int fsum = 0;
	int j=0;

	// Calculate sum of first K elements
	for (int i = 0; i < K; i++) {

		fsum += A[i];
	}

	int maxsum = 0;

	// Iterate over the array from
	// (K + 1)-th index
	for (int i = K; i < N; i++) {

		// Subtract the first element
		// from the previous K elements
		// and add the next element
		fsum=fsum-A[j]+A[i]; 
		j++;
		
		maxsum = max(maxsum, fsum);
		
	}

	cout << maxsum << endl;
}

// Driver Code
int main(){
	int arr[] = { -5, 8, 7, 2, 10, 1, 20, -4, 6, 9 };
	int K = 3;

	// Size of Array
	int N = sizeof(arr)/sizeof(arr[0]); 

	// Function Call
	maxSumSubarr(arr, N, K);

	return 0;
}
