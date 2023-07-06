#include <bits/stdc++.h>
using namespace std;

void bitManipulation(int num, int i)
{
    if (num & (1 << (i - 1)))
        cout << 1 << " ";
    else
        cout << 0 << " ";

    cout << (num | (1 << (i - 1))) << " ";

    cout << (num & (~(1 << i - 1))) << " ";
}