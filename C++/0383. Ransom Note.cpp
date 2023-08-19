class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        int eng[26] = {0};
        for (auto x : ransomNote) {
            ++eng[x - 'a'];
        }
        for (auto x : magazine) {
            --eng[x - 'a'];
        }
        for (auto x : eng) {
            if (x > 0) {
                return false;
            }
        }
        return true;
    }
};