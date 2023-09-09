class Solution {
public:
    bool canBeEqual(string s1, string s2) {
        for (int x = 0; x < 4; ++x) {
            if (s1[x % 4] != s2[x % 4]) {
                if (s1[x % 4] != s2[(x + 2) % 4]) {
                    return false;
                }
                if (s1[(x + 2) % 4] != s2[x % 4]) {
                    return false;
                }
            }
        }
        return true;
    }
};