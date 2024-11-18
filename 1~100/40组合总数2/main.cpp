#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum2(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
        sort(candidates.begin(), candidates.end());
        backtrack(result, combination, candidates, target, 0);
        return result;
    }

    void backtrack(std::vector<std::vector<int>> &result, std::vector<int> &combination,
                   std::vector<int> &candidates, int target, int start)
    {
        if (target == 0)
        {
            result.push_back(combination);
            return;
        }
        if (target < 0)
            return;

        for (int i = start; i < candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i - 1])
                continue;
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i + 1);
            combination.pop_back();
        }
    }
};