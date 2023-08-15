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
    ListNode* partition(ListNode* head, int x) {
        ListNode* L1 = new ListNode();
        ListNode* L2 = new ListNode();
        ListNode* L1h = L1;
        ListNode* L2h = L2;
        ListNode* run = head;
        while (run != nullptr) {
            ListNode* temp = new ListNode(run->val);
            if (run->val < x) {
                L1->next = temp;
                L1 = temp;
            }
            else {
                L2->next = temp;
                L2 = temp;
            }
            run = run->next;
        }
        L1->next = L2h->next;
        return L1h->next;
    }
};