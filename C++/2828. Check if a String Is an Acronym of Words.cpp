class Solution {
public:
    bool isAcronym(vector<string>& words, string s) {
        if (s.size() < words.size()) {
            return false;
        }
        int pos = 0;
        int run = 0;
        while (run < s.size()) {
            for (int y = 0; y < words.size(); ++y) {
                if (words[y][pos] != s[run++]) {
                    return false;
                }
            }
            ++pos;
        }
        return true;
    }
};