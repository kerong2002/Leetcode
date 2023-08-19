class Solution {
public:
    string reverseWords(string s) {
        stack<string> st;
        string ans;
        for (int x = 0; x < s.size(); ++x) {
            string word;
            if (s[x] == ' ') {
                continue;
            }
            while (x < s.size() && s[x] != ' ') {
                word += s[x];
                ++x;
            }
            st.push(word);
        }
        while (!st.empty()) {
            ans += st.top();
            st.pop();
            if (!st.empty()) {
                ans += " ";
            }
        }
        return ans;
    }
};