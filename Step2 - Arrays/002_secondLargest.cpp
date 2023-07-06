#include <bits/stdc++.h>
using namespace std;

/* method 1 (Brute Force Approach: Apply Sorting) */
int secondLargest(vector<int> &arr, int n)
{
    // edge case, if size is less than 2
    if (n < 2)
        return -1;

    // sort the array, merge/quick sort
    sort(arr.begin(), arr.end());

    // by default it's -1, because if second largest element doesn't exist then return -1
    int secondLar = -1;
    for (int i = n - 2; i >= 0; i--)
    {
        // if it's not equal that means, it is my second largest element
        if (arr[i] != arr[i + 1])
        {
            secondLar = arr[i];
            break;
        }
    }
    return secondLar;
    /* TC-O(n*log(n) + o(n)) SC-O(1) */
}

/* method 2 (Better Approach: Two Passes) */
int secondLargest(vector<int> &arr, int n)
{
    // step1: find largest element
    int largest = -1;
    for (int i = 0; i < n; i++)
        largest = max(largest, arr[i]);

    // step2: find second largest, with condtion, arr[i] not cross largest element
    int secondLar = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > secondLar and arr[i] < largest)
            secondLar = arr[i];
    }
    return secondLar;
    /* TC-O(n + n = 2n) SC-O(1) */
}

/* method 3 (Optimal Approach) */
int secondLargest(vector<int> &arr, int n)
{
    int largest = arr[0];

    // if array contain neg element, than you will take INT_MIN
    int sLargest = -1; 

    for (int i = 1; i < n; i++)
    {
        // if largest update, than definetly curr largest is my second largest element 
        if(largest < arr[i]) 
        {
            sLargest = largest; 
            largest = arr[i]; 
        }
        // but if curr element is greater than slargest, make sure largest should be greater than curr elements
        else if(largest > arr[i] and sLargest < arr[i]) 
            sLargest = arr[i];
    }
    return sLargest; 
    /* TC-O(n) SC-O(n) */
}
int secondSmallest(vector<int> &arr, int n)
{
    int smallest = arr[0];

    // max size of integer
    int sSmallest = INT_MAX; 

    for (int i = 1; i < n; i++)
    {
        // if smallest update, than definetly curr smallest is my second smallest element 
        if(smallest < arr[i]) 
        {
            sSmallest = smallest; 
            smallest = arr[i]; 
        }
        // but if curr element is smaller than sSmallest, make sure smallest should be smallest than curr elements
        else if(smallest > arr[i] and sSmallest < arr[i]) 
            sSmallest = arr[i];
    }
    return sSmallest; 
    /* TC-O(n) SC-O(n) */
}
