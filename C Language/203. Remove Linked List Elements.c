/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* removeElements(struct ListNode* head, int val){
    if(head==NULL) return NULL;
    struct ListNode *search = head->next;
    struct ListNode *now = head;
    while(search!=NULL){
        if(search->val==val){
            now->next=search->next;
            free(search);
            search=now->next;
        }
        else{
            search=search->next;
            now=now->next;
        }
    }
    if(head->val==val){
        now=head;
        head=head->next;
        free(now);
    }
    return head;
}