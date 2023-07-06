#include <bits/stdc++.h>
using namespace std;

void swapNum(int num1, int num2)
{
    num1 = (num1 ^ num2);
    num2 = (num1 ^ num2);
    num1 = (num1 ^ num2);
}