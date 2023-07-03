class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) {
            return false;
        }
        int L = -1;
        int R = -1;
        int size = s.size();
        vector<int> english(26, 0);
        for (int x = 0 ; x < size; ++x) {
            if (s[x] != goal[x]) {
                if (L == -1) {
                    L = x;
                }
                else if (R == -1){
                    R = x;
                }
                else {
                    return false;
                }
            }
            else {
                english[s[x] - 'a'] += 1;
            }
        }
        if (L == -1 && R == -1) {
            for (int x = 0; x < 26; ++x) {
                if (english[x] >= 2) {
                    return true;
                }
            }
            return false;
        }
        else if (L != -1  && R != -1) {
            if (s[L] != goal[R] || s[R] != goal[L]) {
                return false;
            }
            else {
                return true;
            }
        }
        else {
            return false;
        }
    }
};