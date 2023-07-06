#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using traversing) */
long long pow(int x, int r)
{
    bool flag = false;
    if (r < 0)
        flag = true, r = -r;

    long long num = 1;
    for (int i = 1; i <= r; i++)
        num = num * x;

    return flag ? 1 / (long long)num : (long long)num;

    /*  TC-O(n)
        SC-O(1) */
}

/* method 2 (optimize approach: using binary expo) */
long long pow(int x, int r)
{
    /*
        2^10 = (2*2)^5 = 4^5
        4^5  = 4 * 4^4 = 4 * (4*4)^2 = 4 * 16^2
        16^2 = (16*16)^1 = 256^1
        256^1 = 256 * (256)^0
    */

    long long ans = 1;
    long long rr = r; // store copy

    // if xx is -2....468, if multiply -1 then convert into 
    // 2....468, and integer can't be store(overflow - int can store 2.....467), that why take long long
    if(rr < 0) rr = -1 * rr; 

    while(rr > 0) {
        if(rr % 2 == 1) {
            ans = (ans * x) % 100000007; 
            rr = rr - 1; 
        } else {
            x = (x * x) % 100000007; 
            rr = rr / 2; 
        }
    }

    if(r < 0) 
        ans = 1 / ans; 
    
    return ans; 
    /*  TC-O(n)
        SC-O(1) */

    /*
    using recursion: 
        if(R == 1) return N;
        if(R == 0) return 1;
        long long int ans= power(N,R/2)%mod;
        ans = (ans*ans)%mod;
        return (R%2 == 0)?ans:(N*ans)%mod;
    */

}