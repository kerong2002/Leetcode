/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* deleteDuplicates(struct ListNode* head){
    if(head==NULL){
        return NULL;
    }
    struct ListNode *now=head;
    struct ListNode *set=NULL;
    while(now->next!=NULL){
        if(now->next->val==now->val){
            set=now->next;
            now->next=set->next;
            free(set);
        }
        else{
             now=now->next;
        }
    }
    return head;
}