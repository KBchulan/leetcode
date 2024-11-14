#include <bits/stdc++.h>

using namespace std;

class Solution
{
private:
    vector<vector<int>> result;
    vector<int> path;

    void backtrack(int start, int n, int k)
    {
        if (path.size() == k)
        {
            result.push_back(path);
            return;
        }

        for (int i = start; i <= n; i++)
        {
            path.push_back(i);
            backtrack(i + 1, n, k);
            path.pop_back();
        }
    }

public:
    vector<vector<int>> combine(int n, int k)
    {
        result.clear();
        path.clear();
        
        backtrack(1, n, k);
        return result;
    }
};