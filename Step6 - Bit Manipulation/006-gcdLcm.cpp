#include <bits/stdc++.h>
using namespace std;

/*  inbuilt function
    __gcd(a, b)
*/

/* a * b / gcd = lcm */
int gcd(int a, int b)
{
    if (a % b == 0)
        return b;

    /*
        // another base condition, on more recursion call
        if(b == 0)
            return a;
    */

    return gcd(b, a % b);
    /*  TC-O(log2(n))*/
}

int lcm(int a, int b)
{
    int GCD = gcd(a, b);
    return (a * b) / GCD;
}