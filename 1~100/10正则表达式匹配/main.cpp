//
// Created by whx on 24-10-19.
//

#include <string>
#include <cstring>
#include <iostream>

class Solution {
public:
    static bool isMatch(const std::string& s, const std::string& p) {
        const auto n = static_cast<int64_t>(s.size());
        const auto m = static_cast<int64_t>(p.size());

        bool dp[n + 1][m + 1];
        memset(dp, false, sizeof(dp));
        dp[0][0] = true;

        for(auto i = 0; i <= n; i++) {
            for(auto j = 1; j <= m; j++) {

                if(p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 2] || (i > 0 && (s[i - 1] == p[j - 2]
                        || p[j - 2] == '.') && dp[i - 1][j]);

                else
                    dp[i][j] = i > 0 && dp[i - 1][j - 1] && (s[i - 1] == p[j - 1] || p[j - 1] == '.');

            }
        }

        return dp[n][m];
    }

};

int main() {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const std::string entire("aaa");
    const std::string part("a*");

    std::cout << Solution::isMatch(entire, part) << std::endl;
}