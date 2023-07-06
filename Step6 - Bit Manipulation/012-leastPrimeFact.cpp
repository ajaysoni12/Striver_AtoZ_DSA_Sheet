#include <bits/stdc++.h>
using namespace std;
vector<int> leastPrimeFactor(int n)
{
    vector<int> temp(n + 1, 0);

    for (int i = 2; i <= n; i++)
    {
        if (temp[i] == i)
        {
            for (int j = 2 * i; j <= n; j += i)
            {
                if (temp[j] == 0)
                    temp[j] = i;
            }
        }
    }
    return temp;
}