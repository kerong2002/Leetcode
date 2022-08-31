/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
bool hasCycle(struct ListNode *head) {
    if(head==NULL||head->next==NULL){
        return false;
    }
    struct ListNode *slower=head;
    struct ListNode *faster=head;
    while(slower->next!=NULL&&faster->next!=NULL &&faster!=NULL){
        if(faster->next->next==NULL){
            return false;
        }
        slower=slower->next;
        faster=faster->next->next;
        if(faster==slower){
            return true;
        }
    }
    return false;
}