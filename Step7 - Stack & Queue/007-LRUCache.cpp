#include <bits/stdc++.h>
using namespace std;

class LRUCache
{
public:
    class node
    {
    public:
        int key, val;
        node *next, *prev;
        node(int _key, int _val)
        {
            key = _key;
            val = _val;
        }
    };

    node *head = new node(-1, -1);
    node *tail = new node(-1, -1);

    int cap;
    unordered_map<int, node *> mp;

    LRUCache(int capacity)
    {
        cap = capacity;
        head->prev = nullptr;
        head->next = tail;
        tail->prev = head;
        tail->next = nullptr;
    }

    void addnode(node *newnode)
    {
        node *temp = head->next;
        newnode->next = temp;
        newnode->prev = head;
        head->next = newnode;
        temp->prev = newnode;
    }

    void deletenode(node *delnode)
    {
        node *delNext = delnode->next;
        node *delPrev = delnode->prev;
        delPrev->next = delNext;
        delNext->prev = delPrev;
    }

    void put(int _key, int value)
    {
        if (mp.find(_key) != mp.end())
        {
            node *existnode = mp[_key];
            mp.erase(_key);
            deletenode(existnode);
        }

        if (mp.size() == cap)
        {
            mp.erase(tail->prev->key);
            deletenode(tail->prev);
        }

        addnode(new node(_key, value));
        mp[_key] = head->next;
        /*  TC-O(n) */
    }

    int get(int _key)
    {
        if (mp.find(_key) != mp.end())
        {
            node *resnode = mp[_key];
            int res = resnode->val;
            mp.erase(_key);
            deletenode(resnode);
            addnode(resnode);
            mp[_key] = head->next;
            return res;
        }
        return -1;
        /*  TC-O(1) */
    }
};