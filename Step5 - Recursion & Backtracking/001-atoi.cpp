#include <bits/stdc++.h>
using namespace std;

/* method 1 (optimize apprpach: using iterative way) */
int atoi(string str)
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
        deci = deci * -1;
    return deci;
    /*  TC-O(n)
        SC-O(1) */
}

/* method 2 (optimize approach: using recursion) */
int solve(string str, int ind, int &num)
{
    if (ind >= str.size())
        return num;

    if (str[ind] < '0' || str[ind] > '9')
        return -1;

    num = num * 10 + (str[ind] - '0');
    if (solve(str, ind + 1, num) == -1)
        return -1;
    return num;
}
int atoi(string str)
{
    int num = 0;

    bool flag = false;

    if (str[0] == '-')
        num = solve(str, 1, num);
    else
        num = solve(str, 0, num);

    if (num == -1)
        return -1;
    return str[0] == '-' ? num * -1 : num;
    /*  TC-O(n)
        SC-O(n-stack space) */
}