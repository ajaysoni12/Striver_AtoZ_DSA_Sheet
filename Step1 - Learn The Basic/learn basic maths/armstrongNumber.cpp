#include <bits/stdc++.h>
using namespace std;

string armstrongNumber(int num)
{
    // code here
    int sum = 0, dup = num;
    while (num > 0)
    {
        int ld = num % 10;
        sum = sum + (ld * ld * ld);
        num /= 10;
    }
    return dup == sum ? "Yes" : "No";
}