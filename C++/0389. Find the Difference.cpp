class Solution {
public:
    char findTheDifference(string s, string t) {
        int eng[26] = {0};
        for (int x = 0; x < s.size(); ++x) {
            ++eng[s[x] - 'a'];
        }

        for (int x = 0; x < t.size(); ++x) {
            --eng[t[x] - 'a'];
        }

        for (int x = 0; x < 26; ++x) {
            if (eng[x]) {
                return x + 'a';
            }
        }
        return ' ';
    }
};