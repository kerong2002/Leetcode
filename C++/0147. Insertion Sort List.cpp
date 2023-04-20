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
    ListNode* insertionSortList(ListNode* head) {
        int max_size = 0;
        ListNode* dummy = head;
        while(dummy != nullptr){
//                cout << dummy->val << endl;
            dummy = dummy->next;

            max_size += 1;
        }
//        cout << max_size << endl;

        for(int x=1;x<max_size;x++){
            ListNode* pick_pre = nullptr;
            ListNode* pick_curr = head;
            int run = 0;

            while(run < x){
                pick_pre = pick_curr;
                pick_curr = pick_curr->next;
                run++;
            }

            pick_pre->next = pick_curr->next;

            int cnt = 0;

            ListNode* pre = nullptr;
            ListNode* curr = head;
            while(cnt < run){
                if(pick_curr->val < curr->val){
                    break;
                }
                else{
                    pre = curr;
                    curr = curr->next;
                    cnt += 1;
                }
            }
            if(cnt ==0){
                pick_curr->next = curr;
                head = pick_curr;
            }
            else{
                pick_curr->next = pre->next;
                pre->next = pick_curr;
            }
            ListNode* d = head;
        }
        return head;

    }
};