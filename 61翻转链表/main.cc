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
    static ListNode *rotateRight(ListNode *head, int k)
    {
        if (head == nullptr)
            return nullptr;
        if (k == 0)
            return head;

        ListNode dummy(0, head);

        ListNode *tmp = dummy.next;
        int length = 1;
        while (tmp->next != nullptr)
        {
            length++;
            tmp = tmp->next;
        }

        k %= length;
        if (k == 0)
            return head;

        ListNode *tail = tmp;

        int idx = 1;
        tmp = dummy.next;
        while (idx < length - k)
        {
            idx++;
            tmp = tmp->next;
        }
        ListNode *newHead = tmp->next;
        tail->next = dummy.next;
        dummy.next = newHead;
        tmp->next = nullptr;

        delete tmp;
        delete tail;
        delete newHead;
        return dummy.next;
    }
};

int main()
{
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    Solution::rotateRight(head, 2);
    delete head;
}