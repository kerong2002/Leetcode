class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        string a; 
        while (head != nullptr) {
            a.push_back(head->val + '0');
            head = head->next;
        }

        string result = multiplyByTwo(a);
        
        ListNode* ans = new ListNode(result[0] - '0');
        ListNode* current = ans;

        for (int x = 1; x < result.size(); ++x) {
            ListNode* newNode = new ListNode(result[x] - '0');
            current->next = newNode;
            current = newNode;
        }

        current->next = nullptr;
        return ans;
    }

private:
    string multiplyByTwo(const string& num) {
        string result;
        int carry = 0;

        for (int i = num.size() - 1; i >= 0; --i) {
            int digit = (num[i] - '0') * 2 + carry;
            carry = digit / 10;
            result.insert(result.begin(), digit % 10 + '0');
        }

        if (carry > 0) {
            result.insert(result.begin(), carry + '0');
        }

        return result;
    }
};