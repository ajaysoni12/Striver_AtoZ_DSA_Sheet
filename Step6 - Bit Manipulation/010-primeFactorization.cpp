#include <bits/stdc++.h>
using namespace std;

vector<int> uniquePrimeFact(int n)
{
    vector<int> ans;
    // use i * i(any composite number, have least divisor,jo usko divide krege root n se phle) i * i - TC-o(sqrt(n))
    for (int i = 2; i <= n; i++)
    {
        while (n % i == 0)
        {
            // this is for unique prime factorization
            if (ans.empty())
                ans.push_back(i);
            else if (ans[ans.size() - 1] != i)
                ans.push_back(i);
            n /= i;
        }
    }
    return ans;
    /*  TC-O(n), for n = 1e9 + 7
        SC-O(1) */
}