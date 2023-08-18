/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode* dummy = new ListNode(0, head);
        ListNode* cur = dummy;
        while (cur->next != nullptr && cur->next->next != nullptr) {
           ListNode* temp1 = cur->next;
           ListNode* temp2 = cur->next->next->next;
           cur->next = cur->next->next;
           cur->next->next = temp1;
           temp1->next = temp2;
           cur = temp1;
        }
        return dummy->next;
    }
};