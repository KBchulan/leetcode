#include <bits/stdc++.h>

using namespace std;

class Solution
{
public:
    static int lengthOfLastWord(string s)
    {
        vector<string> words;
        stringstream str(s);

        string word;
        while (str >> word)
            words.push_back(word);

        return words.back().size();
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    string str = "Hello World";
    cout << Solution::lengthOfLastWord(str) << endl;
}