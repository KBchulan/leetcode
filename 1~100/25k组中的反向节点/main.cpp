//
// Created by whx on 24-10-26.
//

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(const int x) : val(x), next(nullptr) {}
    ListNode(const int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == nullptr) {
            return nullptr;
        }

        ListNode* check = head;
        for (int i = 0; i < k; ++i) {
            if (!check) return head;
            check = check->next;
        }

        ListNode* next = nullptr;
        ListNode* curr = head;
        ListNode* prev = nullptr;
        int cnt = 0;

        while(curr != nullptr && cnt < k) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
            cnt++;
        }

        if(next != nullptr) {
            head->next = reverseKGroup(next, k);
        }
        return prev;
    }
};

