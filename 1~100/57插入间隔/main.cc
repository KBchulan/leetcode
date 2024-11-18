#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
    {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());

        int l = intervals[0][0];
        int r = intervals[0][1];
        if (intervals.size() == 1)
            return {{l, r}};

        vector<vector<int>> res;
        for (size_t i = 1; i < intervals.size(); i++)
        {
            if (r < intervals[i][0])
            {
                res.push_back({l, r});
                l = intervals[i][0];
                r = intervals[i][1];
            }
            else if (r <= intervals[i][1] && r >= intervals[i][0])
                r = intervals[i][1];
        }
        res.push_back({l, r});
        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<int>> intervals = {
        {1, 3}, {6, 9}};
    vector<int> newInterval = {2, 5};

    vector<vector<int>> res = Solution::insert(intervals, newInterval);

    for (const auto &line : res)
    {
        for (const auto &num : line)
            cout << num << " ";
        cout << '\n';
    }
}