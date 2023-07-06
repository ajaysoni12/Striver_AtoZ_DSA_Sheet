#include <bits/stdc++.h>
using namespace std;

struct Item
{
    int value;
    int weight;
};

bool cmp(Item a, Item b)
{
    double r1 = (double)a.value / (double)a.weight;
    double r2 = (double)b.value / (double)b.weight;

    return r1 > r2;
}

double fractionalKnapsack(int W, Item arr[], int n)
{
    sort(arr, arr + n, cmp);

    int currWeight = 0;
    double finalValue = 0.0;

    for (int i = 0; i < n; i++)
    {
        if (currWeight + arr[i].weight <= W)
        { // take full weight
            currWeight += arr[i].weight;
            finalValue += arr[i].value;
        }
        else
        { // take fracktion weight
            int remain = W - currWeight;
            finalValue += (arr[i].value / (double)arr[i].weight) * (double)remain;
            break;
        }
    }
    return finalValue;
    /*  TC-O(nLogn + n)
        SC-O(1) */
}