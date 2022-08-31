/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */


struct ListNode* mergeTwoLists(struct ListNode* list1, struct ListNode* list2){
    if(list1==NULL) return list2;
    if(list2==NULL) return list1;
    if(list1==NULL &&list2==NULL) return NULL;
    struct ListNode *head=NULL;
    if(list1->val <= list2->val){
        head=list1;
        list1=list1->next;
    }
    else{
        head=list2;
        list2=list2->next;
    }
    struct ListNode *merge=head;
    while(list1!=NULL && list2!=NULL){
        if(list1->val <= list2->val){
            merge->next=list1;
            list1=list1->next;
        }
        else{
            merge->next=list2;
            list2=list2->next;
        }
        merge=merge->next;
    }
    if(list1!=NULL) merge->next=list1;
    if(list2!=NULL) merge->next=list2;
    return head;
}