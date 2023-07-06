#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &str)
{
    /*
    Intuition -
        In Roman numerals,
        if a smaller numeral comes before a larger numeral, it is subtracted, otherwise, they are added to get the integer value.eg :
        IV = > I(1) is less than V(5) = > 5 - 1 = 4
        VI = > V(5) is more than I(1) = > 5 + 1 = 6 int ans = 0;
    */

    int decimal = 0;
    unordered_map<char, int> roman = {
        {'M', 1000},
        {'D', 500},
        {'C', 100},
        {'L', 50},
        {'X', 10},
        {'V', 5},
        {'I', 1}};

    for (int i = 0; i < str.size(); i++)
    {
        if (i < str.size() - 1 and roman[str[i]] < roman[str[i + 1]])
            decimal += (roman[str[i + 1]] - roman[str[i]]);
        else
            decimal += roman[str[i]];
    }
    return decimal;
    /*  TC-O(n) 
        SC-O(7) */
}