class Solution {
public:

    string reverseParentheses(string s) {
        int size = s.size();
        string ans = "";
        stack<int> st;
        for (int x = 0; x < size; ++x) {
            if (s[x] == '(') {
                st.push(x);
            }
            else if(s[x] == ')') {
                reverse(s.begin() + st.top(), s.begin() + x);
                st.pop();
            }
        }
        for (auto c : s) {
            if (c != '(' && c != ')') {
                ans += c;
            }
        }
        return ans;
    }
};