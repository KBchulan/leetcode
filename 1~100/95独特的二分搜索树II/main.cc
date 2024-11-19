#include <bits/stdc++.h>

using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution
{
public:
    vector<TreeNode *> generateTrees(int n)
    {
        if (n == 0)
            return vector<TreeNode *>();
        return generateTreeNode(1, n);
    }
    
    vector<TreeNode *> generateTreeNode(int start, int end)
    {
        vector<TreeNode *> result;

        if (start > end)
        {
            result.push_back(nullptr);
            return result;
        }

        for (int i = start; i <= end; i++)
        {
            vector<TreeNode *> leftNode = generateTreeNode(start, i - 1);
            vector<TreeNode *> rightNode = generateTreeNode(i + 1, end);

            for (auto left: leftNode)
            {
                for (auto right : rightNode)
                {
                    TreeNode *root = new TreeNode(i);
                    root->left = left;
                    root->right = right;
                    result.push_back(root);
                }
            }
        }

        return result;
    }
};