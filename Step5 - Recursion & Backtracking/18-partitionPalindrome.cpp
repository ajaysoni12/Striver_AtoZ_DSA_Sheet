#include <bits/stdc++.h>
using namespace std;

bool isPalin(string &str, int start, int end)
{
    while (start <= end)
        if (str[start++] != str[end--])
            return false;
    return true;
}
void f(int ind, string &str, vector<string> &path, vector<vector<string>> &ans)
{
    if (ind == str.size())
    {
        ans.push_back(path);
        return;
    }

    for (int i = ind; i < str.size(); i++)
    {
        if (isPalin(str, ind, i))
        {
            path.push_back(str.substr(ind, i - ind + 1));
            f(ind + 1, str, path, ans);
            path.pop_back();
        }
    }
}
vector<vector<string>> partition(string str)
{
    vector<vector<string>> ans;
    vector<string> path;

    f(0, str, path, ans);
    return ans;
    /*  TC-O(n^n * n)
        SC-O(n + n)*/
}
