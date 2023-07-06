#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

/* method 1 (brute force approach: using two loops) */
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;

    Node *curr = head;
    while (curr != NULL)
    {
        Node *temp = curr->next;
        while (temp != NULL)
        {
            int sum = curr->data + temp->data;
            if (sum == target)
                res.push_back({curr->data, temp->data});

            temp = temp->next;
        }
        curr = curr->next;
    }
    return res;
    /*  TC-O(n*n = n^2-near about)
        SC-O(1) */
}

/* method 2 (better approach: using hashing) */
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;
    if (head == NULL || head->next == NULL)
        return res;

    unordered_map<int, int> mp;
    Node *curr = head;
    while (curr != NULL)
    {
        int remain = target - curr->data;
        if (mp.find(remain) != mp.end())
            res.push_back({curr->data, remain});
        mp[curr->data]++;
        curr = curr->next;
    }
    // question needed
    sort(res.begin(), res.end());
    return res;
    /*  TC-O(n + nLogn)
        SC-O(n)
    */

    // for removing sorting,
    // put freq  first, then tarverse form last-o(n)
    /*
        TC-O(n + n)
        SC-O(n)
    */
}

/* method 3 (optimize approach: using two pointer) */
vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
{
    vector<pair<int, int>> res;
    if (head == NULL or head->next == NULL)
        return res;

    // set low and high pointer
    Node *low = head;
    Node *high = head;
    while (high->next != NULL)
        high = high->next;

    // element sorted
    while (low->data < high->data)
    {
        int sum = low->data + high->data;
        if (sum == target)
            res.push_back({low->data, high->data});
        if (sum < target)
            low = low->next;
        else
            high = high->prev;
    }
    return res;
    /*  TC-O(n + n)
        SC-O(1) */
}