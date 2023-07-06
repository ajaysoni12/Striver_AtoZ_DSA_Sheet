#include <bits/stdc++.h>
using namespace std;

string is_palindrome(int num)
{
    int revNum = 0, dup = num;
    while (num > 0)
    {
        int ld = num % 10;
        revNum = revNum * 10 + ld;
        num = num / 10;
    }
    return dup == revNum ? "Yes" : "No";
}