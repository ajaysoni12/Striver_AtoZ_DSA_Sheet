#include <bits/stdc++.h>
using namespace std;

/* method 1 (brute force approach: using two loops) */
vector<int> intersectionOfArray(vector<int> &a, int n1, vector<int> &b, int n2)
{
    // step1 - intial confrugation
    vector<int> intersectionArr; // stores intersection ele
    vector<int> vis(n2, 0);      // not repeating ele, mark with not visited

    // step2 - find intersection ele
    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            // if it's not vis
            if (a[i] == b[j] && vis[j] == 0)
            {
                intersectionArr.push_back(a[i]);
                vis[j] = 1;
                break;
            }

            // because array is sorted, if any moment j'th value is greater, then break out
            if (b[j] > a[i])
                break;
        }
    }

    return intersectionArr;
    /*  TC-O(n2 + n1*n2)
        SC-O(n2) */
}

/* method 2 (optimal approach: using two pointer approach) */
vector<int> intersectionOfArray(vector<int> &a, int n1, vector<int> &b, int n2)
{
    // step1 - two pointer approach
    int i = 0;
    int j = 0;

    vector<int> ans; // store intersection

    // till anyone not go out of the boundary
    while (i < n1 && j < n2)
    {
        // if first ele is smaller than move it
        if (a[i] < b[j])
            i++;

        // if second ele is smaller than nove it
        else if (b[j] < a[i])
            j++;

        // relation is created
        else
        {
            ans.push_back(a[i]);
            i++, j++;
        }
    }

    return ans;
    /*  TC-O(n1 + n2) - i'th ele move, than j'th ele move(wrost case)
        SC-O(1), not considered ans space */
}