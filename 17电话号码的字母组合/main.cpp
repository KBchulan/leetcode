//
// Created by whx on 24-10-22.
//

#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    static void backtrack(const std::string& digits, const std::vector<std::string>& num_to_strings,
                          const int index, const std::string& current, std::vector<std::string>& result) {
        if (index == digits.size()) {
            result.push_back(current);
            return;
        }

        int digit = digits[index] - '0';

        for (const std::string& letters = num_to_strings[digit];
            const char letter : letters) {
            backtrack(digits, num_to_strings, index + 1, current + letter, result);
        }
    }

    static std::vector<std::string> letterCombinations(const std::string& digits) {
        const std::vector<std::string> num_to_strings = {
            "", "", "abc", "def", "ghi",
            "jkl", "mno", "pqrs", "tuv", "wxyz"
        };

        std::vector<std::string> result;

        if (digits.empty()) {
            return result;
        }

        backtrack(digits, num_to_strings, 0, "", result);
        return result;
    }
};

int main(int argc, char **argv) {
    std::ios::sync_with_stdio(NULL);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    const std::string str = "23";
    for(std::vector<std::string> res =  Solution::letterCombinations(str);
        const auto& aaa :res) {
        std::cout << aaa << std::endl;
    }
}