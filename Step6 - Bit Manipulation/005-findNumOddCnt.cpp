#include <bits/stdc++.h>
using namespace std;

int findNumOddCnt(int arr[], int n)
{
    int num = 0;
    for (int i = 0; i < n; i++)
        num = num ^ arr[i];
    return num;
}