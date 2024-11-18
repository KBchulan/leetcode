#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<string> restoreIpAddresses(string s)
    {
        vector<string> result;
        if (s.size() < 4 || s.size() > 12)
            return result;

        backtrack(result, s, "", 0, 0);
        return result;
    }

private:
    void backtrack(vector<string> &result, const string &s, string current, int start, int count)
    {
        if (count == 4 && start == s.size())
        {
            current.pop_back();
            result.push_back(current);
            return;
        }

        if (count > 4)
            return;

        for (int i = 1; i <= 3 && start + i <= s.size(); i++)
        {
            string segment = s.substr(start, i);
            if (isVaild(segment) && stoi(segment) <= 255)
            {
                backtrack(result, s, current + segment + ".", start + i, count + 1);
            }
        }
    }

    bool isVaild(string s)
    {
        if (s.size() == 1)
            return true;

        if (s.front() == '0')
            return false;

        return true;
    }
};