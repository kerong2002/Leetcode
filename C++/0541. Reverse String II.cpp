class Solution {
public:
    string reverseStr(string s, int k) {
        for(int x = 0; x < s.size(); x += 2*k) {
            if (x + k <= s.size()) {
                reverse(s.begin() + x, s.begin() + x + k);
            }
            else {
                reverse(s.begin() + x, s.end());
            }
        }
        return s;
    }
};