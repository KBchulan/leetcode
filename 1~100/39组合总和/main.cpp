#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    vector<vector<int>> combinationSum(vector<int> &candidates, int target)
    {
        vector<vector<int>> result;
        vector<int> combination;
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
            combination.push_back(candidates[i]);
            backtrack(result, combination, candidates, target - candidates[i], i);
            combination.pop_back();
        }
    }
};

int main()
{
    shared_ptr<Solution> solution = make_shared<Solution>();
    vector<int> candidates = {2, 3, 6, 7};
    int target = 7;
    vector<vector<int>> result = solution->combinationSum(candidates, target);
    for (const auto &i : result)
    {
        for (auto j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}