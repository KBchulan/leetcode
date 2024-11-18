//
// Created by whx on 24-10-21.
//

#include <vector>
#include <string>
#include <iostream>

class Solution {
public:
    static std::string longestCommonPrefix(const std::vector<std::string>& strs) {
        int idx = 0, min_size = 500;
        std::string result;

        for(const auto& str : strs) {
            min_size = std::min(static_cast<int>(str.length()), min_size);
        }

        while(idx < min_size) {
            const char ch = strs[0][idx];
            for(const auto& str : strs) {
                if(str[idx] != ch)
                    return result;
            }
            idx++;
            result += ch;
        }
        return result;
    }
};


int main(int argc,char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    std::vector<std::string> aaa;
    aaa.emplace_back("flower");
    aaa.emplace_back("flow");
    aaa.emplace_back("flight");

    std::cout << Solution::longestCommonPrefix(aaa) << std::endl;

}