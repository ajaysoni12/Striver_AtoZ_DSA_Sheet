#include <bits/stdc++.h>
using namespace std;

struct node
{
    int key, value, cnt;
    node *next, *prev;
    node(int _key, int _value)
    {
        key = _key;
        value = _value;
        cnt = 1;
    }
};

struct List
{
    int size;
    node *head, *tail;
    List()
    {
        head = new node(0, 0);
        tail = new node(0, 0);
        head->next = tail;
        tail->prev = head;
        size = 0;
    }

    void addFront(node *newNode)
    {
        node *temp = head->next;
        newNode->next = temp;
        newNode->prev = head;
        head->next = newNode;
        temp->prev = newNode;
        size++;
    }

    void removeNode(node *delNode)
    {
        node *delPrev = delNode->prev;
        node *delNext = delNode->next;
        delPrev->next = delNext;
        delNext->prev = delPrev;
        size--;
    }
};

class LFUCache
{
private:
    map<int, node *> keyNode;
    map<int, List *> freqListMap;
    int maxSizeCache;
    int minFreq;
    int currSize;

public:
    LFUCache(int _cap)
    {
        maxSizeCache = _cap;
        minFreq = 0;
        currSize = 0;
    }

    void updateFreqListMap(node *node)
    {
        keyNode.erase(node->key);
        freqListMap[node->cnt]->removeNode(node);
        if (node->cnt == minFreq && freqListMap[node->cnt]->size == 0)
            minFreq++;

        List *nextHigherFreqList = new List();
        if (freqListMap.find(node->cnt + 1) != freqListMap.end())
            nextHigherFreqList = freqListMap[node->cnt + 1];

        node->cnt += 1;
        nextHigherFreqList->addFront(node);
        freqListMap[node->cnt] = nextHigherFreqList;
        keyNode[node->key] = node;
    }

    int get(int key)
    {
        if (keyNode.find(key) != keyNode.end())
        {
            node *node = keyNode[key];
            int val = node->value;
            updateFreqListMap(node);
            return val;
        }
        return -1;
    }

    void put(int key, int val)
    {
        if (maxSizeCache == 0)
            return;

        if (keyNode.find(key) != keyNode.end())
        {
            node *node = keyNode[key];
            node->value = val;
            updateFreqListMap(node);
        }
        else
        {
            if (currSize == maxSizeCache)
            {
                List *list = freqListMap[minFreq];
                keyNode.erase(list->tail->prev->key);
                freqListMap[minFreq]->removeNode(list->tail->prev);
                currSize--;
            }

            currSize++;
            minFreq = 1;
            List *listFreq = new List();
            if (freqListMap.find(minFreq) != freqListMap.end())
                listFreq = freqListMap[minFreq];

            node *nodee = new node(key, val);
            listFreq->addFront(nodee);
            keyNode[key] = nodee;
            freqListMap[minFreq] = listFreq;
        }
    }
};