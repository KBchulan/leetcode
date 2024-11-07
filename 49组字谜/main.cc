#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static vector<vector<string>> groupAnagrams(vector<string> &strs)
    {
        unordered_map<string, vector<string>> mp;

        for (auto x : strs)
        {
            string word = x;
            sort(word.begin(), word.end());
            mp[word].push_back(x);
        }

        vector<vector<string>> res;
        
        for (auto x : mp)
            res.push_back(x.second);

        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    vector<vector<string>> res;
    vector<string> strs = {"EAT", "Tia", "So", "And", "Net", "Bat"};

    res = Solution::groupAnagrams(strs);
    for (const auto &item : res)
    {
        for (const auto &str : item)
            cout << str << " ";
        cout << '\n';
    }
    return 0;
}