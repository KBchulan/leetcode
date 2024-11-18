#include <vector>
#include <string>
#include <iostream>

using namespace std;

class Solution
{
public:
    static int longestValidParentheses(string s)
    {
        int result = 0;
        std::vector<int> tmp;
        tmp.emplace_back(-1);
        for(auto i = 0; i < s.size(); i++){
            if(s[i] == '('){
                tmp.push_back(i);
            }
            else{
                tmp.pop_back();
                if(tmp.empty()){
                    tmp.push_back(i);
                }
                else result = std::max(result, i - tmp.back());
            }
        }
        
        return result;
    }
};

int main()
{
    const auto s(std::string("(()"));
    std::cout << Solution::longestValidParentheses(s) << std::endl;
    return 0;
}