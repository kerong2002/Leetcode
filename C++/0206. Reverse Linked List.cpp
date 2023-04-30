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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == nullptr){
            return head;
        }
        else{
            ListNode *NewNode = reverseList(head->next);
            ListNode *headNext = head->next;
            headNext->next = head;
            head->next = nullptr;
            return NewNode;
        }
    }
};