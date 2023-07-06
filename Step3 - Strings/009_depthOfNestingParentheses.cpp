#include <bits/stdc++.h>
using namespace std;

/* method 1 (otimize approach: using linear traversing) */
int maxDepth(string &str)
{
    int depth = 0;
    int openBrac = 0;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '(')
            openBrac++;
        else
            openBrac--;

        depth = max(depth, openBrac);
    }
    return depth;
    /*  TC-O(n)
        SC-O(1) */
}