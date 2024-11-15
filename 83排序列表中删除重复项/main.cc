#include <bits/stdc++.h>

using namespace std;

struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    explicit ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    ListNode *deleteDuplicates(ListNode *head)
    {
        ListNode dummy(0, head);

        vector<int> nums;
        while (head != nullptr)
        {
            nums.emplace_back(head->val);
            head = head->next;
        }
        nums.erase(std::unique(nums.begin(), nums.end()), nums.end());

        if (nums.size() == 0)
            return nullptr;

        ListNode *cur = dummy.next;
        for (size_t i = 0; i < nums.size(); i++)
        {
            cur->val = nums[i];
            if (i == nums.size() - 1)
                cur->next = nullptr;
            else
                cur = cur->next;
        }
        return dummy.next;
    }
};