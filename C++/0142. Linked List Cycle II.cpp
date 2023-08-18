/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (fast == slow) {
                ListNode* i1 = fast;
                ListNode* i2 = head;
                while (i1 != i2) {
                    i1 = i1->next;
                    i2 = i2->next;
                }
                return i2;
            }
        }
        return nullptr;
    }
};