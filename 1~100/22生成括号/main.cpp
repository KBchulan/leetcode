//
// Created by whx on 24-10-24.
//

#include <vector>
#include <string>

using namespace std;

class Solution {
public:
    static vector<string> generateParenthesis(int n) {
        vector<string> result;
        dfs(0, 0, "", n ,result);
        return result;
    }

    static void dfs(const int open, const int close, const string& s, const int n, vector<string>& result) {
        if (open == close && open + close == n * 2) {
            result.push_back(s);
            return;
        }

        if (open < n)
            dfs(open + 1, close, s + "(", n, result);
        if(close < open)
            dfs(open, close + 1, s + ")" ,n , result);
    }
};