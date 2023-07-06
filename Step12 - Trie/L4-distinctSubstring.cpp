#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = false;
    bool containsKey(char ch)
    {
        return (links[ch - 'a'] != NULL);
    }
    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }
    Node *get(char ch)
    {
        return links[ch - 'a'];
    }
    void setEnd()
    {
        flag = true;
    }
    int isEnd()
    {
        return flag;
    }
};

int cntDistinctSubstring(string &word)
{
    int n = word.size();

    Node *root = new Node();
    int cnt; 

    for (int i = 0; i < n; i++)
    {
        Node *node = root;
        for (int j = i; j < n; j++)
        {
            if (!node->containsKey(word[i]))
            {
                cnt++;
                node->put(word[i], new Node());
            }
            node = node->get(word[i]);
        }
    }
    return cnt + 1; // for empty string  +1
}