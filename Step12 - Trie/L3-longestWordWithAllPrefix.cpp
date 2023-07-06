#include <bits/stdc++.h>
using namespace std;

struct Node
{
    Node *links[26];
    bool flag = true;

    bool containsKey(char ch)
    {
        return links[ch - 'a'] != NULL;
    }

    Node *get(char ch)
    {
        return links[ch - 'a'];
    }

    void put(char ch, Node *node)
    {
        links[ch - 'a'] = node;
    }

    void setEnd()
    {
        flag = true;
    }
    bool isEnd() { return flag; }
};

class Trie
{
private:
    Node *root;

public:
    Trie() { root = new Node(); }
    void insert(string word)
    {
        Node *node = root;
        for (int i = 0; i < word.size(); i++)
        {
            if (!node->containsKey(word[i]))
                node->put(word[i], new Node());
            node = node->get(word[i]);
        }
        node->setEnd();
    }

    bool checkIfPrefixExist(string &word)
    {
        bool flag = true;
        Node *node = root;

        for (int i = 0; i < word.size(); i++)
        {
            if (node->containsKey(word[i]))
            {
                node = node->get(word[i]);
                if (node->isEnd() == false)
                    return false;
            }
            return false;
        }
        return true;
    }
};

string completeLongestString(int n, vector<string> &arr)
{
    Trie trie;
    for (auto &it : arr)
        trie.insert(it);

    string longestString = "";
    for (auto &it : arr)
    {
        if (trie.checkIfPrefixExist(it))
        {
            if (it.length() > longestString.length())
                longestString = it;
            else if (it.length() == longestString.length() && it < longestString)
                longestString = it;
        }
    }

    if (longestString == "")
        return "none";
    return longestString;
}