#include <bits/stdc++.h>
using namespace std;
vector<int> leastPrimeFactor(int n)
{
    vector<int> temp(n + 1);
    for (int i = 0; i <= n; i++)
        temp[i] = i;

    for (int i = 2; i <= n; i++)
    {
        if (temp[i] == i)
        {
            for (int j = 2 * i; j <= n; j += i)
                temp[j] = i;
        }
    }
    return temp;

    // you can convert into sqrt(n)
    int i = 2;
    while (n != 1)
    {
        if (n % i == 0)
            n /= i;
        else
            i++;
    }
}