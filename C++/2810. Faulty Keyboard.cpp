class Solution {
public:
    string finalString(string s) {
        string ans;
        for (int x = 0; x < s.size(); ++x) {
            if(s[x] == 'i') {
                reverse(ans.begin(), ans.end());
            }
            else {
                ans.push_back(s[x]);
            }
        }
        return ans;
    }
};