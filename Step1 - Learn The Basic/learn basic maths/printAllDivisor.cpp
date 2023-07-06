#include <bits/stdc++.h>
using namespace std;

/*
    let n = 36, divisor = 1, 2, 3, 4, 6, 9, 12, 18, 36
    itartate througu 1 - n and check n % i == 0 if yes then print(i)

    but you observe
    1 * 36 = n/1
    2 * 18 = n/2
    3 * 12 = n/3
    4 * 9 = n/4
    ---------
    6 * 6 - sqrt(36)
    ---------
    9 * 4 = n/9
    12 * 3 = n/12
    18 * 2 = n/18
    36 * 1 = n/36
*/

void printDivisor(int n)
{
    for (int i = 1; i <= n; i++)
    {
        if (n % i == 0)
            cout << i << " ";
    }
    /* TC-O(N) SC-O(1) */
}

void printDivisor(int n)
{
    for (int i = 1; i * i <= n; i++) // instead going sqrt(n)
    {
        if (n % i == 0)
        {
            cout << i << " ";
            if ((n / i) != i)
                cout << n / i << " ";
        }
    }
    // if you need to sort divisior then push
    /* TC-O(sqrt(n)) SC-O(1) */
}