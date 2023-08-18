class Solution {
public:
    bool isAnagram(string s, string t) {
        int eng[26] = {0};
        for (auto x : s) {
            ++eng[x - 'a'];
        }

        for (auto x : t) {
            --eng[x - 'a'];
        }

        for (auto x : eng) {
            if (x != 0) {
                return false;
            }
        }
        return true;
    }
};