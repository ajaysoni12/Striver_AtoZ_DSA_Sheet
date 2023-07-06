#include <bits/stdc++.h>
using namespace std;

int wordLadder1(string startWord, string targetWord, vector<string> &wordList)
{
    queue<pair<string, int>> q;
    q.push({startWord, 1});

    unordered_set<string> set(wordList.begin(), wordList.end());
    set.erase(startWord); // mark as a visited

    while (!q.empty())
    {
        string word = q.front().first;
        int steps = q.front().second;
        q.pop();

        if (word == targetWord)
            return steps;

        // n * word.length * 26
        for (int i = 0; i < word.size(); ++i)
        {
            char orignal = word[i];
            for (char ch = 'a'; ch <= 'z'; ch++)
            {
                word[i] = ch;

                // exist in the set
                if (set.find(word) != set.end())
                {
                    set.erase(word); // mark as a visited, no need to go further
                    q.push({word, steps + 1});
                }
            }
            // change to orgianal character
            word[i] = orignal;
        }
    }
    return 0;
    /*  TC-O(n*word.length*26 * logn-set) SC-O(n-set + n-queue = 2n)  */
}