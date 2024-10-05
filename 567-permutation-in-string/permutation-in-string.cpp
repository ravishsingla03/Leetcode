
#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool check(int ar1[26], int ar2[26])
    {
        for (int i = 0; i < 26; i++)
        {
            if (ar1[i] != ar2[i])
            {
                return 0;
            }
        }
        return 1;
    }

public:
    bool checkInclusion(string s1, string s2)
    {
        int count1[26] = {0};
        // store count
        for (int i = 0; i < s1.size(); i++)
        {
            int index = s1[i] - 'a';
            count1[index]++;
        }
        int count2[26] = {0};
        int i = 0;

        while (i < s1.size() && i<s2.size())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            i++;
        }

        if (check(count1, count2))
        {
            return 1;
        }

        while (i < s2.size())
        {
            int index = s2[i] - 'a';
            count2[index]++;
            char oldchar = s2[i-s1.size()];
            index =oldchar - 'a';
            count2[index]--;
            if (check(count1, count2))
            {
                return 1;
            }
            i++;
        }
        return 0;
    }
};