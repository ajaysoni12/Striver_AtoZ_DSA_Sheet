#include <bits/stdc++.h>
using namespace std;

/* method 1 (Brute Force Approach: Apply Sorting - Quick/Merge Sort) */
int largestElement(vector<int> &arr, int n)
{
    // sort the array in accending order
    sort(arr.begin(), arr.end());

    // return last index value
    return arr[n - 1];
    /* TC-O(n*log(n)) SC-O(1) - for quick sort */
}

/* method 2 (Optimal Approach: Linear Traversal) */
int largestElement(vector<int> &arr, int n)
{
	int largest = arr[0]; 
	for(int i = 1; i < n; i++) 
		largest = max(largest, arr[i]); 
	return largest; 
	/* TC-O(n) SC-O(1) */
}
