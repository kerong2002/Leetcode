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
    int gcd(int a, int b) {
        if (b == 0) {
            return a;
        }
        return gcd(b, a % b);
    }
    ListNode* insertGreatestCommonDivisors(ListNode* head) {
        ListNode* ans = head;
        ListNode* fast = head;
        ListNode* slow = nullptr;
        while(fast->next != nullptr) {
            slow = fast;
            fast = fast->next;
            cout << slow->val << " , " <<fast->val << endl;
            int ans = gcd(slow->val, fast->val);
            ListNode* temp =  new ListNode(ans, fast);
            slow->next = temp;
        }
        return ans; 
    }  
};