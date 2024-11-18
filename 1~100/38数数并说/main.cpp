#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    string countAndSay(int n)
    {
        if (n == 1)
            return "1";
        string s = "1";
        return result(s, n);
    }

    string result(const string& s, int n)
    {
        if (n == 1)
            return s;
        int i = 0, j = 0;
        optional<string> ans;

        while (i < s.length())
        {
            int count = 0;
            while (j < s.length() && s[i] == s[j]){
                j++;
                count++;
            }
            (*ans) += to_string(count);
            (*ans).push_back(s[i]);
            i = j;
        }
        return result(*ans, n - 1);
    }
};

int main(int argc, char **argv)
{
    int n = 4;
    std::shared_ptr<Solution> sol = std::make_shared<Solution>();
    cout << sol->countAndSay(n) << endl;
}