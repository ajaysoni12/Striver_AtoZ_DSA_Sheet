#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[2];

    bool containsKey(int ind) { return links[ind] != NULL; }
    Node *get(int ind) { return links[ind]; }
    void put(int ind, Node *node) { links[ind] = node; }
};

class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }

    void insert(int num)
    {
        Node *node = root;
        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1; // bit set or not
            if (!node->containsKey(bit))
                node->put(bit, new Node());
            node = node->get(bit);
        }
    }

    int findMax(int num)
    {
        Node *node = root;
        int maxNum = 0;

        for (int i = 31; i >= 0; i--)
        {
            int bit = (num >> i) & 1;

            // find opposite one
            if (node->containsKey(1 - bit))
            {
                maxNum = maxNum | (1 << i);
                node = node->get(1 - bit);
            }

            // here we not have any options
            else
                node = node->get(bit);
        }
        return maxNum;
    }
};

vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries)
{
    sort(arr.begin(), arr.end());

    vector<pair<int, pair<int, int>>> offlineQ;

    // O(q)
    int q = queries.size();
    for (int i = 0; i < q; i++)
    {
        // {ai, {xi, ind}}, sort according to ai
        offlineQ.push_back({queries[i][1], {queries[i][0], i}});
    }

    // O(q*logq)
    sort(offlineQ.begin(), offlineQ.end());

    vector<int> ans(q, 0);
    int ind = 0;
    int n = arr.size();

    Trie trie;

    // o(q), overall O(q * 32 + n * 32)
    for (int i = 0; i < q; i++)
    {
        int ai = offlineQ[i].first;
        int xi = offlineQ[i].second.first;
        int qInd = offlineQ[i].second.second;

        // throught all time, it will run only O(n)
        while (ind < n && arr[ind] <= ai)
        {
            trie.insert(arr[ind]);
            ind++;
        }

        if (ind == 0)
            ans[qInd] = -1;
        else
            ans[qInd] = trie.findMax(xi);
    }
    return ans; 
}