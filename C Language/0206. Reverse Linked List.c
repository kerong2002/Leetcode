/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* reverseList(struct ListNode* head){
    struct ListNode *now=head;
    struct ListNOde *set=NULL;
    while(now!=NULL){
        struct ListNode *save=now->next;
        now->next=set;
        set=now;
        now=save;
    }
    return set;
}