#include <bits/stdc++.h>
using namespace std;

int atoi(string &str)
{
    int deci = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '-' and i == 0)
            continue;
        else if (str[i] == '-' or (str[i] < '0' or str[i] > '9'))
            return -1;
        deci = deci * 10 + (str[i] - '0');
    }

    if (str[0] == '-')
        deci *= -1;
    return deci;
    /*  TC-O(n)
        SC-O(1) */
}